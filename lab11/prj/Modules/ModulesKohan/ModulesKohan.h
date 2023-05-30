#ifndef KOKHAN_MODULES_H
#define KOKHAN_MODULES_H

#include <vector>
#include <string>
#include "KikhotModules.h"

// ����� ��������� �� �����
void searchByCode(const std::string& code, const std::vector<Operator>& operators);

// ����� ��������� �� ������
void searchByName(const std::string& name, const std::vector<Operator>& operators);

// ³��������� ��� ���������
void displayAllOperators(const std::vector<Operator>& operators);

#endif
