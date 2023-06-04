#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cassert>
class Pyramid {
private:
    double baseLength;   // ������� ������ ������
    double baseWidth;    // ������ ������ ������
    double height;       // ������ ������
public:
    // ����������� �� �������������
    Pyramid() {
        baseLength = 0.0;
        baseWidth = 0.0;
        height = 0.0;
    }

    // ����������� � �����������
    Pyramid(double bl, double bw, double h) {
        setBaseLength(bl);
        setBaseWidth(bw);
        setHeight(h);
    }

    // ������ ������� �� ��������
    double getBaseLength() const {
        return baseLength;
    }

    double getBaseWidth() const {
        return baseWidth;
    }

    double getHeight() const {
        return height;
    }

    void setBaseLength(double bl) {
        if (bl > 0) {
            baseLength = bl;
        } else {
            throw std::invalid_argument("Base length must be positive");
        }
    }

    void setBaseWidth(double bw) {
        if (bw > 0) {
            baseWidth = bw;
        } else {
            throw std::invalid_argument("Base width must be positive");
        }
    }

    void setHeight(double h) {
        if (h > 0) {
            height = h;
        } else {
            throw std::invalid_argument("Height must be positive");
        }
    }

    // ����� ��� ���������� ��'��� ������
    double getVolume() const {
        double area = baseLength * baseWidth;
        double volume = (1.0 / 3.0) * area * height;
        return volume;
    }

    // ����� ��� ���� ������� ������ ������
    void changeBaseLength(double bl) {
        setBaseLength(bl);
    }

    // ����� ��� ���� ������ ������ ������
    void changeBaseWidth(double bw) {
        setBaseWidth(bw);
    }

    // ����� ��� ���� ������ ������
    void changeHeight(double h) {
        setHeight(h);
    }
};



int main() {
    bool all_tests_passed = true;

    // ���� 1: ��������� ������ � ��������� ��������
    Pyramid p1;
    if (p1.getBaseLength() == 0.0 && p1.getBaseWidth() == 0.0 && p1.getHeight() == 0.0 && p1.getVolume() == 0.0) {
        std::cout << "Test 1 passed\n";
    } else {
        std::cout << "Test 1 failed\n";
        all_tests_passed = false;
    }

    // ���� 2: ��������� ������ � ����������� ��������
    Pyramid p2(4.0, 3.0, 5.0);
    if (p2.getBaseLength() == 4.0 && p2.getBaseWidth() == 3.0 && p2.getHeight() == 5.0 && p2.getVolume() == 20.0) {
        std::cout << "Test 2 passed\n";
    } else {
        std::cout << "Test 2 failed\n";
        all_tests_passed = false;
    }

    // ���� 3: ���� ������ ������
    p2.changeBaseLength(6.0);
    if (p2.getBaseLength() == 6.0 && p2.getVolume() == 30.0) {
        std::cout << "Test 3 passed\n";
    } else {
        std::cout << "Test 3 failed\n";
        all_tests_passed = false;
    }

    // ���� 4: ���������� ���� �� ����������
    bool exception_thrown = false;
    try {
        Pyramid p3(-1.0, 3.0, 5.0);
    } catch (std::invalid_argument& e) {
        exception_thrown = true;
    }
    if (exception_thrown) {
        std::cout << "Test 4 passed\n";
    } else {
        std::cout << "Test 4 failed\n";
        all_tests_passed = false;
    }

    if (all_tests_passed) {
        std::cout << "All tests passed\n";
    } else {
        std::cout << "Some tests failed\n";
    }

    return 0;
}


