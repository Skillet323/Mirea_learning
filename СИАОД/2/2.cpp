#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
void insertion(int* x, int n)
{
    int key,j;
    for (int i = 1; i < n; i++) {
        key = x[i];
        j = i - 1;
        while (j >= 0 && x[j] > key) {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = key;
    }
}
void insertion1(int* x, int n)
{
    int key, j;
    long int oper=0;
    for (int i = 1; i < n; i++) {
        oper+=3;
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
struct comp
{
    template<class T>
    bool operator()(T const& a, T const& b) const { return a > b; }
};
void bubble(int* x, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (x[j] > x[j + 1])
                swap(x[j], x[j + 1]);
}
void bubble1(int* x, int n)
{
    int oper = 0;
    for (int i = 0; i < n - 1; i++) {
        oper++;
        for (int j = 0; j < n - i - 1; j++) {
            oper ++;
            if (x[j] > x[j + 1]) {
                swap(x[j], x[j + 1]);
                oper += 2;
            }
        }
    }
    cout << "Количество сравнений и перестановок: " << oper << endl;
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
int main()
{
    setlocale(LC_ALL, "rus");
    double a; 
    while (true) {
        cout << "Введите номер задания: \n";
        cin >> a;
        if (a == 1.1) {
            int n = 10;
            cout << "n=10 \n";
            int x[10] = {2354,432,3241,532,1235,674,253,324,134,7543};
            cout << "Первоначальный массив: \n";
            Output(x, n);
            bubble(x, n);
            cout << "Отсортированный массив: \n";
            Output(x, n);
            delete[] x;
        }
        if (a == 1.2) {
            int n;
            cout << "Введите количество элементов n: \n";
            cin >> n;
            int*x = RandChisla(n);
            cout << "Первоначальный массив: \n";
            Output(x, n);
            bubble(x, n);
            cout << "Отсортированный массив: \n";
            Output(x, n);
            delete[] x;
        }
        if (a == 1.3) {
            int n;
            cout << "Введите количество элементов n: \n";
            cin >> n;
            int* x = RandChisla(n);
            cout << "Первоначальный массив: \n";
            Output(x, n);
            time_t begin = clock();
            bubble1(x, n);
            time_t end = clock();
            double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
            cout << "Отсортированный массив: \n";
            Output(x, n);
            cout << "Затраченное время: " << TIME * 1000 << endl;
            delete[] x;
        }
        if (a == 2.1) {
            int n[5] = { 100,1000,10000,100000,1000000 };
            for (int i = 0; i < 5; i++) {
                cout << "n = " << n[i] << endl;
                int* x = RandChisla(n[i]);
                sort(x,x+n[i]);
                time_t begin = clock();
                bubble1(x, n[i]);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                delete[] x;
            }
            for (int i = 0; i < 5; i++) {
                cout << "n = " << n[i] << endl;
                int* x = RandChisla(n[i]);
                sort(x, x + n[i], comp());
                time_t begin = clock();
                bubble1(x, n[i]);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                delete[] x;
            }
        }
        if (a == 2.2) {
            int n = 10;
            cout << "n = " << n << endl;
            int* x = RandChisla(n);
            sort(x, x + n);
            cout << "Отсортированный изначальный массив: \n";
            Output(x, n);
            time_t begin = clock();
            bubble1(x, n);
            time_t end = clock();
            double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
            cout << "Отсортированный конечный массив: \n";
            Output(x, n);
            cout << "Затраченное время: " << TIME * 1000 << endl;
            cout << "n = " << n << endl;
            int* y = RandChisla(n);
            sort(y, y + n, comp());
            cout << "Отсортированный изначальный массив: \n";
            Output(y, n);
            time_t begin1 = clock();
            bubble1(y, n);
            time_t end1 = clock();
            cout << "Отсортированный конечный массив: \n";
            Output(y, n);
            double TIME1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
            cout << "Затраченное время: " << TIME1 * 1000 << endl;
            delete[] x;
            delete[] y;
        }
        if (a == 3.1) {
            int n = 10;
            cout << "n=10 \n";
            int x[10] = { 2354,432,3241,532,1235,674,253,324,134,7543 };
            cout << "Первоначальный массив: \n";
            Output(x, n);
            insertion(x, n); 
            cout << "Отсортированный массив: \n";
            Output(x, n);
            delete[] x;
        }
        if (a == 3.2) {
            int n[5] = { 100,1000,10000,100000,1000000 };
            for (int i = 0; i < 5; i++) {
                cout << "n = " << n[i] << endl;
                int* x = RandChisla(n[i]);
                time_t begin = clock();
                insertion1(x, n[i]);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                delete[] x;
            }
            for (int i = 0; i < 5; i++) {
                cout << "n = " << n[i] << endl;
                int* x = RandChisla(n[i]);
                sort(x, x + n[i]);
                time_t begin = clock();
                insertion1(x, n[i]);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                delete[] x;
            }
            for (int i = 0; i < 5; i++) {
                cout << "n = " << n[i] << endl;
                int* x = RandChisla(n[i]);
                sort(x, x + n[i], comp());
                time_t begin = clock();
                insertion1(x, n[i]);
                time_t end = clock();
                double TIME = (double)(end - begin) / CLOCKS_PER_SEC;
                cout << "Затраченное время: " << TIME * 1000 << endl;
                delete[] x;
            }
        }
        else {
            cout << "Введите номер задания: \n";
            cin >> a;
        }
    }
}