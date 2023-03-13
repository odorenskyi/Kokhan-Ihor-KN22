#include <iostream>
#include <clocale>
#include "ModulesKohan.h"

using namespace std;

string copyright() {
    return "(c) Кохан Iгор";
}

bool expression(char a, char b) {
    return  a + 7 == b;
}

string DecHexSFunc(int x, int y, int z) {
    cout << "В десятковiй: " << endl
         << "'x' -> " << dec << x << endl
         << "'y' -> " << dec << y << endl
         << "'z' -> " << dec << z << endl << endl;
    cout << "В шiстнадцятковiй: " << endl
         << "'x' -> " << hex << x << endl
         << "'y' -> " << hex << y << endl
         << "'z' -> " << hex << z << endl << endl;
    cout << endl << "Результат обчислення виразу: S = " << s_calculation(x, y, z) << endl;
    return "";
}


int main() {
    setlocale(LC_ALL, "ukr");
    cout << copyright() << endl << endl;

    int x, y, z;
    char a, b;

    cout << "Введiть x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введiть символи 'a' та 'b': ";
    cin >> a >> b;

    cout << "Результат виразу: a + 7 = b -> " << expression(a, b) << endl << endl;
    cout << DecHexSFunc(x, y, z);
    return 0;
}

