#include <iostream>
#include <cmath>
using namespace std;

// Задача 1: Проверка попадания точек в фигуру (34 вар)
bool isInFigure(double x, double y, double r) {
    bool inQuarterCircle = (x >= 0 && y >= 0 && (x*x + y*y <= r*r)); // четверть круга
    bool inTriangle = (x >= 0 && y <= 0 && y >= -x); // треугольник
    return inQuarterCircle || inTriangle;
}

void task1() {
    int n; 
    double x, y, r;
    cout << "Введите количество точек: "; cin >> n;
    cout << "Введите радиус круга r: "; cin >> r;

    int count = 0;
    for (int i = 0; i < n; i++) {
        cout << "Введите координаты x и y для точки " << i+1 << ": ";
        cin >> x >> y;
        if (isInFigure(x, y, r)) {
            count++;
        }
    }
    cout << "Количество точек, попадающих в фигуру: " << count << endl;
}

// Задача 2: Вычисление суммы ряда (10 вар)
void task2() {
    int n;
    double x, sum = 0.0;

    cout << "Введите значение x (|x| < 4): "; cin >> x;
    cout << "Введите количество членов ряда n: "; cin >> n;

    if (abs(x) >= 4) {
        cout << "Ошибка: |x| должно быть меньше 4" << endl;
        return;
    }

    for (int i = 0; i <= n; i++) {
        sum += pow(x, i + 2) / (pow(5, i) + i);
    }

    cout << "Сумма ряда S = " << sum << endl;
}

// Задача 3: Вычисление суммы ряда с факториалом (30 вар)
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

void task3() {
    int n_max;
    double x, sum = 0.0;

    cout << "Введите значение x: "; cin >> x;
    cout << "Введите количество членов ряда n: "; cin >> n_max;

    for (int n = 1; n <= n_max; n++) {
        double term = pow(x, n) * factorial(n) / pow(n, n / 2.0);
        sum += term;
    }

    cout << "Сумма ряда: " << sum << endl;
}

// Главное меню программы
int main() {
    int choice;

    do {
        cout << "\nВыберите задачу для выполнения:\n";
        cout << "1. Проверка точек на попадание в фигуру (34 вар)\n";
        cout << "2. Вычисление суммы ряда (10 вар)\n";
        cout << "3. Вычисление суммы ряда с факториалом (30 вар)\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Выход из программы. До свидания!\n"; break;
            default: cout << "Ошибка: неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
