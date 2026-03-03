#ifndef _led_h_
#define _led_h_
#include "gpio.h"
#include "delay.h"
//声明 （函数的名字）
void led_init();
void led_on();
void led_off();
void led_blink();
#endif