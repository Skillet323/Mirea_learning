﻿#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int a, h, R, r, A, b;
    double p,l, V, x, S, y;
    while (true) {
        cout << "Введите № задания\n";
        cin >> a;
        if (a == 1)
        {
            p = 3.14;
            cout << "Напишите больший радиус: \n";
            cin >> R;
            cout << "Напишите меньший радиус: \n";
            cin >> r;
            cout << "Напишите высоту: \n";
            cin >> h;
            l = sqrt(pow(R, 2) + pow(h, 2));
            if ((h <= 0) or (l<=0) or (R<=r) or (R <= 0) or (r <= 0))  { cout << "Это не конус\n"; }
            else{
                V = (p * h * (pow(R, 2) + R * r + pow(r, 2))) / 3;
                S = p * (pow(R, 2) + ((R + r) * l) + pow(r, 2));
                cout << "Объём: " << V << " Площадь: " << S << "\n";
            }
        }
        else if (a == 2) {
            cout << "Введите x и a\n";
            cin >> x;
            cin >> A;
            if (abs(x) < 1) {
                S = A * log(abs(x));
                cout << "Ответ: " << S << '\n';
            }
            else if (abs(x) >= 1) {
                if (A < pow(x, 2)) { cout << "Нельзя извлечь корень из отриц числа\n"; }
                else if (A>= pow(x,2)) {
                    S = sqrt( A - pow(x, 2));
                    cout << "Ответ: " << S << '\n';
                }
            }
        }
        else if (a == 3) {
            cout << "Введите x, y и b\n";
            cin >> x;
            cin >> y;
            cin >> b;
            if (((b - x) < 0) or ((b - y) <=0)) {cout << "Нельзя извлечь корень из отриц числа\n";
            }
            else {
                S = (log(b - y)) * (sqrt(b - x));
                cout << "Ответ: " << S << '\n';
            }
        }
        else if (a == 4) {
            cout << "Введите N\n";
            cin >> x;
            if ((int(x) == x) and (x > 0)) {
                for (int y = 1; y < 11; y++) { cout << x<<" "; x += 1; }
                cout << "\n";
            }
            else { cout << "N должно быть натуральным\n"; break; }
        }
        else if (a == 5) {
            for (double x = -4; x < 4.5; x += 0.5) {
                if (x != 1) { y = ((pow(x, 2) - (2 * x) + 2) / (x - 1)); cout << y << " "; }
                else { cout << "не буду"; }
                cout << "\n";
            }
        }
    }
}