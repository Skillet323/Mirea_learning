#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height =20;
int arr[40];
int x, y, fX, fY, score;
int N = 200;
int tailX[100], tailY[100];
int nTail=0;
enum direc{ Stop = 0, L,R,U,D };
direc dir;
void Setup() {
	gameOver = false;
	dir = Stop;
	x = width / 2-1;
	y = height / 2-1;
	fX = rand() % width;
	fY = rand() % height;
	score = 0;
}
int Draw() {
	system("cls");
	for (int i = 0; i < width+1;i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((j == 0) or (j==width-1) ) {
				cout << "#";
			}
			if (i == y and j == x) {
				cout << "0";
			}
			else if (i == fY and j == fX) {
				cout << "A";
			}
			else { 
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j and tailY[k] == i) {
						print = true;
						cout << "o";
					}
				}
				if (!print) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width+1; i++) {
		cout << "#";
	}
	cout << endl;
	cout << "Ñ÷¸ò: " << score;
	if (score == 4000) {
		system("cls");
		return 1;
	}
	return 0;
}
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': case 'A': case 'ô': case 'Ô':
			dir = L;
			break;
		case 's': case 'S': case 'û': case 'Û':
			dir = D;
			break;
		case 'd': case 'D': case 'â': case 'Â':
			dir = R;
			break;
		case 'w': case 'W': case 'ö': case 'Ö':
			dir = U;
			break;
		case 'x': case 'X': case '÷': case '×':
			gameOver = true;
			break;
		}
	}
}
void Logic() {
	int pX = tailX[0];
	int pY = tailY[0];
	int p2X, p2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++) {
		p2X = tailX[i];
		p2Y = tailY[i];
		tailX[i] = pX;
		tailY[i] = pY;
		pX = p2X;
		pY = p2Y;
	}
	switch (dir) {
	case L:
		x -= 1;
		break;
	case R:
		x += 1;
		break;
	case U:
		y -= 1;
		break;
	case D:
		y += 1;
		break;
	}
	if (x >= width-1) {
		x = 0;
	}
	else if (x < 0) {
		x = width - 2;
	}
	if (y >= height) {
		y = 0;
	}
	else if (y < 0) {
		y = height - 1;
	}
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x and tailY[i] == y) {
			gameOver = true;
		}
	}
	if (x == fX and y == fY) {
		score += 10;
		fX = rand() % width;
		fY = rand() % height;
		nTail++;
	}
}
int main() {
	setlocale(LC_ALL, "RUS");
	for (int i = 0; i < (N / 5); i++) {
		arr[i] = N - (2 * (i + 1));
	}
	N = arr[score % 100];
	Setup();
	while (!gameOver) {
		if (Draw() == 1) {
			cout << "ÝÒÎ ÏÎÁÅÄÀ! \n";
			break;
		}
		Input();
		Logic(); 
		Sleep(N); 
	}
	return 0;
}