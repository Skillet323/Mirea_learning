#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    int a, b, x, c, A, D, s;
    while (true) {
        cout << "Введите № задания\n";
        cin >> a;
        if (a == 1)
        {
                cout << "Тимофей\n";
        }
        else if (a == 2) {
                cout << "Введите 2 числа\n";
                cin >> x;
                cin >> b;
                cout << x + b << ' ' << x - b << ' ' << x * b << ' ';
                if (b == 0) { cout << "Не дели на ноль\n"; }
                else { cout << x / b << "\n"; }
        }
        else if (a == 3) {
                cout << "Введите b и c\n";
                cin >> b;
                cin >> c;
                if (b == 0) { cout << "Уравнение не зависит от x\n"; }
                else { x = -c / b; cout << x << '\n'; }
        }
        else if (a == 4) {
                cout << "Введите a,b и c\n";
                cin >> A;
                cin >> b;
                cin >> c;
                if (A == 0) {
                    if (b == 0) { cout << "На ноль делить нельзя\n"; }
                    else {
                        x = -c / b;
                        cout << x << '\n';
                    }
                    
                }
                D = pow(b, 2) - (4 * A * c);
                if (D < 0) { cout << "Решений нет\n"; }
                else if (D == 0) {
                    x = -b / (2 * A);
                    cout << x << '\n';
                }
                else if (A>0 and D>0) {
                    x = -b + sqrt(D) / (2 * A);
                    s = -b - sqrt(D) / (2 * A);
                    cout << "Первый корень: " << x << " " << "Второй корень : " << s << "\n";
                }
        }
        else if (a == 5) {
                cout << "1=да. 0=нет.\n";
                cout << "Шторы открыты?\n";
                cin >> b;
                cout << "На улице день?\n";
                cin >> c;
                cout << "Включена ли лампа?\n";
                cin >> A;
                s = b * c + A;
                if (s == 1) { cout << "В комнате светло\n"; }
                else { cout << "В комнате темно\n"; }
        }
    }
}