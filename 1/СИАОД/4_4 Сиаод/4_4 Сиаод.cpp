#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <locale>
#include <filesystem>
#include <ctime>

using namespace std;

struct Book {
    string author;
    string title;
    int tirazh; // Новое поле
    string publisher;
    int pages;
    double price;
};

bool compareBooksByPublisher(const Book& book1, const Book& book2) {
    return book1.publisher < book2.publisher;
}

Book parseBook(const string& line) {
    Book book;
    stringstream ss(line);

    getline(ss, book.author, ',');
    ss >> ws; // Пропускаем пробельные символы после запятой

    getline(ss, book.title, ',');
    ss >> ws; // Пропускаем пробельные символы после запятой

    ss >> book.tirazh; // Считываем тираж
    ss.ignore(1, ','); // Пропускаем запятую после тиража

    getline(ss, book.publisher, ',');
    ss >> ws; // Пропускаем пробельные символы после запятой

    ss >> book.pages;
    ss.ignore(1, ','); // Пропускаем запятую после страниц

    ss >> ws; // Пропускаем пробельные символы после числа
    ss >> book.price;

    return book;
}

void writeBook(ofstream& out, const Book& book) {
    out << book.author << ", " << book.title << ", " << book.tirazh << ", " << book.publisher << ", " << book.pages << ", " << book.price << endl;

}
void mergeSeries(const string& inFile1, const string& inFile2, const string& outFile, bool (*compare)(const Book&, const Book&)) {
    ifstream file1(inFile1), file2(inFile2);
    ofstream out(outFile);

    Book book1, book2;
    string line1, line2;

    // Считываем первую запись из каждого файла
    getline(file1, line1);
    getline(file2, line2);
    book1 = parseBook(line1);
    book2 = parseBook(line2);

    // Пока не достигнем конца обоих файлов
    while (!file1.eof() && !file2.eof()) {
        if (compare(book1, book2)) {
            writeBook(out, book1);
            getline(file1, line1);
            book1 = parseBook(line1);
        }
        else {
            writeBook(out, book2);
            getline(file2, line2);
            book2 = parseBook(line2);
        }
    }

    // Дописываем оставшиеся записи из первого файла
    while (!file1.eof()) {
        writeBook(out, book1);
        getline(file1, line1);
        book1 = parseBook(line1);
    }

    // Дописываем оставшиеся записи из второго файла
    while (!file2.eof()) {
        writeBook(out, book2);
        getline(file2, line2);
        book2 = parseBook(line2);
    }
    file1.close();
    file2.close();
    remove("temp1.txt");
    remove("temp2.txt");
    out.close();

}

void splitAndSort(const string& inFile, const string& outFile1, const string& outFile2, int seriesSize, bool (*compare)(const Book&, const Book&), int N) {
    ifstream in(inFile);
    ofstream out1(outFile1), out2(outFile2);

    vector<Book> buffer;
    string line;
    int j = 0;
    int k = 0;
    while (k<N) {
        getline(in, line);
        if (buffer.size() < seriesSize && !in.eof()) {
            buffer.push_back(parseBook(line));
            sort(buffer.begin(), buffer.end(), compare);
        }
        k++;
    }
    for (size_t i = 0; i < buffer.size(); ++i) {
        if (j % 2 == 0) {
            writeBook(out1, buffer[i]);
        }
        else {
            writeBook(out2, buffer[i]);
        }
        j++;
    }

    buffer.clear();
    in.close();
    out1.close();
    out2.close();
}


void naturalMergeSort(const string& inFile, const string& outFile, int bufferSize, bool (*compare)(const Book&, const Book&),int N) {
    splitAndSort(inFile, "temp1.txt", "temp2.txt", bufferSize, compare, N);
    string temp1 = "temp1.txt", temp2 = "temp2.txt";
    mergeSeries(temp1, temp2, outFile, compare);
}

int main() {
    while (true) {
        setlocale(LC_ALL, "rus");
        int N;
        cout << "Количество записей: " << endl;
        cin >> N;

        const string inputFile = "input.txt";
        const string sortedFile = "sorted.txt";
        const int bufferSize = 10000;
        time_t begin = clock();
        naturalMergeSort(inputFile, sortedFile, bufferSize, compareBooksByPublisher, N);
        time_t end = clock();
        double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
        cout << "Затраченное время: " << TIME * 1000 << " мс" << endl;
        cout << "Отработал" << endl;
        if (N == 0) { return 0; }
    }
}
