#include <iostream>
#include <math.h>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int a, h, R, A, b;
    double  r, p, l, V, x, S, y, n, m;
    char str;
    while (true) {
        cout << "Введите № задания\n";
        cin >> a;
        if (a == 1) {
            cout << "Введите S\n";
            cin >> S;
            cout << "Введите p\n";
            cin >> p;
            cout << "Введите n\n";
            cin >> n;
            r = p / 100;
            if (((pow(1 + r, n)) != 1) and S > 0 and p > 0 and p <= 100 and n > 0) {
                m = (S * r * (pow(1 + r, n))) / (12 * ((pow(1 + r, n)) - 1));
                cout << m << "\n";
            }
            else if ((pow(1 + r, n)) == 1) { cout << "Делить на ноль нельзя\n"; }
            else { cout << "Числа не подходят \n"; }
        }
        else if (a == 2) {
            cout << "Введите S\n";
            cin >> S;
            cout << "Введите m\n";
            cin >> m;
            cout << "Введите n\n";
            cin >> n;
            if (S > 0 and m > 0 and n > 0) {
                for (double p = 1; p <= 100; p++) {
                    r = p / 100;
                    x = (S * r * (pow(1 + r, n))) / (12 * ((pow(1 + r, n)) - 1));
                    if ((x - 0.01 < m) and (m < x + 0.01)) {
                        cout << p << "%\n";
                    }
                }
            }
        }
        else if (a == 3) {
            setlocale(0, "");
            int te = 0;
            ofstream JJJ("Zadanie.txt");
            ofstream G;
            G.open("Zadanie.txt");
            if (G.is_open()) {
                string text, kol = "{";
                while (getline(cin, text)) {
                    if (text == kol) { break; }
                    G << text << endl;
                }
                G.close();
                string line;
                ifstream in("Zadanie.txt");
                if (in.is_open()) {
                    while (getline(in, line)) {
                        for (int i = 0; i < strlen(line.c_str()); i++) {
                            te++;
                        }
                    }
                }
                in.close();
                cout << te;
            }
        }
        else if (a == 4) {
            setlocale(0, "");
            ofstream JJJ("Zadanie.txt");
            ofstream G;
            G.open("Zadanie.txt");
            if (G.is_open()) {
                string text, kol = "{";
                while (getline(cin, text)) {
                    if (text == kol) { break; }
                    G << text << endl;
                }
                G.close();
                string line;
                string chisla;
                ifstream in("Zadanie.txt");
                if (in.is_open()) {
                    while (getline(in, line)) {
                        chisla = "";
                        chisla += line;
                        for (int i = 0; i < strlen(chisla.c_str()); i++) {
                            if (isdigit(chisla[i])) {
                                cout << chisla[i];
                                if (not isdigit(chisla[i + 1])) { cout << " "; }
                            }
                        }
                    }
                }
                in.close();
                cout << "\n";
            }
        }
        else if (a == 5) {
            setlocale(0, "");
            ofstream JJJ("Zadanie.txt");
            ofstream G;
            G.open("Zadanie.txt");
            if (G.is_open()) {
                string text, kol = "{";
                while (getline(cin, text)) {
                    if (text == kol) { break; }
                    G << text << endl;
                }
                G.close();
                string line;
                string Alph;
                int minka, minind;
                ifstream in("Zadanie.txt");
                if (in.is_open()) {
                    while (getline(in, line)) {
                        Alph += line;
                    }
                    char* cstr = new char[30];
                    for (size_t i = 0; i < Alph.size(); i++){cstr[i] = Alph[i];
                    }
                    int da[30]{};
                    for (int i = 0; i < Alph.size(); i++) {
                        da[i] = int(Alph[i]);
                    }
                    if (strlen(Alph.c_str()) == 30) {
                        for (int i = 0; i < strlen(line.c_str()); i++) {
                        }
                    }
                    else { cout << "Должно быть 30 букв\n"; }
                    cout << cstr << endl;
                    cout << da << endl;
                }
                in.close();
            }
        }
        else {break;}
        }

    }
