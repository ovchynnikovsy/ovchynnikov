#include <iostream>
#include <cmath> // для функции pow
using namespace std;

// Задача if16: Удвоение или изменение знака переменных A, B, C в зависимости от условий
void task_if16() {
    float A, B, C;
    cout << "********** Задача if16 **********" << endl;
    cout << "Введите значения A, B и C: ";
    cin >> A >> B >> C;

    if (A < B && B < C) {
        // Если значения упорядочены по возрастанию
        A *= 2;
        B *= 2;
        C *= 2;
        cout << "Значения удвоены: A = " << A << ", B = " << B << ", C = " << C << endl;
    }
    else {
        // Если не по возрастанию, меняем знаки
        A = -A;
        B = -B;
        C = -C;
        cout << "Значения заменены на противоположные: A = " << A << ", B = " << B << ", C = " << C << endl;
    }
}

// Задача 34: Проверка попадания точки в сложную область (окружность и треугольники)
void task_34_variant() {
    float x, y, r;
    cout << "********** Задача 34 вариант **********" << endl;
    cout << "Введите радиус r: ";
    cin >> r;

    if (r <= 0) {
        cout << "Радиус должен быть положительным числом!" << endl;
        return;
    }

    cout << "Введите координаты точки (x, y): ";
    cin >> x >> y;

    bool in_circle = (x * x + y * y <= r * r) && (x >= 0) && (y >= 0); // точка в правом верхнем круге
    bool in_triangle1 = (x >= 0 && y >= 0 && y <= -x + r); // правый верхний треугольник
    bool in_triangle2 = (x <= 0 && y >= 0 && y <= x + r);  // левый верхний треугольник
    bool in_triangle3 = (x <= 0 && y <= 0 && y >= x - r);  // левый нижний треугольник
    bool in_triangle4 = (x >= 0 && y <= 0 && y >= -x - r); // правый нижний треугольник

    if (in_circle || in_triangle1 || in_triangle2 || in_triangle3 || in_triangle4) {
        cout << "Точка находится в заданной области!" << endl;
    }
    else {
        cout << "Точка находится вне заданной области!" << endl;
    }
}

int main() {
    int menu;
    cout << "Введите номер задачи (1 для if16, 2 для 34 варианта): ";
    cin >> menu;

    switch (menu) {
    case 1:
        task_if16();
        break;
    case 2:
        task_34_variant();
        break;
    default:
        cout << "Неверный номер задачи! Введите 1 или 2." << endl;
        break;
    }

    return 0;
}
