#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string>
#include <time.h>
#include <wincon.h>
#include <vector>
#include <windows.h>	
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
using namespace std;
bool flag; 
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
	}
}
bool posledovatelnost() {
	string chislo;
	char next, now, prev;
	for (int i = 0; i < strlen(chislo.c_str()-1); i++) {
		now = chislo[i];
		next = chislo[i + 1];
		if (now == next and (now == 'L' or now == 'D' or now == 'V')) {
			return false;
			break;
		}
		else if ((next == 'X' and now  == 'V') || (next == 'C' and now == 'L') || (next == 'M' and now == 'D')) {
			return false;
			break;
		}
		else { return true; }
	}
}
void square(int Fig) {
	double x, y, z,p, S;
	switch(Fig){
	case 1:
		cout << "Введите длину\n";
		cin >> x;
		cout << "Введите ширину\n";
		cin >> y;
		if (x>0 and y>0){
			S = x * y;
			cout << "Площадь равна " << S << endl;
		}
		else { cout<<"Err\n"; }
		break;
	case 2:
		cout << "Введите первую сторону\n";
		cin >> x;
		cout << "Введите вторую сторону\n";
		cin >> y;
		cout << "Введите третью сторону\n";
		cin >> z;
		if((x>0 and y>0 and z>0) and (x+y>z) and (x + z > y)and (z + y > x)){
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
		if (x>0){
			S = x * x*p;
			cout << "Площадь равна " << S << endl;
		}
		else{ cout << "Err\n";}
		break;
	default:
		cout << "Не знаю такой фигуры\n";
		break;
	}
}
void sign(string y) {
	for (int i = 0; i < strlen(y.c_str()); i++) {
		flag = true;
		if (isdigit(y[i]) == 0) {
			cout << "Это не число\n";
			flag = false;
			break;
		}
	}
	if (flag==true){
		if (y[0] > 0) { cout << "1\n"; }
		else if (y[0] < 0) { cout << "-1\n"; }
		else if (y[0] == 0) { cout << "0\n"; }
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int a;
	double S=0,R,x,y,z,p;
	string text, line, kol, chisla;
	while (true) {
		cout << "Номер задания:\n";
		cin >> a;
		if (a == 1) {
			setlocale(0, "");
			ofstream Doc("File1.txt");
			ofstream G;
			G.open("File1.txt");
			if (G.is_open()) {
				for (int i = 0; i < 10; i++) {
					cin >> R;
					if ((double(R) == R)) {
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
			cout << "Сумма:" << S<<endl;
		}
		else if (a == 2 ) {
			string y;
			cin >> y;
			sign(y);
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
			cout << "**__________________**__________________**";
			cout << "__**______________**__**______________**__";
			cout << "____**__________**______**__________**____";
			cout << "______**______**__________**______**______";
			cout << "________**__**______________**__**________";
			cout << "__________**__________________**__________";
		}
		else if (a == 6) {

		}
		else if (a == 7) {

		}
		else if (a == 8) {

		}
		else if (a == 9) {

		}
		else { cout << "Нет такого задания\n"; break; }
	}
}