#include <iostream>
#include <string>
#include <cctype> //для проверки

using namespace std;

//задание 1
string removeCharAtIndex(const string& str, size_t index) {
    if (index >= str.length()) {
        return str;
    }
    string result = str;
    result.erase(index, 1);
    return result;
}

//задание 2
string removeAllChars(const string& str, char ch) {
    string result = str;
    size_t pos = 0;
    while ((pos = result.find(ch, pos)) != string::npos) {
        result.erase(pos, 1);
    }
    return result;
}

//Задание 3
string insertCharAtIndex(const string& str, size_t index, char ch) {
    if (index > str.length()) {
        return str;
    }
    string result = str;
    result.insert(index, 1, ch);
    return result;
}

//задание 4
string replaceDotsWithExclamation(const string& str) {
    string result = str;
    size_t pos = 0;
    while ((pos = result.find('.', pos)) != string::npos) {
        result.replace(pos, 1, "!");
        pos += 1;
    }
    return result;
}

//задание 5
int countCharOccurrences(const string& str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) {
            count++;
        }
    }
    return count;
}

//задание 6
void countCharacters(const string& str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    for (char c : str) {
        if (isalpha(c)) {
            letters++;
        }
        else if (isdigit(c)) {
            digits++;
        }
        else {
            others++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    // Задание 1
    string str1 = "Hello, World!";
    cout << "1.Удаление символа с индексом 5" << endl;
    cout << "Исходная строка: " << str1 << endl;
    cout << "Результат: " << removeCharAtIndex(str1, 5) << endl << endl;

    // Задание 2
    string str2 = "Hello, World!";
    cout << "2. Удаление всех символов 'l'" << endl;
    cout << "Исходная строка: " << str2 << endl;
    cout << "Результат: " << removeAllChars(str2, 'l') << endl << endl;

    // Задание 3
    string str3 = "Hello World!";
    cout << "3. Вставка символа ',' на позицию 5" << endl;
    cout << "Исходная строка: " << str3 << endl;
    cout << "Результат: " << insertCharAtIndex(str3, 5, ',') << endl << endl;

    //задание 4
    string str4;
    cout << "4. Замена точек на восклицательные знаки" << endl;
    cout << "Введите строку с точками: ";
    getline(cin, str4);
    cout << "Результат: " << replaceDotsWithExclamation(str4) << endl << endl;

    //задание 5
    string str5;
    char searchChar;
    cout << "Задание 5: Подсчет вхождений символа" << endl;
    cout << "Введите строку: ";
    getline(cin, str5);
    cout << "Введите символ для поиска: ";
    cin >> searchChar;
    cin.ignore();
    cout << "Символ '" << searchChar << "' встречается "
        << countCharOccurrences(str5, searchChar) << " раз(а)" << endl << endl;

    //задание 6
    string str6;
    cout << "Задание 6: Подсчет букв, цифр и других символов" << endl;
    cout << "Введите строку: ";
    getline(cin, str6);

    int letters, digits, others;
    countCharacters(str6, letters, digits, others);

    cout << "Буквы: " << letters << endl;
    cout << "Цифры: " << digits << endl;
    cout << "Другие символы: " << others << endl;

    return 0;
}