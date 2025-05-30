
#include <iostream>
using namespace std;

struct TDate {
    int Day;
    int Month;
    int Year;
};

// Проверка високосного года
bool IsLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Возвращает количество дней в месяце
int DaysInMonth(int month, int year) {
    if (month < 1 || month > 12) return 0;
    int days[] = { 31, 28 + IsLeapYear(year), 31, 30, 31, 30,
                   31, 31, 30, 31, 30, 31 };
    return days[month - 1];
}

// Проверка корректности даты
int CheckDate(TDate D) {
    if (D.Month < 1 || D.Month > 12)
        return 1; // неверный месяц
    if (D.Day < 1 || D.Day > DaysInMonth(D.Month, D.Year))
        return 2; // неверный день
    return 0; // дата корректна
}

void PrintCheckResult(int result) {
    switch (result) {
        case 0: cout << "Дата корректна\n"; break;
        case 1: cout << "Неверный номер месяца\n"; break;
        case 2: cout << "Неверный день для месяца\n"; break;
        default: cout << "Неизвестная ошибка\n";
    }
}

int main() {
    TDate dates[5] = {
        {29, 2, 2024},   // корректная (високосный год)
        {31, 4, 2023},   // неверный день (в апреле 30 дней)
        {15, 13, 2022},  // неверный месяц
        {30, 6, 2021},   // корректная
        {0, 12, 2020}    // неверный день
    };

    for (int i = 0; i < 5; ++i) {
        cout << "Проверка даты: " << dates[i].Day << "." << dates[i].Month << "." << dates[i].Year << " => ";
        int result = CheckDate(dates[i]);
        PrintCheckResult(result);
    }

    return 0;
}
