#include <iostream>
#include <fstream>
#include <regex>
#include <ModulesKohan.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    check_word();
    ofstream input_file("input.txt");
    input_file << "ЦНТУ знаходиться в місті Кропивницький, Україна." << endl;
    input_file << "Університет має багато факультетів." << endl;
    input_file.close();

    check_word();

    ifstream output_file("output.txt");
    string line;
    while (getline(output_file, line)) {
        cout << line << endl;
    }
    output_file.close();

    return 0;
}
