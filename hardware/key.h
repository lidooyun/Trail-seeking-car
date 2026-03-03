#ifndef _key_h_
#define _key_h_

#include "gpio.h"
#include "led.h"

#define key P05
void key_init();
void key_scan();
#endif