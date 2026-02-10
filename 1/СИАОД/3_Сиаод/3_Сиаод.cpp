#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
void insertion1(int* x, int n)
{
    int key, j;
    long int oper = 0;
    for (int i = 1; i < n; i++) {
        oper += 3;
        key = x[i];
        j = i - 1;
        while (j >= 0 && x[j] > key) {
            x[j + 1] = x[j];
            j--;
            oper += 2;
        }
        x[j + 1] = key;
        oper++;
    }
    cout << "Количество сравнений и перемещений: " << oper << endl;
}
void Output(int* y, int n) {
    for (int i = 0; i < n; i++) {
        cout << y[i] << " ";
    }
    cout << endl;
}
int* RandChisla(int n) {
    srand(time(NULL));
    int* x = new int[n];
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 100;
    }
    return(x);
}
void shell_sort(int* x, int n) {
    int k = log(n - 1) / log(2);
    int* d = new int[k];
    d[0] = 1;
    for (int i = 1; i < k; i++) {
        d[i] = (d[i - 1] * 2) + 1;//Определение d по второму способу Кнута
    }
    for (int c = k - 1; c >= 0; c--) {
        for (int i = d[c]; i < n; i++) { //Цикл по счетчику элемента
            for (int j = i - d[c]; j >= 0 && x[j] > x[j + d[c]]; j -= d[c]) { //Цикл по счетчику элемента с шагом
                swap(x[j], x[j + d[c]]);//Смена мест элементов
            }
        }
    }
    delete[] d;
}
void shell_sort1(int* x, int n) {
    long long oper = 0;
    int k = log(n - 1) / log(2);
    int* d = new int[k];
    d[0] = 1;
    for (int i = 1; i < k; i++) {
        oper+=2;
        d[i] = (d[i - 1] * 2) + 1;//Определение d по второму способу Кнута
    }
    for (int c = k-1; c >=0; c--) {
        oper++;
        for (int i = d[c]; i < n; i++) { //Цикл по счетчику элемента
            oper++;
            for (int j = i - d[c]; j >= 0 && x[j] > x[j + d[c]]; j -= d[c]) { //Цикл по счетчику элемента с шагом
                oper += 2;
                swap(x[j], x[j + d[c]]);//Смена мест элементов
            }
        }
    }
    delete[] d;
    cout << "Количество операций: " << oper << endl;
}
void MergeSort(int *a, size_t l)
{
    size_t BlockSizeIterator;
    size_t BlockIterator;
    size_t LeftBlockIterator;
    size_t RightBlockIterator;
    size_t MergeIterator;
    size_t LeftBorder;
    size_t MidBorder;
    size_t RightBorder;
    for (BlockSizeIterator = 1; BlockSizeIterator < l; BlockSizeIterator *= 2)
    {
        for (BlockIterator = 0; BlockIterator < l - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
        {
            //Производим слияние с сортировкой пары блоков начинающуюся с элемента BlockIterator
            //левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
            LeftBlockIterator = 0;
            RightBlockIterator = 0;
            LeftBorder = BlockIterator;
            MidBorder = BlockIterator + BlockSizeIterator;
            RightBorder = BlockIterator + 2 * BlockSizeIterator;
            RightBorder = (RightBorder < l) ? RightBorder : l;
            int* SortedBlock = new int[RightBorder - LeftBorder]; //Разбиваем массив на два разных
            //Пока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
            while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
            {
                if (a[LeftBorder + LeftBlockIterator] < a[MidBorder + RightBlockIterator])
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                    LeftBlockIterator += 1;
                }
                else
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                    RightBlockIterator += 1;
                }
            }
            //После этого заносим оставшиеся элементы из левого или правого блока
            while (LeftBorder + LeftBlockIterator < MidBorder)
            {
                SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                LeftBlockIterator += 1;
            }
            while (MidBorder + RightBlockIterator < RightBorder)
            {
                SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                RightBlockIterator += 1;
            }

            for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
            {
                a[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
            }
            delete[] SortedBlock;
        }
    }
}
struct comp
{
    template<class T>
    bool operator()(T const& a, T const& b) const { return a > b; }
};
void MergeSort1(int* a, size_t l)
{
    int oper = 0;
    size_t BlockSizeIterator;
    size_t BlockIterator;
    size_t LeftBlockIterator;
    size_t RightBlockIterator;
    size_t MergeIterator;
    size_t LeftBorder;
    size_t MidBorder;
    size_t RightBorder;
    for (BlockSizeIterator = 1; BlockSizeIterator < l; BlockSizeIterator *= 2)
    {
        oper++;
        for (BlockIterator = 0; BlockIterator < l - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
        {
            //Производим слияние с сортировкой пары блоков начинающуюся с элемента BlockIterator
            //левый размером BlockSizeIterator, правый размером BlockSizeIterator или меньше
            LeftBlockIterator = 0;
            RightBlockIterator = 0;
            LeftBorder = BlockIterator;
            MidBorder = BlockIterator + BlockSizeIterator;
            RightBorder = BlockIterator + 2 * BlockSizeIterator;
            RightBorder = (RightBorder < l) ? RightBorder : l;
            int* SortedBlock = new int[RightBorder - LeftBorder]; //Разбиваем массив на два разных
            //Пока в обоих массивах есть элементы выбираем меньший из них и заносим в отсортированный блок
            oper += 5;
            while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
            {
                oper += 2;
                if (a[LeftBorder + LeftBlockIterator] < a[MidBorder + RightBlockIterator])
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                    LeftBlockIterator += 1;
                    oper += 2;
                }
                else
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                    RightBlockIterator += 1;
                    oper++;
                }
            }
            //После этого заносим оставшиеся элементы из левого или правого блока
            while (LeftBorder + LeftBlockIterator < MidBorder)
            {
                oper += 2;
                SortedBlock[LeftBlockIterator + RightBlockIterator] = a[LeftBorder + LeftBlockIterator];
                LeftBlockIterator += 1;
            }
            while (MidBorder + RightBlockIterator < RightBorder)
            {
                oper += 2;
                SortedBlock[LeftBlockIterator + RightBlockIterator] = a[MidBorder + RightBlockIterator];
                RightBlockIterator += 1;
            }

            for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
            {
                oper += 2;
                a[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
            }
            delete[] SortedBlock;
        }
    }
    cout << "Количество операций: " << oper << endl;
}
int main()
{
    setlocale(LC_ALL, "rus");
    double a;
    while (true) {
        cout << "Введите номер задания: \n";
        cin >> a;
        if (a == 1.1) {
            int n = 100;
            for (int i = 3; i < 8;i++) {
                int* x = RandChisla(n);
                time_t begin = clock();
                shell_sort1(x, n);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                n = pow(10,i);
                delete[] x;
            }
        }
        if (a == 1.2) {
            int n = 100;
            for (int i = 3; i < 8; i++) {
                int* x = RandChisla(n);
                time_t begin = clock();
                MergeSort1(x, n);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                n = pow(10, i);
                delete[] x;
            }
        }
        if (a == 1.3) {
            int n = 100;
            for (int i = 3; i < 8; i++) {
                cout << "n= " << n << endl;
                int* x = RandChisla(n);
                sort(x, x + n);
                time_t begin = clock();
                shell_sort1(x, n);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                n = pow(10, i);
                delete[] x;
            }
            n = 100;
            for (int i = 3; i < 8; i++) {
                cout << "n= " << n << endl;
                int* x = RandChisla(n);
                sort(x, x + n,comp());
                time_t begin = clock();
                shell_sort1(x, n);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                n = pow(10, i);
                delete[] x;
            }
            n = 100;
            for (int i = 3; i < 8; i++) {
                cout << "n= " << n << endl;
                int* x = RandChisla(n);
                sort(x, x + n);
                time_t begin = clock();
                MergeSort1(x, n);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                n = pow(10, i);
                delete[] x;
            }
            n = 100;
            for (int i = 3; i < 8; i++) {
                cout << "n= " << n << endl;
                int* x = RandChisla(n);
                sort(x, x + n, comp());
                time_t begin = clock();
                MergeSort1(x, n);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                n = pow(10, i);
                delete[] x;
            }
        }
        else {
            cout << "Введите номер задания: \n";
            cin >> a;
        }
    }
}
