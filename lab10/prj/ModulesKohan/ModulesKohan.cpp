#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "ModulesKohan.h"
#include <chrono>
#include <ctime>
#include <bitset>
#include <cmath>
const double pi = 3.14159;

using namespace std;


void write_info() {
    ofstream output_file("output.txt");
    output_file << "Кохан І.О." << endl;
    output_file << "ЦНТУ Кропивницький Україна" << endl;
    output_file << "2023" << endl;
    output_file.close();
}

//функція яка виводить в файл output.txt к-ість абзаців тексту з файлу input.txt
int abzac() {
    ifstream input("input.txt"); // відкриття файлу для зчитування
    ofstream output("output.txt"); // відкриття файлу для запису

    string line; // змінна для зберігання рядка з файлу
    int count = 0; // лічильник абзаців

    // поки можна зчитати рядок з файлу
    while (getline(input, line)) {
        // якщо рядок порожній, то це новий абзац
        if (line.empty()) {
            count++;
        }
    }

    // якщо останній абзац не закінчується порожнім рядком, то додати його до лічильника
    if (!line.empty()) {
        count++;
    }

    // виведення результату до файлу
    output << "Кількість абзаців у тексті: " << count << endl;

    // закриття файлів
    input.close();
    output.close();

    return 0;
}


//функція яка виводить в файл output.txt У тексті немає слова ... або виводить У тексті є слово ...
int check_word() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    string line;
    bool has_ukraine = false;
    bool has_university = false;

    regex ukraine_regex("Україн[а-яіїє]*");
    regex university_regex("університет[уаоііїє]*");

    while (getline(input_file, line)) {
        if (regex_search(line, ukraine_regex)) {
            has_ukraine = true;
        }
        if (regex_search(line, university_regex)) {
            has_university = true;
        }
    }

    if (has_ukraine) {
        output_file << "У тексті є слово 'Україна'" << endl;
    } else {
        output_file << "У тексті немає слова 'Україна'" << endl;
    }

    if (has_university) {
        output_file << "У тексті є слово 'університет'" << endl;
    } else {
        output_file << "У тексті немає слова 'університет'" << endl;
    }

    return 0;
}


//Функція яка дозаписує до файлу input.txt к-ість крапок в цьому файлі,дату та час дозапису інформації
void append_info_to_file() {
    // відкриваємо файл для читання
    std::ifstream input_file("input.txt");

    // рахуємо кількість крапок
    int num_dots = 0;
    char c;
    while (input_file.get(c)) {
        if (c == '.') {
            num_dots++;
        }
    }

    // відкриваємо файл для запису
    std::ofstream output_file("input.txt", std::ios::app);

    // записуємо кількість крапок
    output_file << "Кількість крапок у файлі: " << num_dots << std::endl;

    // отримуємо поточну дату та час
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    // записуємо дату та час дозапису інформації
    output_file << "Дата та час дозапису інформації: " << std::ctime(&now_c) << std::endl;

    // закриваємо файли
    input_file.close();
    output_file.close();
}


//Функція s_calculation
float s_calculation(float x,float y,float z){
    float s = abs(sin(abs(y - pow(z,2))) + sqrt(x) - sqrt(pow(y*z,x) + y/2*pi));
    return s;
}

//Функція яка записує у файл output.txt результат Функції s_calculation та число b у двійковому коді
int function_3() {
    float x, y, z;
    int b;

    // Зчитування вхідних даних з файлу
    ifstream input_file("input.txt");
    input_file >> x >> y >> z >> b;
    input_file.close();

    // Обчислення значення s
    float s = s_calculation(x, y, z);

    // Запис результатів у файл output.txt
    ofstream output_file("output.txt", ios_base::app);
    output_file << "Значення s: " << s << endl;
    output_file << "Число b у двійковій системі: " << bitset<8>(b) << endl;
    output_file.close();

    return 0;
}

