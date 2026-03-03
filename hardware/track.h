#ifndef __track_h_
#define __track_h_
#include "config.h"

#define RRIGHT P04
#define RIGHT P03
#define MID P02
#define LEFT P01
#define LLEFT P00

void track_gpio_init();
int track_scan();

#endif