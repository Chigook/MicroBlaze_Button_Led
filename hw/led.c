#include "led.h"

XGpio GPIO_LED;

void led_init()
{
	XGpio_Initialize(&GPIO_LED, XPAR_AXI_GPIO_0_DEVICE_ID);			// GPIO init
	XGpio_SetDataDirection(&GPIO_LED, CHANNEL_1, OUTPUT);
}

void Led_MakeInst(ledInst *led, int ledNum)
{
	led->ledNum = ledNum;
}

void Led_On(ledInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | (1<<led->ledNum));
}

void Led_Off(ledInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState & ~(1<<led->ledNum));
}

void Led_Toggle(ledInst *led)
{
	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, (ledState ^ (1<<led->ledNum)));
}

void Led_LeftShift()
{
	for(int i=0; i<8; i++){
		XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 1<<i);
		usleep(300000);
	}
}

void Led_RightShift()
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

/*
//같은 내용의 여러 함수를 만들어야 할 떄 다른 점을 찾아서 그 부분만 변수화 시키면 instance 만드는데 도움 된다.
//void Led_On_0()
//{
//	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | (1<<0));
//}
//
//void Led_On_1()
//{
//	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, ledState | (1<<1));
//}
//
//void Led_Off_0()
//{
//	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1l, (ledState & ~(1<<0)));
//
//}
//
//void Led_Toggle_0()
//{
//	int ledState = XGpio_DiscreteRead(&GPIO_LED, CHANNEL_1);
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1l, (ledState ^ ~(1<<0)));
//}
*/

//void led_on()
//{
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
//	usleep(1000000);
//}
//
//void led_off()
//{
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
//	usleep(1000000);
//}
//
//void led_toggle_1sec()
//{
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0x00);
//	usleep(1000000);
//	XGpio_DiscreteWrite(&GPIO_LED, CHANNEL_1, 0xff);
//	usleep(1000000);
//}



