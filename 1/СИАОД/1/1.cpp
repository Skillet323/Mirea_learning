#include <iostream>
#include "Windows.h"
#include <conio.h>
#include <time.h>
#include <ctime>
using namespace std;
void Obhod(int** x,int m,int n) {
	int i = 0, j = 0,oper=4; // 2
	while (i < m && j < n) { // min(m, n)
		// Обход верхней строки
		for (int col = j; col < n; col++) { // min(m, n) * (n+1) + 1
			cout << x[i][col] << " "; //n * min(m, n)
			oper += 2;
		}
		i++;// min(m, n)
		oper++;
		// Обход последнего столбца
		for (int row = i; row < m; row++) { // (m+1) * min(m, n) + 1
			cout << x[row][n - 1] << " "; // m * min(m, n)
			oper += 2;
		}
		n--; // min(m, n)
		oper++;
		// Обход нижней строки
		if (i < m) { // min(m, n)
			for (int col = n - 1; col >= j; col--) { //(n+1)* min(m, n) + 1
				cout << x[m - 1][col] << " "; // n * min(m, n)
				oper += 2;
			}
			m--;//min(m, n)
			oper++;
		}
		oper++;
		// Обход первого столбца
		if (j < n) { // min(m, n)
			for (int row = m - 1; row >= i; row--) { //(m+1) * min(m, n) + 1
				cout << x[row][j] << " "; // m * min(m, n)
				oper += 2;
			}
			j++; // min(m, n)
			oper++;
		}
		oper++;
		oper++;
		// Пусть k=min(m, n)
		// Тогда:
		//Функция роста T(n) = 2k*(n+1) + 2k*(m+1) + 2k*m  + 2k*n  + 7k + 6
		// T(n) = 4kn + 4km + 11k + 6 
	}
	cout << endl << "Количество сравнений и перемещений данных: " << oper << endl;
}
void Obhod0(int** x, int m, int n) {
	int i = 0, j = 0; // 2
	while (i < m && j < n) { // min(m, n)
		// Обход верхней строки
		for (int col = j; col < n; col++) { // min(m, n) * (n+1) + 1
			cout << x[i][col] << " "; //n * min(m, n)
		}
		i++;// min(m, n)
		// Обход последнего столбца
		for (int row = i; row < m; row++) { // (m+1) * min(m, n) + 1
			cout << x[row][n - 1] << " "; // m * min(m, n)
		}
		n--; // min(m, n)
		// Обход нижней строки
		if (i < m) { // min(m, n)
			for (int col = n - 1; col >= j; col--) { //(n+1)* min(m, n) + 1
				cout << x[m - 1][col] << " "; // n * min(m, n)
			}
			m--;//min(m, n)
		}
		// Обход первого столбца
		if (j < n) { // min(m, n)
			for (int row = m - 1; row >= i; row--) { //(m+1) * min(m, n) + 1
				cout << x[row][j] << " "; // m * min(m, n)
			}
			j++; // min(m, n)
		}
		// Пусть k=min(m, n)
		// Тогда:
		//Функция роста T(n) = 2k*(n+1) + 2k*(m+1) + 2k*m  + 2k*n  + 7k + 6
		// T(n) = 4kn + 4km + 11k + 6
	}
}
int* RandChisla(int n){
	srand(time(NULL));
	int* x = new int[n];
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 100; //генерация случайных значений для элементов массива
	}
	return(x);
}
void Output(int*y,int n) {
	cout << "\nИзмененный массив x : ";
	for (int i = 0; i <n; i++) {
		cout << y[i] << " ";
	}
	cout << endl;
}
void delFirstMetod(int* x, int n, int key) {
	int i = 0, oper=0; // 1
	while (i < n) { // n
		if (x[i] == key) { // n
			for (int j = i; j < n - 1; j++) { // n + (n-1)^2
				x[j] = x[j+1]; // (n-1)^2
				oper+=2;
			}
			n--; // n
			oper++;
		}
		else {
			i++; // n
			oper++ ; 
		}
		oper++;
	}
	for (int i = 0; i < n; i++) { // n+1
		cout << x[i] << " "; // n
		oper++;
	}
	cout << "\n" << "Конечное количество элементов массива: " << n << endl;//1
	cout << "Количество сравнений и перемещений равно: " << oper << endl;
	// Функция роста T(n) = 2n^2 + 3n + 5
}
void delOtherMetod(int* x, int n, int key) {
	int j = 0, oper=0; // 1
	for (int i = 0; i <n; i++) { // n + 1
		x[j] = x[i]; // n
		oper+=2;
		if (x[i] != key) { // n
			j++; // n
			oper++;
		}
	}
	n = j; // 1
	for (int i = 0; i < n; i++) { // n + 1
		cout << x[i] << " "; // n
		oper++;
	}
	cout << "\n" << "Конечное количество элементов массива: " << n << endl; //1
	cout << "Количество сравнений и перемещений равно: " << oper << endl; 
	// Функция роста T(n) = 6n + 5
}
void delFirstMetod1(int* x, int n, int key) {
	int i = 0, oper = 0; // 1
	while (i < n) { // n
		if (x[i] == key) { // n
			for (int j = i; j < n - 1; j++) { // n + (n-1)^2
				x[j] = x[j + 1]; // (n-1)^2
				oper+=2;
			}
			n--; // n
			oper++;
		}
		else {
			i++; // n
			oper++;
		}
		oper++;
	}
	cout << "n = " << n << endl; // 1
	cout << "Количество сравнений и перемещений равно: " << oper << endl;
	// Функция роста T(n) = 2n^2 + n + 4
	Output(x,n);
}
void delOtherMetod1(int* x, int n, int key) {
	int j = 0, oper = 0; // 1
	for (int i = 0; i < n; i++) { // n + 1
		x[j] = x[i]; // n
		oper += 2;
		if (x[i] != key) { // n
			j++; // n
			oper++;
		}
	}
	n = j; // 1
	cout << "n = " << n << endl;//1
	cout << "Количество сравнений и перемещений равно: " << oper << endl;
	// Функция роста T(n) = 4n + 4
	Output(x, n);
}
int main()
{
	int n, key;
	double a;
	setlocale(LC_ALL,"Rus");
	while (true) {
		cout << "Введите номер задания: \n";
		cin >> a;
		if (a == 1.1) {
			cout << "Введите n: \n";
			cin >> n;
			cout << "Введите key: \n";
			cin >> key;
			srand(time(NULL));
			int temp;
			int* x = new int[n];
			int* y = new int[n];
			for (int i = 0; i < n; i++) {
				temp = rand() % 100; //генерация случайных значений для элементов массива
				x[i] = temp;
				y[i] = temp;
			}
			cout << "Отсортированный массив x: ";
			delFirstMetod(x, n, key);
			delete[] x; // Освобождаем память после использования
			cout << "Отсортированный массив x: ";
			delOtherMetod(y, n, key);
			delete[] y; // Освобождаем память после использования
		}
		if (a == 1.2) {
			cout << "Введите n: \n";
			cin >> n;
			cout << "Введите key: \n";
			cin >> key;
			double t;
			int* x = RandChisla(n); // Создание массива x
			int* x_copy1 = new int[n]; // Создаем копию массива x
			int* x_copy2 = new int[n]; // Создаем еще одну копию массива x
			// Копируем значения из массива x в копии
			cout << "Первоначальный массив x: ";
			for (int i = 0; i < n; ++i) {
				x_copy1[i] = x[i];
				x_copy2[i] = x[i];
				cout << x[i] << " ";
			}
			cout << endl;
			// Вызываем функции для каждой копии
			time_t begin = clock();
			delFirstMetod1(x_copy1,n,key);
			time_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Затраченное время: " << time_spent << endl;
			begin = clock();
			delOtherMetod1(x_copy2, n, key);
			end = clock();
			time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Затраченное время: " << time_spent << endl;
			// Освобождаем память для каждой копии
			delete[] x;
			delete[] x_copy1;
			delete[] x_copy2;
		}
		if (a == 1.3) {
			int k[10] = { 3,3,3,3,3,3,3,3,3,3 };
			cout << "Первоначальный массив x: ";
			for (int i = 0; i < 10; ++i) {
				cout << k[i] << " ";
			}
			cout << endl;
			time_t begin = clock();
			delFirstMetod1(k, 10, 3);
			time_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Затраченное время: " << time_spent << endl;
			for (int i = 0; i < 10; i++) {
				k[i] = 3;
			}
			begin = clock();
			delOtherMetod1(k, 10, 3);
			end = clock();
			time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Затраченное время: " << time_spent << endl;
		}
		if (a == 1.4) {
			int k[10] = { 3,4,5,6,7,8,9,10,11,12};
			cout << "Первоначальный массив x: ";
			for (int i = 0; i < 10; ++i) {
				cout << k[i] << " ";
			}
			cout << endl;
			time_t begin = clock();
			delFirstMetod1(k, 10, 2);
			time_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Затраченное время: " << time_spent << endl;
			for (int i = 0; i < 10; i++) {
				k[i] = i + 3;
			}
			begin = clock();
			delOtherMetod1(k, 10, 2);
			end = clock();
			time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Затраченное время: " << time_spent << endl;

		}
		if (a == 2.1) {
			int m, n;
			cout << "Введите кол-во строк: \n";
			cin >> m;
			cout << "Введите кол-во столбцов: \n";
			cin >> n;
			int** x = new int* [m]; //создание матрицы
			for (int i = 0; i < m; i++) {
				x[i] = new int[n];
			}
			srand(time(NULL));
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					x[i][j] = rand() % 100; //генерация случайных значений для элементов матрицы
					cout << x[i][j] << " ";
				}
				cout << endl;
			}
			time_t begin = clock();
			Obhod(x,m,n);
			time_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Затраченное время: " << time_spent << endl;
			// Освобождаем память
			for (int i = 0; i < m; ++i) {
				delete[] x[i];
			}
			delete[] x;
		}
		if (a == 2.2) {
			int m = 3, n = 3,k=0;
			int** x = new int* [m]; //создание матрицы
			for (int i = 0; i < m; i++) {
				x[i] = new int[n];
			}
			cout << "Введите через enter 9 значений элементов матрицы x\n";
			// Введем значения от 1 до 9 включительно, получим матрицу:
			// 1 2 3
			// 4 5 6
			// 7 8 9
			// Ожидаемый результат работы алгоритма:
			// 1 2 3 6 9 8 7 4 5
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cin >> k;
					x[i][j] = k;
				}
			}
			Obhod(x, m, n);
			cout << endl;
			// Освобождаем память
			for (int i = 0; i < m; ++i) {
				delete[] x[i];
			}
			delete[] x;
		}
		else { cout << "Ожидание ввода номера задания: \n";}
	}
}
