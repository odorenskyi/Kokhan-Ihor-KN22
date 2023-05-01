#include <iostream>
#include <fstream>
#include <string>
#include <ModulesKohan.h>
using namespace std;

void write_info() {
    ofstream output_file("output.txt");
    output_file << "Кохан І.О." << endl;
    output_file << "ЦНТУ Кропивницький Україна" << endl;
    output_file << "2023" << endl;
    output_file.close();
}

int main() {
    // викликаємо функцію, яка записує інформацію у файл
    write_info();

    // відкриваємо файл на читання
    ifstream input_file("output.txt");
    string line;
    bool is_valid = true;

    // перевіряємо, чи записана інформація вірно
    if (getline(input_file, line) && line != "Кохан І.О.") {
        is_valid = false;
    }
    if (getline(input_file, line) && line != "ЦНТУ Кропивницький Україна") {
        is_valid = false;
    }
    if (getline(input_file, line) && line != "2023") {
        is_valid = false;
    }

    // якщо хоча б один рядок не відповідає очікуваному значенню, то тест не пройдено
    if (!is_valid) {
        cout << "Test False!" << endl;
        return 1;
    }

    cout << "Test Passed!" << endl;
    return 0;
}

