#include <iostream>
#include "Windows.h"
#include <time.h>
#include <string>
#include <fstream>
using namespace std;
void pole(char(&x)[21][21], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}
void clear(int(&x)[21][21], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = 0;
        }
    }
}
void Fill(int(&x)[21][21], char(&y)[21][21], int n) {
    ifstream G;
    char c;
    string text;
    int k = 0, j = 0;
    G.open("C:\\Users\\borga\\source\\repos\\MicrobiNein.txt");
    if (G.is_open()) {
        while (getline(G, text)) {
            for (int j = 0; j < n; j++) {
                c = text[j];
                if (c == '1') {
                    x[k][j] = 1;
                }
                else { x[k][j] = 0; }
                if (x[k][j] > 0) {
                    y[k][j] = 'M';
                }
                else { y[k][j] = ' '; }
            }
            k++;
        }
        G.close();
    }
}
int pos[2][8] = { {1, 1, 1, 0, 0, -1, -1, -1}, {1, 0, -1, 1, -1, 1, 0, -1} };
void live(int(&x)[21][21], char(&y)[21][21], int n)
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
                else { y[i][j] = 'M'; }
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
void lvl(int(&x)[21][21], char(&y)[21][21], int n) {
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
int death(int(&x)[21][21], char(&y)[21][21], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i][j] == 0) count++;
        }
    }
    if (count > 440) {
        return 1;
    }
    else { cout << "Микробов " << count << " штук\n"; }
    return 0;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int N;
    int a[21][21];
    cout << "Введите количество поколений: \n";
    cin >> N;
    int arr_mask[21][21];
    char arr_out[21][21];
    clear(arr_mask, 21);
    Fill(arr_mask, arr_out, 21);
    for (int i = 0; i < N; i++)
    {
        system("cls");
        pole(arr_out, 21);
        live(arr_mask, arr_out, 21);
        lvl(arr_mask, arr_out, 21);
        cout << "Поколение № " << i + 1 << endl;
        if (death(arr_mask, arr_out, 21) == 1) {
            system("cls");
            pole(arr_out, 21);
            live(arr_mask, arr_out, 21);
            lvl(arr_mask, arr_out, 21);
            cout << "Смерть микробам \n";
            break;
        }
        Sleep(1000);
    }
    cout << "Поколения кончились\n";
    system("pause");
    return 0;
}
