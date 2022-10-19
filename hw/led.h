#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define CHANNEL_1 1
#define OUTPUT 0x00

#define  LED_0 0
#define  LED_1 1
#define  LED_2 2
#define  LED_3 3


typedef struct _led{
	int ledNum;
}ledInst;

void led_init();
void Led_On(ledInst *led);
void Led_Off(ledInst *led);
void Led_Toggle(ledInst *led);
void Led_LeftShift();
void Led_RightShift();

//void Led_On_0();
//void Led_Off_0();
//void Led_Toggle_0();
//void led_on();
//void led_off();
//void led_toggle_1sec();
