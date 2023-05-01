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
    output_file << "����� �.�." << endl;
    output_file << "���� ������������� ������" << endl;
    output_file << "2023" << endl;
    output_file.close();
}

//������� ��� �������� � ���� output.txt �-���� ������� ������ � ����� input.txt
int abzac() {
    ifstream input("input.txt"); // �������� ����� ��� ����������
    ofstream output("output.txt"); // �������� ����� ��� ������

    string line; // ����� ��� ��������� ����� � �����
    int count = 0; // �������� �������

    // ���� ����� ������� ����� � �����
    while (getline(input, line)) {
        // ���� ����� �������, �� �� ����� �����
        if (line.empty()) {
            count++;
        }
    }

    // ���� ������� ����� �� ���������� ������� ������, �� ������ ���� �� ���������
    if (!line.empty()) {
        count++;
    }

    // ��������� ���������� �� �����
    output << "ʳ������ ������� � �����: " << count << endl;

    // �������� �����
    input.close();
    output.close();

    return 0;
}


//������� ��� �������� � ���� output.txt � ����� ���� ����� ... ��� �������� � ����� � ����� ...
int check_word() {
    ifstream input_file("input.txt");
    ofstream output_file("output.txt");
    string line;
    bool has_ukraine = false;
    bool has_university = false;

    regex ukraine_regex("�����[�-����]*");
    regex university_regex("����������[����]*");

    while (getline(input_file, line)) {
        if (regex_search(line, ukraine_regex)) {
            has_ukraine = true;
        }
        if (regex_search(line, university_regex)) {
            has_university = true;
        }
    }

    if (has_ukraine) {
        output_file << "� ����� � ����� '������'" << endl;
    } else {
        output_file << "� ����� ���� ����� '������'" << endl;
    }

    if (has_university) {
        output_file << "� ����� � ����� '����������'" << endl;
    } else {
        output_file << "� ����� ���� ����� '����������'" << endl;
    }

    return 0;
}


//������� ��� �������� �� ����� input.txt �-���� ������ � ����� ����,���� �� ��� �������� ����������
void append_info_to_file() {
    // ��������� ���� ��� �������
    std::ifstream input_file("input.txt");

    // ������ ������� ������
    int num_dots = 0;
    char c;
    while (input_file.get(c)) {
        if (c == '.') {
            num_dots++;
        }
    }

    // ��������� ���� ��� ������
    std::ofstream output_file("input.txt", std::ios::app);

    // �������� ������� ������
    output_file << "ʳ������ ������ � ����: " << num_dots << std::endl;

    // �������� ������� ���� �� ���
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    // �������� ���� �� ��� �������� ����������
    output_file << "���� �� ��� �������� ����������: " << std::ctime(&now_c) << std::endl;

    // ��������� �����
    input_file.close();
    output_file.close();
}


//������� s_calculation
float s_calculation(float x,float y,float z){
    float s = abs(sin(abs(y - pow(z,2))) + sqrt(x) - sqrt(pow(y*z,x) + y/2*pi));
    return s;
}

//������� ��� ������ � ���� output.txt ��������� ������� s_calculation �� ����� b � ��������� ���
int function_3() {
    float x, y, z;
    int b;

    // ���������� ������� ����� � �����
    ifstream input_file("input.txt");
    input_file >> x >> y >> z >> b;
    input_file.close();

    // ���������� �������� s
    float s = s_calculation(x, y, z);

    // ����� ���������� � ���� output.txt
    ofstream output_file("output.txt", ios_base::app);
    output_file << "�������� s: " << s << endl;
    output_file << "����� b � ������� ������: " << bitset<8>(b) << endl;
    output_file.close();

    return 0;
}

