#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 21;
const int MAX_GENERATIONS = 100;
const char MICROBE_CHAR = 'X';

void printGeneration(int generation, int field[SIZE][SIZE]) {
    cout << "Поколение " << generation << ":\n";
    for (int i = 1; i < SIZE - 1; ++i) {
        for (int j = 1; j < SIZE - 1; ++j) {
            cout << (field[i][j] == 1 ? MICROBE_CHAR : ' ');
        }
        cout << "\n";
    }
    cout << "\n";
}

void createInitialGeneration(int field[SIZE][SIZE]) {
    ifstream input("work.dat");
    if (input) {
        for (int i = 1; i < SIZE - 1; ++i) {
            for (int j = 1; j < SIZE - 1; ++j) {
                char ch;
                input >> ch;
                if (ch == MICROBE_CHAR) {
                    field[i][j] = 1;
                }
                else {
                    field[i][j] = 0;
                }
            }
        }
        input.close();
    }
    else {
        srand(time(nullptr));
        for (int i = 1; i < SIZE - 1; ++i) {
            for (int j = 1; j < SIZE - 1; ++j) {
                field[i][j] = rand() % 2;
            }
        }
    }
}

void updateGeneration(int currentGeneration[SIZE][SIZE], int nextGeneration[SIZE][SIZE]) {
    for (int i = 1; i < SIZE - 1; ++i) {
        for (int j = 1; j < SIZE - 1; ++j) {
            int neighbors = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    neighbors += currentGeneration[i + x][j + y];
                }
            }
            neighbors -= currentGeneration[i][j];
            if (currentGeneration[i][j] == 1) {
                if (neighbors == 2 || neighbors == 3) {
                    nextGeneration[i][j] = 1;
                }
                else {
                    nextGeneration[i][j] = 0;
                }
            }
            else {
                if (neighbors == 3) {
                    nextGeneration[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    int currentGeneration[SIZE][SIZE] = { 0 };
    int nextGeneration[SIZE][SIZE] = { 0 };
    int generations;
    setlocale(LC_ALL, "RUS");
    cout << "Введите количество поколений: ";
    cin >> generations;

    createInitialGeneration(currentGeneration);

    for (int generation = 1; generation <= generations; ++generation) {
        printGeneration(generation, currentGeneration);
        updateGeneration(currentGeneration, nextGeneration);
        swap(currentGeneration, nextGeneration);
    }

    cout << "Все поколения завершены. Программа завершена." << endl;

    return 0;
}
