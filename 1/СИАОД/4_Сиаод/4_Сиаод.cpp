#include <iostream> 
#include <fstream> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include <locale>
#include <io.h>         
#include <set>
#include <fcntl.h>  
#include <sstream>
#include <ctime>
#include <Windows.h>
#include <map>

using namespace std;
// Структура для представления книги
// Функция для слияния двух файлов в один отсортированный файл по издателю
void mergeFilesByPublisher(const string& file1, const string& file2, const string& outputFile) {
    ifstream inFile1(file1);
    ifstream inFile2(file2);
    ofstream outFile(outputFile);

    string line1, line2;

    // Читаем первые строки из обоих файлов
    getline(inFile1, line1);
    getline(inFile2, line2);

    while (!inFile1.eof() && !inFile2.eof()) {
        // Сравниваем издателей в первых строках из файлов и записываем в выходной файл
        size_t pos1 = line1.find_last_of(',');
        size_t pos2 = line2.find_last_of(',');
        string publisher1 = line1.substr(pos1 + 1);
        string publisher2 = line2.substr(pos2 + 1);

        if (publisher1 < publisher2) {
            outFile << line1 << endl;
            getline(inFile1, line1);
        }
        else {
            outFile << line2 << endl;
            getline(inFile2, line2);
        }
    }

    // Записываем оставшиеся строки из первого файла
    while (!inFile1.eof()) {
        outFile << line1 << endl;
        getline(inFile1, line1);
    }

    // Записываем оставшиеся строки из второго файла
    while (!inFile2.eof()) {
        outFile << line2 << endl;
        getline(inFile2, line2);
    }

    // Закрываем все файлы
    inFile1.close();
    inFile2.close();
    outFile.close();
}

// Функция для разделения данных из одного файла на два файла 
void splitFile2(const string& inputFile, const string& outputFile1, const string& outputFile2) {
    ifstream input(inputFile);
    ofstream output1(outputFile1);
    ofstream output2(outputFile2);

    string line;
    bool writeToFirst = true;
    while (getline(input, line)) {
        // Извлекаем издателя и определяем, в какой файл записать текущую строку
        size_t pos = line.find_last_of(',');
        string publisher = line.substr(pos + 1);
        if (writeToFirst && publisher < "М") // Разделяем строки по половине алфавита
            output1 << line << endl;
        else
            output2 << line << endl;

        writeToFirst = !writeToFirst;
    }

    input.close();
    output1.close();
    output2.close();
}

// Функция для сортировки файла методом слияния по издателю
void mergeSortFileByPublisher(const string& inputFile, const string& outputFile, int n) {
    // Создаем временные файлы для разделения данных
    string tempFile1 = "temp1.txt";
    string tempFile2 = "temp2.txt";

    int portionSize = 1;

    // Фаза разделения
    bool dataLeft = true;
    while (dataLeft) {
        bool switchFiles = true;
        dataLeft = false;

        // Разделяем данные из входного файла на два временных файла
        splitFile2(inputFile, tempFile1, tempFile2);

        // Чтение данных из временных файлов и слияние обратно в выходной файл
        mergeFilesByPublisher(tempFile1, tempFile2, outputFile);

        // Обновление размера порции
        portionSize *= 2;
        if (portionSize >= n) {
            // Если размер порции достигнут, завершаем сортировку
            dataLeft = false;
            break;
        }
    }

    // Удаляем временные файлы
    remove(tempFile1.c_str());
    remove(tempFile2.c_str());
}









//
//
//// Функция для разделения строки на элементы по разделителю ','
//vector<string> split(const string& s, char delimiter) {
//    vector<string> tokens;
//    string token;
//    istringstream tokenStream(s);
//    while (getline(tokenStream, token, delimiter)) {
//        tokens.push_back(token);
//    }
//    return tokens;
//}
//
//// Функция для сравнения двух книг по издателю
//bool compareBooks(const Book& a, const Book& b) {
//    return a.publisher < b.publisher;
//}
//
//// Сортировка слиянием для вектора книг
//void mergeSort11(vector<Book>& books) {
//    if (books.size() <= 1) {
//        return;
//    }
//
//    auto middle = books.begin() + books.size() / 2;
//    vector<Book> left(books.begin(), middle);
//    vector<Book> right(middle, books.end());
//
//    mergeSort11(left);
//    mergeSort11(right);
//
//    merge(left.begin(), left.end(), right.begin(), right.end(), books.begin(), compareBooks);
//}
//
//
//
//
//
//




// Функция для разделения данных из одного файла на два файла 
void splitFile(const string& inputFile, const string& outputFile1, const string& outputFile2) {
    ifstream input(inputFile);
    ofstream output1(outputFile1);
    ofstream output2(outputFile2);

    int num;
    bool writeToFirst = true;
    while (input >> num) {
        if (writeToFirst)
            output1 << num << " ";
        else
            output2 << num << " ";

        writeToFirst = !writeToFirst;
    }

    input.close();
    output1.close();
    output2.close();
}

// Функция для слияния данных из двух файлов в один файл 
void mergeFiles(const string& outputFile, const string& inputFile1, const string& inputFile2) {
    ifstream input1(inputFile1);
    ifstream input2(inputFile2);
    ofstream output(outputFile);

    vector<int> numbers;

    int num1, num2;
    while (input1 >> num1) {
        numbers.push_back(num1);
    }
    while (input2 >> num2) {
        numbers.push_back(num2);
    }

    sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        output << num << " ";
    }

    input1.close();
    input2.close();
    output.close();
}


// Функция для сортировки файла методом слияния 
void mergeSort(const string& inputFile, const string& outputFile, int chunkSize) {
    // Разделение данных из исходного файла на два файла 
    string tempFile1 = "temp1.txt";
    string tempFile2 = "temp2.txt";
    splitFile(inputFile, tempFile1, tempFile2);

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

        mergeFiles(outputFile, tempFile1, tempFile2);
        chunkSize *= 2;
        splitFile(outputFile, tempFile1, tempFile2);
    }

    // Удаление временных файлов 
    remove(tempFile1.c_str());
    remove(tempFile2.c_str());
}
// Функция для разделения данных из одного файла на два файла
void splitFile1(const string& inputFile, const string& outputFile1, const string& outputFile2) {
    ifstream input(inputFile);
    ofstream output1(outputFile1);
    ofstream output2(outputFile2);

    string num;
    bool writeToFirst = true;
    while (input >> num) {
        if (writeToFirst)
            output1 << num << " ";
        else
            output2 << num << " ";

        writeToFirst = !writeToFirst;
    }

    input.close();
    output1.close();
    output2.close();
}

// Функция для слияния данных из двух файлов в один файл
void mergeFiles1(const string& outputFile, const string& inputFile1, const string& inputFile2) {
    ifstream input1(inputFile1);
    ifstream input2(inputFile2);
    ofstream output(outputFile);

    vector<string> numbers;

    string num1, num2;
    while (input1 >> num1) {
        numbers.push_back(num1);
    }
    while (input2 >> num2) {
        numbers.push_back(num2);
    }

    sort(numbers.begin(), numbers.end());

    for (string num : numbers) {
        output << num << " ";
    }

    input1.close();
    input2.close();
    output.close();
}

// Функция для сортировки файла методом слияния
void mergeSort1(const string& inputFile, const string& outputFile, int chunkSize) {
    // Разделение данных из исходного файла на два файла
    string tempFile1 = "temp1.txt";
    string tempFile2 = "temp2.txt";
    splitFile1(inputFile, tempFile1, tempFile2);

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

        mergeFiles1(outputFile, tempFile1, tempFile2);
        chunkSize *= 2;
        splitFile1(outputFile, tempFile1, tempFile2);
    }

    // Удаление временных файлов
    remove(tempFile1.c_str());
    remove(tempFile2.c_str());
}

int main()
{


    setlocale(LC_ALL, "rus");
    double a;
    while (true) {
        cout << "Введите номер задания: \n";
        cin >> a;
        if (a == 1.1) {
            time_t begin = clock();
            string inputFile = "input.txt";
            string outputFile = "output.txt";
            int chunkSize = 1; // Размер порции данных 

            // Вызов функции сортировки слиянием 
            mergeSort(inputFile, outputFile, chunkSize);

            // Вывод отсортированных данных из файла 
            ifstream output(outputFile);
            int num;
            while (output >> num) {
                cout << num << " ";
            }
            cout << endl;
            output.close();
            time_t end = clock();
            double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
            cout << "Затраченное время: " << TIME * 1000 << endl;
        }
        if (a == 1.2) {
            int N,l;
            cout << "Введите кол-во строк: ";
            cin >> N;
            string outputFile = "output.txt";
            int chunkSize = 1; // Размер порции данных 
            string** x = new string * [33];
            for (int i = 0; i < 33; i++)
            {
                x[i] = new string[7];
            }
            string book, text;
            text = "";
            string inputFile = "книги1.txt";
            ifstream books;
            char c;
            int i=0, j = 0;
            books.open(inputFile);
            if (books.is_open()){
                while (getline(books, book)) {
                    l = strlen(book.c_str());
                    for (int k = 0; k < l; k++) {
                        c = book[k];
                        if (c==','){
                            x[i][j] = text;
                            j++;
                            text = "";
                        }
                        else {
                                text += c;
                                if (text[0] == ' ') {text=""; }
                        }
                        if (k == l - 1) {
                            x[i][j] = text;
                            j = 0;
                            text = "";
                        }

                    }
                    j = 0;
                    i++;
                }
            }
            books.close();
            string* izd = new string[N];
            for (int i = 0; i < N; i++)
            {
                izd[i] = x[i][3];
            }
            string inputFile1 = "издатели.txt";
            ofstream input(inputFile1); 
            for (int i = 0; i < N; i++) {
                input << izd[i] << " ";
            }
            mergeSort1(inputFile1, outputFile, chunkSize);
            ifstream output(outputFile);
            book = "";
;           while (output >> book) {
                cout << book << " ";
            }
            for (int i = 0; i < 33; i++)
            {
                delete[] x[i];
            }
            delete[] x;
            delete[] izd;
                 
        }
        if (a == 1.3) {
            //int N;
            //cout << "Введите кол-во записей: ";
            //cin >> N;
            //ifstream inFile("книги1.txt");
            //ofstream outFile("output.txt");

            //vector<Book> books;
            //string line;
            //time_t begin = clock();

            //// Считываем данные из файла и сохраняем в векторе книг
            //while (getline(inFile, line)) {
            //    vector<string> tokens = split(line, ',');
            //    Book book;
            //    book.author = tokens[0];
            //    book.title = tokens[1];
            //    book.ISBN = stoi(tokens[2]);
            //    book.publisher = tokens[3];
            //    book.pages = stoi(tokens[4]);
            //    book.price = stoi(tokens[5]);
            //    books.push_back(book);
            //}

            //// Применяем сортировку слиянием к книгам по издателю
            //mergeSort11(books);

            //// Выводим отсортированные книги в файл
            //for (const auto& book : books) {
            //    outFile << book.author << ", " << book.title << ", " << book.ISBN << ", "
            //        << book.publisher << ", " << book.pages << ", " << book.price << endl;
            //}

            //inFile.close();
            //outFile.close();
            //time_t end = clock();
            //double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
            //cout << "Затраченное время: " << TIME * 1000 << endl;
        }
        if (a == 1.4) {
            string inputFile = "книги1.txt";
            string outputFile = "output.txt";

            time_t begin = clock();

            // Применяем сортировку слиянием к содержимому файла по издателю
            mergeSortFileByPublisher(inputFile, outputFile, 32);

            time_t end = clock();
            double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
            cout << "Затраченное время: " << TIME * 1000 << " мс" << endl;
    
        }
        else { cout << "Нет такого задания: \n"; cin >> a; }

    }
}