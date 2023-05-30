#include <iostream>
#include "KikhotModules.h"
#include "ModulesKohan.h"
#include "KovalovModules.h"
#include <windows.h>


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::string filename = "phonebook.txt";
    std::vector<Operator> operators;
    loadFromFile(filename, operators);

    while (true) {
        std::cout << "Select an option:" << std::endl;
        std::cout << "1. Search by code" << std::endl;
        std::cout << "2. Search by name" << std::endl;
        std::cout << "3. Display all operators" << std::endl;
        std::cout << "4. Add a new operator" << std::endl;
        std::cout << "5. Delete the operator" << std::endl;
        std::cout << "6. Save and exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
                        std::string code;
            std::cout << "Enter the code: ";
            std::cin >> code;
            searchByCode(code, operators);
            break;
        }
        case 2: {
            std::string name;
            std::cout << "Enter a name: ";
            std::cin >> name;
            searchByName(name, operators);
            break;
        }
        case 3: {
            displayAllOperators(operators);
            break;
        }
        case 4: {
            std::string name, code;
            std::cout << "Enter a name: ";
            std::cin >> name;
            std::cout << "Enter the code: ";
            std::cin >> code;
            addOperator(name, code, operators);
            std::cout << "Operator added" << std::endl;
            break;
        }
        case 5: {
            std::string name, code;
            std::cout << "Enter a name: ";
            std::cin >> name;
            std::cout << "Enter the code: ";
            std::cin >> code;
            removeOperator(name, code, operators);
            std::cout << "The operator has been deleted" << std::endl;
            break;
        }
        case 6: {
            saveToFile(filename, operators);
            std::cout << "Exiting the program..." << std::endl;
            return 0;
        }
        default:
            std::cout << "Wrong choice. Try again." << std::endl;
        }
    }

    return 0;
}


