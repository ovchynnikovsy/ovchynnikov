#include <iostream>
#include <cmath>
using namespace std;

// --- Задача 1: Вычисление периметра прямоугольника ---
double RectP(double x1, double y1, double x2, double y2) {
    // Проверяем диапазон входных данных
    if (x1 < -100 || x1 > 100 || y1 < -100 || y1 > 100 || 
        x2 < -100 || x2 > 100 || y2 < -100 || y2 > 100) {
        cout << "Ошибка: координаты должны быть в диапазоне [-100, 100]!\n";
        return -1; // Возвращаем ошибочное значение
    }
    // Рассчитываем ширину, высоту и периметр
    double width = abs(x2 - x1);
    double height = abs(y2 - y1);
    return 2 * (width + height);
}

// --- Задача 2: Проверка равностороннего треугольника ---
bool isEquilateral(int a, int b, int c) {
    // Проверяем диапазон входных данных
    if (a < -100 || a > 100 || b < -100 || b > 100 || c < -100 || c > 100) {
        cout << "Ошибка: длины сторон должны быть в диапазоне [-100, 100]!\n";
        return false; // Считаем треугольник невалидным
    }
    // Проверяем, равны ли стороны
    return a == b && b == c;
}

// --- Задача 3: Количество полных тонн ---
int fullTons(int M) {
    // Проверяем диапазон входных данных
    if (M < -100 || M > 100) {
        cout << "Ошибка: масса должна быть в диапазоне [-100, 100]!\n";
        return -1; // Возвращаем ошибочное значение
    }
    // Рассчитываем количество тонн
    return M / 1000;
}

int main() {
    int choice;

    do {
        // Главное меню
        cout << "\nВыберите задачу для выполнения:\n";
        cout << "1. Задача 1: Вычислить периметры прямоугольников\n";
        cout << "2. Задача 2: Проверить, является ли треугольник равносторонним\n";
        cout << "3. Задача 3: Вычислить количество полных тонн\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Задача 1: Периметр прямоугольников
                cout << "Введите координаты 3 прямоугольников (x1, y1, x2, y2):\n";
                for (int i = 0; i < 3; i++) {
                    double x1, y1, x2, y2;
                    cout << "Прямоугольник " << i + 1 << ": ";
                    cin >> x1 >> y1 >> x2 >> y2;
                    double perimeter = RectP(x1, y1, x2, y2);
                    if (perimeter != -1) {
                        cout << "Периметр: " << perimeter << endl;
                    }
                }
                break;
            }
            case 2: {
                // Задача 2: Проверка равностороннего треугольника
                int a, b, c;
                cout << "Введите длины сторон треугольника (a, b, c): ";
                cin >> a >> b >> c;
                if (isEquilateral(a, b, c)) {
                    cout << "Треугольник равносторонний\n";
                } else {
                    cout << "Треугольник не равносторонний или некорректные данные\n";
                }
                break;
            }
            case 3: {
                // Задача 3: Количество полных тонн
                int M;
                cout << "Введите массу в килограммах: ";
                cin >> M;
                int tons = fullTons(M);
                if (tons != -1) {
                    cout << "Количество полных тонн: " << tons << endl;
                }
                break;
            }
            case 0:
                // Выход из программы
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Некорректный выбор, попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
