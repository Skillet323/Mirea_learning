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
using namespace std;
bool flag;
bool Af(const string& str) {
	for (char ch : str) {
		if (isalpha(ch) && isdigit(ch)) {
			return false;
		}
	}
	return true;
}
bool isDouble(const string& str) {
	istringstream stream(str);
	double value;
	return (stream >> value) && stream.eof();
}
void matrizi(int A[3][4], double B[4][2]) {
	A[0][0] = 5;
	A[0][1] = 2;
	A[0][2] = 0;
	A[0][3] = 10;
	A[1][0] = 3;
	A[1][1] = 5;
	A[1][2] = 2;
	A[1][3] = 5;
	A[2][0] = 20;
	A[2][1] = 0;
	A[2][2] = 0;
	A[2][3] = 0;
	B[0][0] = 1.20;
	B[0][1] = 0.50;
	B[1][0] = 2.80;
	B[1][1] = 0.40;
	B[2][0] = 5.00;
	B[2][1] = 1.00;
	B[3][0] = 2.00;
	B[3][1] = 1.50;
}
void sinus() {
	cout << "**__________________**__________________**" << endl;
	cout << "__**______________**__**______________**__" << endl;
	cout << "____**__________**______**__________**____" << endl;
	cout << "______**______**__________**______**______" << endl;
	cout << "________**__**______________**__**________" << endl;
	cout << "__________**__________________**__________" << endl;
	double PI = 3.14;
	const int width = 100;
	const int height = 30;
	double start = 0.0;
	double end = 2 * PI;
	double step = (end - start) / width;
	for (double x = start; x <= end; x += step) {
		double y = sin(x);
		int yPos = static_cast<int>((y + 1) * height / 2);
		for (int i = 0; i < width; i++) {
			if (i == yPos) {
				cout << "*";
			}
			else if (i == height / 2) {
				cout << "-";
			}
			else {
				cout << " ";
			}
		}
		cout <<endl;
	}
}
int Arab(char Rim) {
	switch (Rim) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return -1;
	}
}
int init(char Rim) {
	switch (Rim) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'F':
		return 15;
	case 'E':
		return 14;
	case 'a':
		return 10;
	case 'b':
		return 11;
	case 'c':
		return 12;
	case 'd':
		return 13;
	case 'e':
		return 14;
	case 'f':
		return 15;
	default:
		return 9999999999999;
	}
}
bool posledovatelnost(string chislo) {
	char next, now, next1, next2;
	int x = 0;
	if ((strlen(chislo.c_str()) > 2)) {
		for (int i = 0; i <= strlen(chislo.c_str() - 2); i++) {
			now = chislo[i];
			next = chislo[i + 1];
			next1 = chislo[i + 2];
			if ((not (now == next and (now == 'L' or now == 'D' or now == 'V'))) and (not((now == 'X' and next == 'C' and next1 == 'M') or (now == 'X' and next == 'C' and next1 == 'D') or (now == 'I' and next == 'V' and next1 == 'X') or (now == 'I' and next == 'X' and next1 == 'C') or (now == 'I' and next == 'X' and next1 == 'L') or (next == 'X' and now == 'V') or (next == 'C' and now == 'L') or (next == 'M' and now == 'D') or (next == 'C' and now == 'V')))) {
				x = 1;
			}
			else { x = 0; }
		}
	}
	else if (strlen(chislo.c_str()) > 1) {
		for (int i = 0; i <= strlen(chislo.c_str() - 1); i++) {
			now = chislo[i];
			next = chislo[i + 1];
			if ((not (now == next and (now == 'L' or now == 'D' or now == 'V'))) and (not((next == 'X' and now == 'V') or (next == 'C' and now == 'L') or (next == 'M' and now == 'D') or (next == 'C' and now == 'V')))) {
				x = 1;
			}
			else { x = 0; }
		}
	}
	else if (strlen(chislo.c_str()) == 1) {
		x = 1;
	}
	if (x == 0) {
		return false;
	}
	else { return true; }
	}
void square(int Fig) {
	double x, y, z, p, S;
	switch (Fig) {
	case 1:
		cout << "Введите длину\n";
		cin >> x;
		cout << "Введите ширину\n";
		cin >> y;
		if (x > 0 and y > 0) {
			S = x * y;
			cout << "Площадь равна " << S << endl;
		}
		else { cout << "Err\n"; }
		break;
	case 2:
		cout << "Введите первую сторону\n";
		cin >> x;
		cout << "Введите вторую сторону\n";
		cin >> y;
		cout << "Введите третью сторону\n";
		cin >> z;
		if ((x > 0 and y > 0 and z > 0) and (x + y > z) and (x + z > y) and (z + y > x)) {
			p = (x + y + z) / 2;
			S = sqrt((p * (p - x) * (p - y) * (p - z)));
			cout << "Площадь равна " << S << endl;
		}
		else { cout << "Err\n"; }
		break;
	case 3:
		cout << "Введите радиус окружности\n";
		cin >> x;
		p = 3, 14;
		if (x > 0) {
			S = x * x * p;
			cout << "Площадь равна " << S << endl;
		}
		else { cout << "Err\n"; }
		break;
	default:
		cout << "Не знаю такой фигуры\n";
		break;
	}
}
int sign(double y) {
	if (y > 0) {
		return 1;
	}
	else if (y < 0) {
		return -1;
	}
	else {
		return 0; 
	}
}
int recur1(int i) {
	int m = 37;
	int b = 3;
	int c = 64;
	if (i == 0) { return 0; }
	return((m * recur1(i-1) + b) % c);
}
int recur2(int i) {
	int m = 25173;
	int b = 13849;
	int c = 65537;
	if (i == 0) { return 0; }
	return((m * recur2(i - 1) + b) % c);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int a;
	double S = 0, R, x, y, z, p;
	string text, line, kol, chisla;
	while (true) {
		cout << "Номер задания:\n";
		cin >> a;
		if (a == 1) {
			string input;
			flag = true;
			setlocale(0, "");
			ofstream Doc("File1.txt");
			ofstream G;
			G.open("File1.txt");
			if (G.is_open()) {
				for (int i = 0; i < 10; i++) {
					cin >> input;
					R = stod(input);
					for (int i = 0; i < strlen(input.c_str()); i++) {
						if (not isdigit(input[i]) and not (input[0]=='-') and not (input[i]=='.') and not (input[i] == ',')) {
							cout << "Это не число\n";
							flag = false;
							break;
						}
					}
					if (flag == false) { exit(0);  return 0; break; }
					if ((flag==true)) {
						G << R << endl;
						S += R;
					}
					else {
						cout << "Это не число\n";
						break;
					}
				}
			}
			G.close();
			cout << "Сумма:" << S << endl;
		}
		else if (a == 2) {
			string input;
			double inputNumber;
			int sign1;
			cout << "Введите число: ";
			cin >> input;
			istringstream stream(input);
			flag = true;
			for (int i = 0; i < strlen(input.c_str()); i++) {
				if (not isdigit(input[i]) and not (input[i]=='-')) {
					cout << "Это не число\n";
					flag = false;
					break;
				}
			}
			if (flag == true) {
				if (stream >> inputNumber) {
					sign1 = sign(inputNumber) + 0;
					if (inputNumber == 0.0) {
						cout << "Вы ввели число 0." << endl;
					}
					else {
						cout << "Знак числа: " << sign1 << endl;
					}
				}
				else {
					cout << "Ошибка: Введено не число." << endl;
				}
			}
		}
		else if (a == 3) {
			int Fig;
			cout << "Прямоугольник = 1\n" << "Треугольник = 2\n" << "Круг = 3\n";
			cin >> Fig;
			square(Fig);
		}
		else if (a == 4) {
			for (int i = 0; i < 6; i++) {
				cout << "********____________" << endl;
			}
			for (int i = 0; i < 7; i++) {
				cout << "____________________" << endl;
			}
		}
		else if (a == 5) {
			sinus();
		}
		else if (a == 6) {
			string text;
			cin >> text;
			int e;
			int now,next,S=0;
			flag = true;
			flag = Af(text);
			for (int i = 0; i < strlen(text.c_str()); i++) {
				e = Arab(text[i]);
				if ((e == -1)) {
					flag = false;
				}
			}
			if (flag == true) {
				if (posledovatelnost(text)) {
					if (strlen(text.c_str())>1) {
						for (int i = 0; i < strlen(text.c_str()) - 1; i++) {
							now = Arab(text[i]);
							next = Arab(text[i + 1]);
							if (((now == 1) and (next == 5 or next == 10)) or ((now == 10) and (next == 50 or next == 100)) or ((now == 100) and (next == 500 or next == 1000))) {
								now = -now;
							}
							S += now;
						}
						S += next;
						cout << S << endl;
					}
					else if (strlen(text.c_str()) == 1) {
						cout << Arab(text[0])<<endl;
					}
				}
				else { cout << "Нет такого числа в римской с-ме" << endl; }
			}
			else { cout << "Нет такого числа в римской с-ме" << endl; }
		}
		else if (a == 7) {
			int z;
			cout << "Вариант 1 или 2:\n";
			cin >> z;
			switch (z) {
			case 1:
				for (int i = 0; ; i++) {
					cout << recur1(i) << endl;
				}
			case 2:
				for (int i = 0; ; i++) {
					cout << recur2(i) << endl;
				}
			default:
				cout << "1 или 2, не более";
				break;
			}
		}
		else if (a == 8) {
			int f;
			double C[3][2];
			int A[3][4];
			double B[4][2];
			double x, y, z, g;
			A[0][0] = 5;
			A[0][1] = 2;
			A[0][2] = 0;
			A[0][3] = 10;
			A[1][0] = 3;
			A[1][1] = 5;
			A[1][2] = 2;
			A[1][3] = 5;
			A[2][0] = 20;
			A[2][1] = 0;
			A[2][2] = 0;
			A[2][3] = 0;
			B[0][0] = 1.20;
			B[0][1] = 0.50;
			B[1][0] = 2.80;
			B[1][1] = 0.40;
			B[2][0] = 5.00;
			B[2][1] = 1.00;
			B[3][0] = 2.00;
			B[3][1] = 1.50;
			cout << "Матрица C:" << endl;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 2; j++) {
					C[i][j] = ((A[i][0] * B[0][j]) + (A[i][1] * B[1][j]) + (A[i][2] * B[2][j]) + (A[i][3] * B[3][j]));
					//00 = 00*00 + 01*10 + 02*20 + 03*30
					//01 = 00*01 + 01*11 + 02*21 + 03*31 
					//10 = 10*00 + 11*10 + 12*20 + 13*30
					//11 = 10*01 + 11*11 + 12*21 + 13*31
					//20 = 20*00 + 21*10 + 22*20 + 23*30
					//21 = 20*01 + 21*11 + 22*21 + 23*31
					cout << C[i][j] << "\t";
				}
				cout << endl;
			}
			x = (C[0][0] + C[0][1]);
			y = (C[1][0] + C[1][1]);
			z = (C[2][0] + C[2][1]);
			g = x + y + z;
			if (x == max(x, y, z)) { f = 1; }
			if (y == max(x, y, z)) { f = 2; }
			if (z == max(x, y, z)) { f = 3; }
			cout<<"Больше всех получил " << f<< " продавец(" << max(x, y, z) << " денег)" << endl;
			x = C[0][1];
			y = C[1][1];
			z = C[2][1];
			if (x == max(x, y, z)) { f = 1; }
			if (y == max(x, y, z)) { f = 2; }
			if (z == max(x, y, z)) { f = 3; }
			cout << "Больше всех комисиионых получил " << f << " продавец(" << max(x, y, z) << ")" << endl;
			if (x == min(x, z, y)) { f = 1; }
			if (y == min(x, z, y)) { f = 2; }
			if (z == min(x, z, y)) { f = 3; }
			cout << "Меньше всех комисиионых получил " << f << " продавец(" << min(x, z, y) << ")" << endl;
			cout << "Общая сумма денег за товары: " << (C[0][0] + C[1][0] + C[2][0]) << endl;
			cout << "Сумма комиссионых: " << x + y + z << endl;
			cout << "Вообще все деньги: " << g << endl;
		}
		else if (a == 9) {
			string chislo, aaaa;
			long long N1, N2, e,o;
			long long z=0;
			int j=0;
			char buffer[33000];
			cout << "Введите число:\n";
			cin >> chislo;
			cout << "CC 1?\n";
			cin >> N1;
			cout << "CC 2?\n";
			cin >> N2;
			for (int i = 0; i < strlen(chislo.c_str()); i++) {
				e = init(chislo[i]);
				if (e < N1) {
					flag = true;
				}
				else { flag = false; cout << "Нет такой цифры в этой СС\n"; break; }
			}
			if (flag == true) {
				for (int i = strlen(chislo.c_str())-1; i > 0; i--) {
				e = init(chislo[j]);
				o = (pow(N1, i));
				z += (e * o);
				j++;
				//перевели в 10}
				}
				if (N2 == 10) {
					cout << z<<endl;
				}
				else{
					_itoa_s(z, buffer, N2);
					cout << buffer << endl;
				}
			}
		}
		else { cout << "Нет такого задания\n"; break; }
	}
}