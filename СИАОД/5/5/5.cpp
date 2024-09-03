#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>	
#include <algorithm>
#include <iterator>
#include <sstream>
#include <set>
#include <random>
using namespace std;
double prog(double x, double y, double z) {
	double Q;
	Q = x * x + y * y + z * z;
	return Q;
}
int prost(long long i) {
	for (long long j = 2; j <= sqrt(i); j++) {
		if (i % j == 0) {
			return 0;
		}
	}
	return i;
}
double evk(double x, double y) {
	if (y == 0)
		return x;

	return evk(y, fmod(x,y));
}
double evk2(double x, double y) {
	while (x != y) {
		if (x > y) {
			x -= y;
		}
		else { y -= x; }
	}
	return x;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	int a;
	double x, y;
	while (true) {
		cout << "Введите номер задания:\n";
		cin >> a;
		if (a == 1) {
			cout << "Первое число\n";
			cin >> x;
			cout << "Второе число\n";
			cin >> y;
			if (x <= 0 or y <= 0) {
				cout << "Error" << endl;
			}
			else {
				cout << "Делением: " << evk(x, y) << endl;
				cout << "Вычитанием: " << evk2(x, y) << endl;
			}
		}
		else if (a == 2) {
			double b;
			cout << "Число:\n";
			cin >> b;
			if (b >= 2) {
				cout << 2 << endl;
				if (b >= 3) {
					for (long long i = 3; i <= b; i += 2) {
						if (prost(i) > 0) {
							cout << i << endl;
						}
					}
				}
			}
			else { cout << "Нет простых чисел в таком диапазоне\n"; break; }
		}
		else if (a == 3) {
			int b;
			//4 и 6 задания
			cout << "1 или 2\n";
			cin >> b;
			while (b != 1 and b != 2) {
				cout << "Нет такого, 1 или 2:\n";
				cin >> b;
			}
			setlocale(0, "");
			ofstream JJJ("Zadanie.txt");
			ofstream G;
			string res;
			int k = 0, S = 0, v = 0, l = 0;
			char c;
			G.open("Zadanie.txt");
			if (G.is_open()) {
				string text, kol = "{";
				while (getline(cin, text)) {
					if (text == kol) { break; }
					G << text << endl;
				}
				G.close();
				string line;
				string arr[10000];
				if (b == 2) {
					for (int i = 0; i < 10000; i++) {
						arr[i] = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
					}
				}
				ifstream in("Zadanie.txt");
				if (in.is_open()) {
					while (getline(in, line)) {
						text = "";
						l = strlen(line.c_str());
						for (int i = 0; i < l; i++) {
							c = line[i];
							if (not (c == ' ')) {
								text += line[i];
							}
							if ((c == ' ')) {
								arr[v] = text;
								text = "";
								v++;
							}
							if (i == l - 1) {
								arr[v] = text;
								text = "";
								v++;
							}
						}
					}
				}
				in.close();
				if (b == 1) {
					S = 0;
				}
				else if (b == 2) {
					S = 100000000;
				}
				for (int i = 0; i < 10000; i++) {
					l = strlen(arr[i].c_str());
					if (b == 1) {S = max(S, l); }
					else if (b == 2) {S = min(S, l); }
				}
				for (int i = 0; i < 10000; i++) {
					l = strlen(arr[i].c_str());
					if (l == S) {
						cout << arr[i] << endl;
					}
				}
			}
		}
		else if (a == 4) {
			//60 и 30
			int b;
			cout << "1 или 2\n";
			cin >> b;
			while (b != 1 and b != 2) {
				cout << "Нет такого, 1 или 2:\n";
				cin >> b;
			}
			if (b == 1) {
				int N, r;
				double x = 1, y = 1, z = 1, a;
				cout << "N\n";
				cin >> N;
				r = 3*N;
				double arr[30000];
				for (int i = 0; i < 30000; i++) {
					arr[i] = 0;
				}
				if ((N > 0) and (int(N) == N)) {
					cout << "Введите " << r << " действительных чисел\n";
					for (int i = 0; i < r; i++) {
						cin>>a;
						if (double(a) == a) { arr[i] = a; }
						else { break; }
					}
					for (int i = 0; i < N; i++) {
						x *= arr[i];
					}
					for (int i = N + 1; i < 2 * N; i++) {
						y *= arr[i];
					}
					for (int i = ((2 * N) + 1); i < 3 * N; i++) {
						z *= arr[i];
					}
					cout << "Q: " << prog(x, y, z) << endl;
				}
				else {
					cout << "N должно быть натуральным\n";
				}
			}
			else if (b == 2) {
				string N;
				std::set<int> arr; 
				cout << "Целое N:\n";
				cin >> N;
				int J;
				for (int i = 0; i < strlen(N.c_str()); i++) {
					if (isdigit(N[i])) {
						J = N[i] - '0';
						arr.insert(J);
					}
					else {
						cout << "Это не число\n";
						break;
					}
				}
				for (int i : arr) {
					cout << i << endl;
				}
			}
		}
		else if (a == 5) {
			//18
			setlocale(LC_ALL, "RU");
			ofstream JJJ("phone.txt");
			ofstream G;
			G.open("phone.txt");
			string line, res,text;
			int i = 0,l,k=0,v=0;
			char c;
			string arr[999];
			if (G.is_open()) {
				string text, kol = "{";
				while (getline(cin, text)) {
					if (text == kol) { break; }
					G << text << endl;
				}
			}
			cout << "Введите фамилию человека:\n";
			cin >> res;
			ifstream T("phone.txt");
			if (T.is_open()) {
				while (getline(T, line)) {
					text = "";
					l = strlen(line.c_str());
					for (int i = 0; i < l; i++) {
						c = line[i];
						if (not (c == ' ')) {
							text += line[i];
						}
						if ((c == ' ')) {
							arr[v] = text;
							text = "";
							v++;
						}
						if (i == l - 1) {
							arr[v] = text;
							text = "";
							v++;
						}
					} 
				}
			}
			for (int i = 0; i < 999; i++) {
				if (arr[i] == res) {
					cout << arr[i] << " " <<arr[i+1]<<" " << arr[i + 2] << endl;
					k++;
				}
			}
			if (k == 0) {
				cout << "Нет такого человека в списке\n";
			}
			ofstream O("sorted.txt");
			O.open("sorted.txt");
			string fam;
			char s;
			int j,S=1000000;
			v = 0;
			string sorted[999];
			if (O.is_open())
			{
				for (int i = 0; i < 999; i+=3) {
					fam = arr[i];
					s = fam[0];
					j = int(s);
					if (S > j) {
						S = j;
					}
				}
				for (int i = 0; i < 999; i += 3) {
					fam = arr[i];
					s = fam[0];
					j = int(s);
					if (S == j) {
						sorted[v]=fam;
						v++;
						sorted[v] = arr[i + 1];
						v++;
						sorted[v] = arr[i + 2];
						v++;
						arr[i] = " ";
					}
				}
				for (int i = 0; i < 999; i+=3) {
					O << sorted[i] << sorted[i + 1] << sorted[i + 2] << endl;
				}
			}
			ifstream H("sorted.txt");
			if (H.is_open()) {
				while (getline(H, line)) {
					cout << line << endl;
				}
			}
		}
		else{
			cout << "Нет такого задания\n";
			return 0;
			break;
			}
	}
}