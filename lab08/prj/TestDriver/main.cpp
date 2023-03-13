#include <iostream>
#include <cmath>
#include "ModulesKohan.h"

#define ARRAY_SIZE 6

using namespace std;

int main() {
    const float x[ARRAY_SIZE] = {2, 5, 4,   4, 4,   4};
    const float y[ARRAY_SIZE] = {3, 8, -2, 11, -4,  4};
    const float z[ARRAY_SIZE] = {1,  2, 5, 6, 9, 9};
    const float expectedResult[ARRAY_SIZE] = {1,1022,97,4354,1294,1293};

    for (short int i = 0; i < ARRAY_SIZE; i++) {
        const float currentReasult = round(s_calculation(x[i], y[i], z[i])*10000) / 10000;
        if (currentReasult == expectedResult[i])
            cout << "Test #" << i+1 << " - PASSED\n";
        else
            cout << "Test #" << i+1 << " - FAILED\n";
    }
}
