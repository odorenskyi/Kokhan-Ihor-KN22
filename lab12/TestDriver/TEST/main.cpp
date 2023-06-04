#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cassert>
class Pyramid {
private:
    double baseLength;   // довжина основи піраміди
    double baseWidth;    // ширина основи піраміди
    double height;       // висота піраміди
public:
    // конструктор за замовчуванням
    Pyramid() {
        baseLength = 0.0;
        baseWidth = 0.0;
        height = 0.0;
    }

    // конструктор з параметрами
    Pyramid(double bl, double bw, double h) {
        setBaseLength(bl);
        setBaseWidth(bw);
        setHeight(h);
    }

    // методи доступу до атрибутів
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

    // метод для обчислення об'єму піраміди
    double getVolume() const {
        double area = baseLength * baseWidth;
        double volume = (1.0 / 3.0) * area * height;
        return volume;
    }

    // метод для зміни довжини основи піраміди
    void changeBaseLength(double bl) {
        setBaseLength(bl);
    }

    // метод для зміни ширини основи піраміди
    void changeBaseWidth(double bw) {
        setBaseWidth(bw);
    }

    // метод для зміни висоти піраміди
    void changeHeight(double h) {
        setHeight(h);
    }
};



int main() {
    bool all_tests_passed = true;

    // тест 1: створення піраміди з нульовими розмірами
    Pyramid p1;
    if (p1.getBaseLength() == 0.0 && p1.getBaseWidth() == 0.0 && p1.getHeight() == 0.0 && p1.getVolume() == 0.0) {
        std::cout << "Test 1 passed\n";
    } else {
        std::cout << "Test 1 failed\n";
        all_tests_passed = false;
    }

    // тест 2: створення піраміди з ненульовими розмірами
    Pyramid p2(4.0, 3.0, 5.0);
    if (p2.getBaseLength() == 4.0 && p2.getBaseWidth() == 3.0 && p2.getHeight() == 5.0 && p2.getVolume() == 20.0) {
        std::cout << "Test 2 passed\n";
    } else {
        std::cout << "Test 2 failed\n";
        all_tests_passed = false;
    }

    // тест 3: зміна розмірів піраміди
    p2.changeBaseLength(6.0);
    if (p2.getBaseLength() == 6.0 && p2.getVolume() == 30.0) {
        std::cout << "Test 3 passed\n";
    } else {
        std::cout << "Test 3 failed\n";
        all_tests_passed = false;
    }

    // тест 4: негативний тест на виключення
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


