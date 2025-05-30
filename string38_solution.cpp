
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ======= 1.A =======
// Метод string::replace(pos, len, str) заменяет подстроку длины len с позиции pos на строку str

// ======= 1.B =======
// Собственная реализация замены всех вхождений подстроки s1 в строке s на подстроку s2
void replaceAllCustom(char s[], const char s1[], const char s2[]) {
    string result, source = s, find = s1, replace = s2;
    size_t pos = 0, found;
    while ((found = source.find(find, pos)) != string::npos) {
        result.append(source.substr(pos, found - pos));
        result.append(replace);
        pos = found + find.length();
    }
    result.append(source.substr(pos));
    strcpy(s, result.c_str()); // обновляем исходную строку
}

// ======= 2.A =======
// Реализация через string
string replaceAllSTD(string s, string s1, string s2) {
    size_t pos = 0;
    while ((pos = s.find(s1, pos)) != string::npos) {
        s.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
    return s;
}

// ======= main =======
int main() {
    char s[1000];
    string s1, s2;

    cout << "Введите строку S: ";
    cin.getline(s, 1000);

    cout << "Введите подстроку S1 для замены: ";
    getline(cin, s1);

    cout << "Введите подстроку S2 на которую заменяем: ";
    getline(cin, s2);

    // Вариант с std::string
    string std_result = replaceAllSTD(s, s1, s2);
    cout << "Результат с std::string: " << std_result << endl;

    // Вариант с char[] (без string)
    replaceAllCustom(s, s1.c_str(), s2.c_str());
    cout << "Результат с собственной функцией: " << s << endl;

    return 0;
}
