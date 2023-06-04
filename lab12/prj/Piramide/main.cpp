#include <iostream>
#include <stdexcept>
#include <cmath>

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
    Pyramid p(5.0, 2.0, 6.0);
    std::cout << "Base length: " << p.getBaseLength() << std::endl;
    std::cout << "Base width: " << p.getBaseWidth() << std::endl;
    std::cout << "Height: " << p.getHeight() << std::endl;
    std::cout << "Volume: " << p.getVolume() << std::endl;

    // ���� ������� ������ ������
    try {
        p.changeBaseLength(6.0);
        std::cout << "New base length: " << p.getBaseLength() << std::endl;
        std::cout << "New volume: " << p.getVolume() << std::endl;
    } catch (std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
