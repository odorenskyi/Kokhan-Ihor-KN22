#include <iostream>
#include <fstream>
#include <string>
#include <ModulesKohan.h>
using namespace std;

void write_info() {
    ofstream output_file("output.txt");
    output_file << "����� �.�." << endl;
    output_file << "���� ������������� ������" << endl;
    output_file << "2023" << endl;
    output_file.close();
}

int main() {
    // ��������� �������, ��� ������ ���������� � ����
    write_info();

    // ��������� ���� �� �������
    ifstream input_file("output.txt");
    string line;
    bool is_valid = true;

    // ����������, �� �������� ���������� ����
    if (getline(input_file, line) && line != "����� �.�.") {
        is_valid = false;
    }
    if (getline(input_file, line) && line != "���� ������������� ������") {
        is_valid = false;
    }
    if (getline(input_file, line) && line != "2023") {
        is_valid = false;
    }

    // ���� ���� � ���� ����� �� ������� ����������� ��������, �� ���� �� ��������
    if (!is_valid) {
        cout << "Test False!" << endl;
        return 1;
    }

    cout << "Test Passed!" << endl;
    return 0;
}

