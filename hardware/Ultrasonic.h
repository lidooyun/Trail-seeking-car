#ifndef __Ultrasonic_h_
#define __Ultrasonic_h_
#include "config.h"

#define ULTRASONIC_ECHO	P33
#define ULTRASONIC_TRIG	P47

#define ULTRASONIC_PIN_INIT() {P3M0 &= ~0x08; P3M1 |= 0x08; P4M0 |= 0x80; P4M1 &= ~0x80;}

void gpio_ultrasonic_init();
void Delay10us(void);
float ultrasonic_get();


#endif