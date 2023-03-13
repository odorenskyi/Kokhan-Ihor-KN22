#include <cmath>

const double pi = 3.14159;


float s_calculation(float x,float y,float z){
    return abs(sin(abs(y - pow(z,2))) + sqrt(x) - sqrt(pow(y*z,x) + y/2*pi));
}
