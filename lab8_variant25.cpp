
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int N = 100;
const int M = 20;

// ====== ЗАДАНИЕ 1 ======
// Чтение символьного массива из файла
void get_mas(const string& filename, char arr[N], int &n) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Ошибка при открытии файла ввода!" << endl;
        return;
    }
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }
    fin.close();
}

// Запись массива в файл
void show_mas(const string& filename, const char arr[N], int n) {
    ofstream fout(filename, ios::app);
    fout << "Отсортированный массив:\n";
    for (int i = 0; i < n; ++i)
        fout << arr[i] << " ";
    fout << "\n";
    fout.close();
}

// ====== ЗАДАНИЕ 3 ======
// Шейкерная сортировка по возрастанию (символьный массив)
void shaker_sort(char arr[N], int n) {
    int left = 0, right = n - 1;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        --right;
        for (int i = right; i > left; --i) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++left;
    }
}

int main() {
    char arr[N];
    int n;
    string inputFile, outputFile;

    cout << "Введите имя входного файла: ";
    cin >> inputFile;
    cout << "Введите имя выходного файла: ";
    cin >> outputFile;

    // Чтение массива из файла
    get_mas(inputFile, arr, n);

    // Сортировка массива
    shaker_sort(arr, n);

    // Вывод результата в файл
    show_mas(outputFile, arr, n);

    cout << "Сортировка завершена. Результат записан в " << outputFile << endl;
    return 0;
}
