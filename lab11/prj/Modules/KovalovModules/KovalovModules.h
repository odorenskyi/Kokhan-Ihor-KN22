#ifndef KOVALOV_MODULES_H
#define KOVALOV_MODULES_H

#include <vector>
#include <string>
#include "KikhotModules.h"

// Додати нового оператора
void addOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators);

// Видалити оператора
void removeOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators);

#endif
