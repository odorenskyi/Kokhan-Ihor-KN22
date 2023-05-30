#ifndef KOVALOV_MODULES_H
#define KOVALOV_MODULES_H

#include <vector>
#include <string>
#include "KikhotModules.h"

// ������ ������ ���������
void addOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators);

// �������� ���������
void removeOperator(const std::string& name, const std::string& code, std::vector<Operator>& operators);

#endif
