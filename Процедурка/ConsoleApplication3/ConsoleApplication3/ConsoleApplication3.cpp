#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <time.h>
#include <wincon.h>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2) {
    MoveToEx(hdc, x1, y1, NULL);
    return LineTo(hdc, x2, y2);
}
int main() {
    int x = 400;
    int y = 150;
    double a = 1;
    int b = 2;
    srand(time(NULL));
    HWND hWnd = GetConsoleWindow();
    HDC hDc = GetDC(hWnd);
    int red = 255;
    int green = 255;
    int blue = 255;
    COLORREF color = RGB(red, green, blue);
    HPEN pen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hDc, pen);
    Line(hDc, x, 0, x, 2 * y);
    Line(hDc, 200, y, 2 * x, y);
    COLORREF c2 = red;
    SetPixel(hDc, x + 1, 2, red);
    SetPixel(hDc, x + 2, 3, color);
    SetPixel(hDc, x + 3, 4, color);
    SetPixel(hDc, x - 1, 2, color);
    SetPixel(hDc, x - 2, 3, color);
    SetPixel(hDc, x - 3, 4, color);
    SetPixel(hDc, 2 * x - 2, y - 1, color);
    SetPixel(hDc, 2 * x - 3, y - 2, color);
    SetPixel(hDc, 2 * x - 4, y - 3, color);
    SetPixel(hDc, 2 * x - 2, y + 1, color);
    SetPixel(hDc, 2 * x - 3, y + 2, color);
    SetPixel(hDc, 2 * x - 4, y + 3, color);
    for (int i = 200; i < 600; i += 50) {
        Line(hDc, i, y - 2, i, y + 2);
    }
    for (int i = 0; i < y * 2; i += 50) {
        Line(hDc, x - 2, i, x + 2, i);
    }
    cout << "function: Y = sin(x) \t\t\t\ty\n\n";
    cout << "|y\t|x\t|\n";
    cout << "|_______________|\n";
    for (double i = -5; i <= 5; i++) {
        double j = 1 / i;
        cout << fixed << setprecision(3) << "|" << j << "\t|" << i << "\t|\n";
    }
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 48, 7 };
    SetConsoleCursorPosition(hConsole, pos);
    cout << 1;
    COORD pos1 = { 56,11 };
    SetConsoleCursorPosition(hConsole, pos1);
    cout << 1 << "                      x";
    for (double x1 = -30; x1 < 5; x1 += 0.0001) {
        int y1 = sin(x1) * 50;
        SetPixel(hDc, x1 * 5 + x + 63, y - y1, red);
    }
    int asd;
    cin >> asd;
    ReleaseDC(hWnd, hDc);
    return 0;
}