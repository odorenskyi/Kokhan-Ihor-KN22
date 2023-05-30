#include "KovalovModules.h"

#include <algorithm>

// ������ ������ ���������
void addOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators) {
    operators.push_back(Operator{name, code});
}

// �������� ���������
void removeOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators) {
    operators.erase(std::remove_if(operators.begin(), operators.end(), [&](const Operator& op) {
        return op.name == name && op.code == code;
    }), operators.end());
}
