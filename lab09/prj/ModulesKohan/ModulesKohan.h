#ifndef MODULESKOHAN_H_INCLUDED
#define MODULESKOHAN_H_INCLUDED

float s_calculation(float x,float y,float z);
void get_wind_speed_and_description(int b, float *speed, char *description);
void convert_sizes(int ukr_size, int& us_size, int& eu_size);
int count_zeros_or_sum_ones(int n);

#endif // MODULESKOHAN_H_INCLUDED
