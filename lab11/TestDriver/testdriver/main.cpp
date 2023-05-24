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


void testPhonebook() {
    Phonebook phonebook;

    // Test loading from file
    phonebook.loadFromFile("phonebook.txt");
    phonebook.displayAllOperators();

    // Test searching by code
    phonebook.searchByCode("067");
    phonebook.searchByCode("050");
    phonebook.searchByCode("063");
    phonebook.searchByCode("099");
    phonebook.searchByCode("098");
    phonebook.searchByCode("095");

    // Test searching by name
    phonebook.searchByName("Kyivstar");
    phonebook.searchByName("Vodafone");
    phonebook.searchByName("Lifecell");
    phonebook.searchByName("MTS");

    // Test adding and removing operators
    phonebook.addOperator("MTS", "066");
    phonebook.displayAllOperators();
    phonebook.removeOperator("MTS", "066");
    phonebook.displayAllOperators();

    // Test saving to file
    phonebook.saveToFile("phonebook_new.txt");

    // Test loading from saved file
    Phonebook phonebook_new;
    phonebook_new.loadFromFile("phonebook_new.txt");
    phonebook_new.displayAllOperators();
}

int main() {
    testPhonebook();
    return 0;
}
