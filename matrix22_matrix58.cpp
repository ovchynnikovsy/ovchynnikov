
#include <iostream>
using namespace std;

const int M = 20, N = 20;

// Ввод матрицы
void inputMatrix(int matr[M][N], int &rows, int &cols) {
    do {
        cout << "Введите количество строк (2-20): ";
        cin >> rows;
        cout << "Введите количество столбцов (2-20): ";
        cin >> cols;
    } while (rows < 2 || rows > 20 || cols < 2 || cols > 20);

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matr[i][j];
}

// Вывод матрицы
void outputMatrix(int matr[M][N], int rows, int cols) {
    cout << "\nМатрица:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matr[i][j] << "\t";
        cout << endl;
    }
}

// Задача Matrix22
void solveMatrix22(int matr[M][N], int rows, int cols) {
    cout << "\nСуммы элементов чётных столбцов (2, 4, ...):\n";
    for (int j = 1; j < cols; j += 2) {
        int sum = 0;
        for (int i = 0; i < rows; ++i)
            sum += matr[i][j];
        cout << "Столбец " << j + 1 << ": сумма = " << sum << endl;
    }
}

// Задача Matrix58
void solveMatrix58(int matr[M][N], int rows, int cols) {
    for (int i = rows / 2; i < rows; ++i)
        for (int j = 0; j < cols / 2; ++j)
            swap(matr[i][j], matr[i - rows / 2][j + cols / 2]);

    cout << "\nМатрица после замены четвертей:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << matr[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int matr[M][N], rows, cols;
    int choice;

    do {
        cout << "\nМеню:\n1 – Matrix22\n2 – Matrix58\n0 – Выход\nВыбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputMatrix(matr, rows, cols);
                outputMatrix(matr, rows, cols);
                solveMatrix22(matr, rows, cols);
                break;
            case 2:
                do {
                    cout << "Введите чётное количество строк и столбцов (2-20):\n";
                    cout << "Строки: "; cin >> rows;
                    cout << "Столбцы: "; cin >> cols;
                } while (rows % 2 != 0 || cols % 2 != 0 || rows < 2 || cols < 2 || rows > 20 || cols > 20);

                inputMatrix(matr, rows, cols);
                solveMatrix58(matr, rows, cols);
                break;
        }
    } while (choice != 0);

    return 0;
}
