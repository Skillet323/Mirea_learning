#include <iostream>
#include "Windows.h"
#include <conio.h>
#include <time.h>
using namespace std;
void Input(int M) {
    if (_kbhit()) {
        switch (_getch()) {
        case 's': case 'S': case 'ы': case 'Ы':
            M-= 100;
            break;
        case 'w': case 'W': case 'ц': case 'Ц':
            M+= 100;
            break;
        }
    }
}
void pole(char** x, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}
void clear(int** x, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = 0;

}
void Fill(int** x, char**y, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = rand() % 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] > 0) {
                y[i][j] = 'M';
            }
            else { y[i][j] = ' '; }
        }
    }

}
int pos[2][8] = { {1, 1, 1, 0, 0, -1, -1, -1}, {1, 0, -1, 1, -1, 1, 0, -1} };
void live(int** x, char** y, int n)
{
    int tmpi = 0;
    int tmpj = 0;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                tmpi = i + pos[0][k];
                tmpj = j + pos[1][k];
                if (tmpi < 0) tmpi = n - 1;
                else if (tmpi >= n) tmpi = 0;
                if (tmpj < 0) tmpj = n - 1;
                else if (tmpj >= n) tmpj = 0;
                g += (x[tmpi][tmpj] > 0);
            }
            if (x[i][j] > 0)
            {

                if ((g > 3) || (g < 2))
                {
                    x[i][j] = 0;
                    y[i][j] = ' ';
                }
            }
            else
            {
                if (g == 3)
                {
                    x[i][j] = 1;
                    y[i][j] = 'M';
                }
            }
            g = 0;
        }
    }
}
void lvl(int** x, char** y, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] > 0) {
                x[i][j] += 1;
            }
            if (x[i][j] > 11) {
                x[i][j] = 0;
                y[i][j] = ' ';
            }
        }
    }
}
int death(int** x, char** y, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           if (x[i][j]>0) count++;
        }
    }
    if (count > 440) {
        cout << "Смерть микробам \n";
        return 1;
    }
    return 0;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int N, M;
    M = 1000;
    cout << "Введите количество поколений: \n";
    cin >> N;
    int** arr_mask = new int* [21];
    char** arr_out = new char* [21];
    for (int i = 0; i < 21; i++)
    {
        arr_mask[i] = new int[21];
    }
    for (int i = 0; i < 21; i++)
    {
        arr_out[i] = new char[21];
    }
    while (true) {
    clear(arr_mask, 21);
    Fill(arr_mask, arr_out, 21);
    Input(M);
    for (int i = 0; i < N; i++)
    {

        system("cls");
        cout << "W - повысить скорость\nS - понизить скорость\n";
        live(arr_mask, arr_out, 21);
        pole(arr_out, 21);
        lvl(arr_mask, arr_out, 21);
        Input(M);
        cout << "Поколение № " << i + 1 << endl;
        if (death(arr_mask, arr_out, 21) == 1) {
            break;
        }
        Sleep(M);
    }

    for (int i = 0; i < N; i++)
    {
        delete[] arr_mask[i];
        delete[] arr_out[i];
    }
    delete[] arr_out;
    cout << "Поколения кончились\n";
    system("pause");
    return 0;
}
}