#ifndef __bluetooth_h_
#define __bluetooth_h_
#include "config.h"
void bluetooth_gpio_init();
void bluetooth_uart_init();
void bluetooth_init();
void bluetooth_receive();
#endif