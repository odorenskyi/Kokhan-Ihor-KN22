#include <iostream>
#include <fstream>
#include "ModulesKohan.h"
using namespace std;

// ������� ��� ���������� abzac() �� �������������� ����������
void test_abzac(int x, int b) {
    // ³�������� ����� ��� ���������� �� ������
    ifstream input("input.txt");
    ofstream output("output.txt", ios::app); // ������ �� ���� �����

    // �������� ����� ��� �� ��������� �����
    output << "������� ������� abzac() � ���������� �������� ������:\n"
           << "x = " << x << ", b = " << b << endl;

    // �������� ����-����
    int result = abzac();

    // ����������, �� ������� ����-����
    bool passed = (result == 0);

    // �������� ��������� ����-����� �� ���� ������ �� ��������� �����
    output << "��������� ����������: " << result << endl;
    output << "������ ����-�����: " << (passed ? "passed" : "failed") << endl;

    // ��������� �����
    input.close();
    output.close();
}

int main() {
    // ������� ������� ������� ��� ���������� � �������� ������
    test_abzac(8, 7);

    return 0;
}
