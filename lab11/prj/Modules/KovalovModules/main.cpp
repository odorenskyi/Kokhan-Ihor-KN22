#include "KovalovModules.h"

#include <algorithm>

// Додати нового оператора
void addOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators) {
    operators.push_back(Operator{name, code});
}

// Видалити оператора
void removeOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators) {
    operators.erase(std::remove_if(operators.begin(), operators.end(), [&](const Operator& op) {
        return op.name == name && op.code == code;
    }), operators.end());
}
