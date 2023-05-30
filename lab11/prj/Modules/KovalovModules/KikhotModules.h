#ifndef KIKHOTMODULES_H_INCLUDED
#define KIKHOTMODULES_H_INCLUDED

#ifndef KIKHOT_MODULES_H
#define KIKHOT_MODULES_H

#include <vector>
#include <string>

// Оператор мобільного зв'язку
struct Operator {
    std::string name; // Назва оператора
    std::string code; // Код оператора
};

// Завантажити дані з файлу
void loadFromFile(const std::string& filename, std::vector<Operator>& operators);

// Зберегти дані у файл
void saveToFile(const std::string& filename, const std::vector<Operator>& operators);

#endif


#endif // KIKHOTMODULES_H_INCLUDED
