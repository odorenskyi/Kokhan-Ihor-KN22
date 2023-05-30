#ifndef KOKHAN_MODULES_H
#define KOKHAN_MODULES_H

#include <vector>
#include <string>
#include "KikhotModules.h"

// Пошук оператора за кодом
void searchByCode(const std::string& code, const std::vector<Operator>& operators);

// Пошук оператора за назвою
void searchByName(const std::string& name, const std::vector<Operator>& operators);

// Відобразити всіх операторів
void displayAllOperators(const std::vector<Operator>& operators);

#endif
