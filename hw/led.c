#include "led.h"

void led_init()
{
	XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);			// GPIO init
	XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, OUTPUT);
}

void led_on()
{
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
	usleep(1000000);
}

void led_off()
{
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
	usleep(1000000);
}

void led_toggle_1sec()
{
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
	usleep(1000000);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
	usleep(1000000);
}

void led_leftShift()
{
	for(int i=0; i<8; i++){
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 1<<i);
		usleep(300000);
	}
}

void led_rightShift()
{
	for(int i=8; i>0; i--){
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 1<<(i-1));
		usleep(300000);
	}
}
//	for(int i=0; i<8; i++){
//		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 128>>i);
//		usleep(300000);
//	}

