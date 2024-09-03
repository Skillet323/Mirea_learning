#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Book {
    string author;
    string title;
    int ISBN;
    string publisher;
    int pages;
    int price;
};

// Функция для разделения строки на элементы по разделителю ','
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Функция для сравнения двух книг по издателю
bool compareBooks(const Book& a, const Book& b) {
    return a.publisher < b.publisher;
}

// Сортировка слиянием для вектора книг
void mergeSort1(vector<Book>& books) {
    if (books.size() <= 1) {
        return;
    }

    auto middle = books.begin() + books.size() / 2;
    vector<Book> left(books.begin(), middle);
    vector<Book> right(middle, books.end());

    mergeSort1(left);
    mergeSort1(right);

    merge(left.begin(), left.end(), right.begin(), right.end(), books.begin(), compareBooks);
}

int main() {
    ifstream inFile("книги1.txt");
    ofstream outFile("output.txt");

    vector<Book> books;
    string line;

    // Считываем данные из файла и сохраняем в векторе книг
    while (getline(inFile, line)) {
        vector<string> tokens = split(line, ',');
        Book book;
        book.author = tokens[0];
        book.title = tokens[1];
        book.ISBN = stoi(tokens[2]);
        book.publisher = tokens[3];
        book.pages = stoi(tokens[4]);
        book.price = stoi(tokens[5]);
        books.push_back(book);
    }

    // Применяем сортировку слиянием к книгам по издателю
    mergeSort1(books);

    // Выводим отсортированные книги в файл
    for (const auto& book : books) {
        outFile << book.author << ", " << book.title << ", " << book.ISBN << ", "
            << book.publisher << ", " << book.pages << ", " << book.price << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
