#include "led.h"

//第一步 初始化
//模式引脚端口
//P07 ,P52
void led_init(){
	GPIO_InitTypeDef LEDL_GPIO;
	GPIO_InitTypeDef LEDR_GPIO;
	
	LEDL_GPIO.Mode = GPIO_OUT_PP;
	LEDL_GPIO.Pin = GPIO_Pin_7;
	
	LEDR_GPIO.Mode = GPIO_OUT_PP;
	LEDR_GPIO.Pin = GPIO_Pin_2;
	
	GPIO_Inilize(GPIO_P0, &LEDL_GPIO);
	GPIO_Inilize(GPIO_P5, &LEDR_GPIO);
}

void led_on(){
		P07 = 1;
		P52 = 1;
}
void led_off(){
		P07 = 0;
		P52 = 0;
}
void led_blink(){
	led_on();
	delay_ms(250);
	delay_ms(250);
	led_off();
	delay_ms(250);
	delay_ms(250);
}