#include <iostream>
#include <cmath> // Для використання функції abs
using namespace std;

int main()
{
    // Оголошення змінних
    double V1, V2, S, T, distance;

    // Введення даних від користувача
    cout << "Введіть швидкість першого автомобіля (V1) км/год: ";
    cin >> V1;
    cout << "Введіть швидкість другого автомобіля (V2) км/год: ";
    cin >> V2;
    cout << "Введіть початкову відстань між автомобілями (S) км: ";
    cin >> S;
    cout << "Введіть час руху (T) годин: ";
    cin >> T;

    // Обчислення сумарної швидкості
    double V_total = V1 + V2;

    // Розрахунок загального шляху
    double total_distance = V_total * T;

    // Визначення відстані між автомобілями
    distance = abs(S - total_distance);

    // Виведення результату
    cout << "Відстань між автомобілями через " << T << " годин: " << distance << " км" << endl;

    return 0; // Завершення програми
}
