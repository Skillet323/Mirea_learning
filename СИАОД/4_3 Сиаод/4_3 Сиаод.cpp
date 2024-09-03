#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для слияния двух серий
void mergeSeries(const string& inFile1, const string& inFile2, const string& outFile) {
    ifstream file1(inFile1), file2(inFile2);
    ofstream out(outFile);

    int num1, num2;
    file1 >> num1;
    file2 >> num2;

    while (!file1.eof() && !file2.eof()) {
        if (num1 < num2) {
            out << num1 << " ";
            file1 >> num1;
        }
        else {
            out << num2 << " ";
            file2 >> num2;
        }
    }

    while (!file1.eof()) {
        out << num1 << " ";
        file1 >> num1;
    }

    while (!file2.eof()) {
        out << num2 << " ";
        file2 >> num2;
    }

    file1.close();
    file2.close();
    out.close();
}

// Функция для разделения файла на серии и сортировки каждой серии
void splitAndSort(const string& inFile, const string& outFile1, const string& outFile2, int bufferSize) {
    ifstream in(inFile);
    ofstream out1(outFile1), out2(outFile2);

    vector<int> buffer(bufferSize);
    int num;

    while (!in.eof()) {
        int i = 0;
        while (i < bufferSize && !in.eof()) {
            in >> num;
            buffer[i++] = num;
        }
        sort(buffer.begin(), buffer.begin() + i);

        for (int j = 0; j < i; ++j) {
            if (j % 2 == 0) out1 << buffer[j] << " ";
            else out2 << buffer[j] << " ";
        }
    }

    in.close();
    out1.close();
    out2.close();
}

// Основная функция сортировки естественного слияния
void naturalMergeSort(const string& inFile, const string& outFile, int bufferSize) {
    splitAndSort(inFile, "temp1.txt", "temp2.txt", bufferSize);

    bool flag = true;
    while (flag) {
        mergeSeries("temp1.txt", "temp2.txt", outFile);
        mergeSeries("temp2.txt", "temp1.txt", outFile);
        flag = false;
        ifstream in(outFile);
        int num, prev;
        in >> prev;
        while (in >> num) {
            if (num < prev) {
                flag = true;
                break;
            }
            prev = num;
        }
        in.close();
    }
}

int main() {
    // Параметры файла и размер буфера
    const string inputFile = "input.txt";
    const string sortedFile = "sorted.txt";
    const int bufferSize = 1000; // Размер буфера

    // Сортировка файла методом естественного слияния
    naturalMergeSort(inputFile, sortedFile, bufferSize);

    // Вывод отсортированных данных
    ifstream sorted(sortedFile);
    int num;
    while (sorted >> num) {
        cout << num << " ";
    }
    sorted.close();

    return 0;
}
