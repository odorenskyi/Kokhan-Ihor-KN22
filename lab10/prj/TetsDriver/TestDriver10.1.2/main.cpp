#include <iostream>
#include <fstream>
#include "ModulesKohan.h"
using namespace std;

// Функція для тестування abzac() та протоколювання результату
void test_abzac(int x, int b) {
    // Відкриваємо файли для зчитування та запису
    ifstream input("input.txt");
    ofstream output("output.txt", ios::app); // Додаємо до кінця файлу

    // Записуємо вхідні дані до вихідного файлу
    output << "Тестуємо функцію abzac() з наступними вхідними даними:\n"
           << "x = " << x << ", b = " << b << endl;

    // Виконуємо тест-кейс
    int result = abzac();

    // Перевіряємо, чи пройшов тест-кейс
    bool passed = (result == 0);

    // Записуємо результат тест-кейсу та його статус до вихідного файлу
    output << "Результат тестування: " << result << endl;
    output << "Статус тест-кейсу: " << (passed ? "passed" : "failed") << endl;

    // Закриваємо файли
    input.close();
    output.close();
}

int main() {
    // Приклад виклику функції для тестування зі вхідними даними
    test_abzac(8, 7);

    return 0;
}
