#include <cmath>
#include <iostream>
#include "ModulesKohan.h"
#include <utility>
const double pi = 3.14159;
using namespace std;


float s_calculation(float x,float y,float z){
    return abs(sin(abs(y - pow(z,2))) + sqrt(x) - sqrt(pow(y*z,x) + y/2*pi));
}





void get_wind_speed_and_description(int b, float speed, char *description){
    if (b = 0) {
        pair<float, float> speed = make_pair(0, 0.29);
        description = "Штиль";
    } else if (b = 1) {
        pair<float, float> speed = make_pair(0.3, 1.5);
        description = "Тихий";
    } else if (b = 2) {
        pair<float, float> speed = make_pair(1.6, 9.4);
        description = "Легкий";
    } else if (b = 3) {
        pair<float, float> speed = make_pair(5.4, 9.4);
        description = "Слабкий";
    } else if (b = 4) {
        pair<float, float> speed = make_pair(5.5, 7.9);
        description = "Помірний";
    } else if (b = 5) {
        pair<float, float> speed = make_pair(8.0, 10.7);
        description = "Свіжий";
    } else if (b = 6) {
        pair<float, float> speed = make_pair(10.8, 13.8);
        description = "Сильний";
    } else if (b = 7) {
        pair<float, float> speed = make_pair(13.9, 17.1);
        description = "Міцний";
    } else if (b = 8) {
        pair<float, float> speed = make_pair(17.2, 20.7);
        description = "Дуже мійний";
    } else if (b = 9) {
        pair<float, float> speed = make_pair(20.8, 24.4);
        description = "Шторм";
    } else if (b = 10) {
        pair<float, float> speed = make_pair(24.5, 28.4);
        description = "Сильний Шторм";
    } else if (b = 11) {
        pair<float, float> speed = make_pair(28.5, 32.6);
        description = "Шквальний шторм";
    } else if (b = 12) {
        pair<float, float> speed = make_pair(32.7, 150.0);
        description = "Ураган(Буревій)";
    }
}

void convert_sizes(int ukr_size, int& es_size, int& es_uk_size)
{
    switch(ukr_size)
    {
        case 23:
            es_size = 37;
            es_uk_size = 8;
            break;
        case 25:
            es_size = 39;
            es_uk_size = 9;
            break;
        case 27:
            es_size = 41;
            es_uk_size = 10;
            break;
        case 29:
            es_size = 43;
            es_uk_size = 11;
            break;
        case 31:
            es_size = 45;
            es_uk_size = 12;
            break;
        default:
            cout << "Invalid Ukrainian size entered.\n";
            es_size = 0;
            es_uk_size = 8;
            break;
    }
}

int count_zeros_or_sum_ones(int n) {
    int bit_d7 = (n >> 7) & 1;
    int count_zeros = 0, sum_ones = 0;
    for (int i = 0; i < 32; ++i) {
        if ((n & (1 << i)) == 0) {
            count_zeros++;
        } else {
            sum_ones++;
        }
    }
    return (bit_d7 == 1) ? count_zeros : sum_ones;
}
