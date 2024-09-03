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
    srand(time(NULL));
    HWND hWnd = GetConsoleWindow();
    HDC hDc = GetDC(hWnd);
    COLORREF color = RGB(255, 255, 255);
    HPEN pen = CreatePen(PS_SOLID, 1, color);
    SelectObject(hDc, pen);
    cout << "FUNCTION : Y = Sin(X)\n\n";
    cout << "*****************\n";
    cout << "*   x   |   y   *\n";
    cout << "*****************\n";
    for (double i = -5, j = 1 / i; i <= 5; ++i) {
        cout << fixed << setprecision(3) << "|";
        (i < 0) ? cout << i << "\t|" << j << "\t|\n"
            : cout << " " << i << "\t|" << j << "\t|\n";
    }
    cout << "*****************\n";
    for (int i = 0; i < 300; ++i)
        Line(hDc, 200, i, 650, i);
    color = RGB(0, 0, 0);
    for (double x1 = 0; x1 < 280; x1 += 0.001)
        SetPixel(hDc, 400, 10 + x1, color);
    for (double x1 = 0; x1 < 300; x1 += 0.001)
        SetPixel(hDc, 250 + x1, 150, color);
    for (double x1 = -30; x1 < 5; x1 += 0.001) {
        int y1 = sin(x1) * 50;
        SetPixel(hDc, x1 * 5 + x + 63, y - y1, color);
    }
    system("pause >> 0");
    return 0;
}