#ifndef __bat_h_
#define __bat_h_
#include "config.h"

extern float V_NUM;

void bat_gpio_init();
void bat_adc_init();
void get_bat_v();
void bat_all_init();

#endif