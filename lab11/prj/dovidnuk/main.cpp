#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Operator {
public:
    Operator(string name, string code) : name_(name), code_(code) {}

    string name() const { return name_; }
    string code() const { return code_; }

private:
    string name_;
    string code_;
};

class Phonebook {
public:
    void loadFromFile(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }

        string name, code;
        while (infile >> name >> code) {
            operators_.push_back(Operator(name, code));
        }
    }

    void saveToFile(const string& filename) {
        ofstream outfile(filename);
        if (!outfile) {
            cerr << "Failed to open file: " << filename << endl;
            return;
        }

        for (const auto& op : operators_) {
            outfile<< op.name() << " " << op.code() << endl;
        }
    }

    void searchByCode(const string& code) const {
        auto it = find_if(operators_.begin(), operators_.end(), [&](const Operator& op) {
            return op.code() == code;
        });

        if (it != operators_.end()) {
            cout << "Operator: " << it->name() << ", Code: " << it->code() << endl;
        } else {
            cout << "No operator found with code: " << code << endl;
        }
    }

    void searchByName(const string& name) const {
        auto it = find_if(operators_.begin(), operators_.end(), [&](const Operator& op) {
            return op.name() == name;
        });

        if (it != operators_.end()) {
            cout << "Operator: " << it->name() << ", Code: " << it->code() << endl;
        } else {
            cout << "No operator found with name: " << name << endl;
        }
    }

    void addOperator(const string& name, const string& code) {
        operators_.push_back(Operator(name, code));
    }

    void removeOperator(const string& name, const string& code) {
        operators_.erase(remove_if(operators_.begin(), operators_.end(), [&](const Operator& op) {
            return op.name() == name && op.code() ==code;
        }), operators_.end());
    }

    void displayAllOperators() const {
        for (const auto& op : operators_) {
            cout << "Operator: " << op.name() << ", Code: " << op.code() << endl;
        }
    }

private:
    vector<Operator> operators_;
};

int main() {
    string filename = "phonebook.txt";
    Phonebook phonebook;
    phonebook.loadFromFile(filename);

    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Search by code" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Display all operators" << endl;
        cout << "4. Add new operator" << endl;
        cout << "5. Remove operator" << endl;
        cout << "6. Save and exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string code;
            cout << "Enter code: ";
            cin >> code;
            phonebook.searchByCode(code);
            break;
        }
        case 2: {
            string name;
            cout << "Enter name: ";
            cin >> name;
            phonebook.searchByName(name);
            break;
        }
        case 3: {
            phonebook.displayAllOperators();
            break;
        }
        case 4: {
            string name,code;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter code: ";
            cin >> code;
            phonebook.addOperator(name, code);
            cout << "Operator added" << endl;
            break;
        }
        case 5: {
            string name, code;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter code: ";
            cin >> code;
            phonebook.removeOperator(name, code);
            cout << "Operator removed" << endl;
            break;
        }
        case 6: {
            phonebook.saveToFile(filename);
            cout << "Exiting program..." << endl;
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
