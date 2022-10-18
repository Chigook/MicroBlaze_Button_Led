#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define CHANNEL_1 1
#define OUTPUT 0x00

XGpio GPIO_LED;

void led_init();
void led_on();
void led_off();
void led_toggle_1sec();
void led_leftShift();
void led_rightShift();
