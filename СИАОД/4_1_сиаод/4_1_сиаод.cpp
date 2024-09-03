#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 
#include <ctime>
#include <string> 
#include <sstream> 


using namespace std;

// Функция для разделения данных из одного файла на два файла 
void splitFile(const string& inputFile, const string& outputFile1, const string& outputFile2, int N) {
    ifstream input(inputFile);
    ofstream output1(outputFile1);
    ofstream output2(outputFile2);

    string line;
    int lineNum = 0;
    for (int i=0; i<N;i++){
        getline(input, line);
        if (lineNum % 2 == 0)
            output1 << line << endl;
        else
            output2 << line << endl;
        lineNum++;
    }

    input.close();
    output1.close();
    output2.close();
}

// Функция для сравнения строк по ключевому индексу 
bool compare(const vector<string>& tokens1, const vector<string>& tokens2, int keyIndex) {
    if (keyIndex >= tokens1.size() || keyIndex >= tokens2.size()) {
        cerr << "Key index is out of range." << endl;
        exit(1);
    }
    return tokens1[keyIndex] != tokens2[keyIndex];
}

// Функция для слияния данных из двух файлов в один файл 
void mergeFiles(const string& outputFile, const string& inputFile1, const string& inputFile2, int keyIndex) {
    ifstream input1(inputFile1);
    ifstream input2(inputFile2);
    ofstream output(outputFile);

    string line1, line2;
    getline(input1, line1);
    getline(input2, line2);
    while (!input1.eof() && !input2.eof()) {
        vector<string> tokens1, tokens2;
        stringstream ss1(line1), ss2(line2);
        string token;
        while (getline(ss1, token, ','))
            tokens1.push_back(token);
        while (getline(ss2, token, ','))
            tokens2.push_back(token);

        if (compare(tokens1, tokens2, keyIndex)) {
            output << line1 << endl;
            getline(input1, line1);
        }
        else {
            output << line2 << endl;
            getline(input2, line2);
        }


    }
    // Write remaining lines 
    while (!input1.eof()) {
        output << line1 << endl;
        getline(input1, line1);
    }
    while (!input2.eof()) {
        output << line2 << endl;
        getline(input2, line2);
    }

    input1.close();
    input2.close();
    output.close();
}

// Функция для сортировки файла методом слияния 
void mergeSort(const string& inputFile, const string& outputFile, int chunkSize, int keyIndex, int N) {
    // Разделение данных из исходного файла на два файла 
    string tempFile1 = "temp1.txt";
    string tempFile2 = "temp2.txt";
    splitFile(inputFile, tempFile1, tempFile2, N);

    // Последовательное слияние данных из двух файлов обратно в исходный 
    while (chunkSize < 100) {
        // Проверяем, не пуст ли tempFile1 
        ifstream check1(tempFile1);
        if (!check1.peek()) {
            check1.close();
            break; // tempFile1 пуст, выходим из цикла 
        }
        check1.close();

        // Проверяем, не пуст ли tempFile2 
        ifstream check2(tempFile2);
        if (!check2.peek()) {
            check2.close();
            break; // tempFile2 пуст, выходим из цикла 
        }
        check2.close();

        mergeFiles(outputFile, tempFile1, tempFile2, keyIndex);
        chunkSize *= 2;
        splitFile(outputFile, tempFile1, tempFile2,N);
    }
    // Удаление временных файлов 
    remove(tempFile1.c_str());
    remove(tempFile2.c_str());
}

int main() {
    while (true) {
        setlocale(LC_ALL, "rus");
        int N;
        cout << "Кол-во записей: ";
        cin >> N;
        string inputFile = "input.txt";
        string outputFile = "output.txt";
        int chunkSize = 10;
        int keyIndex = 3;
        time_t begin = clock();
        // Сортировка файла 
        mergeSort(inputFile, outputFile, chunkSize, keyIndex, N);
        time_t end = clock();
        double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
        cout << "Затраченное время: " << TIME * 1000 << " мс" << endl;
        cout << "Файл " << outputFile << " успешно отсортирован." << endl;
    }
}