#include "Ultrasonic.h"

void gpio_ultrasonic_init(){
	//echo:transment the information of starting. trig:the control mode.
	GPIO_InitTypeDef echo_gpio,trig_gpio;
	
	echo_gpio.Mode=GPIO_PullUp;
	echo_gpio.Pin=GPIO_Pin_3;
	trig_gpio.Mode=GPIO_PullUp;
	trig_gpio.Pin=GPIO_Pin_7;
	
	GPIO_Inilize(GPIO_P3,&echo_gpio);
	GPIO_Inilize(GPIO_P4,&trig_gpio);
}

void Delay10us(void)	//@24.000MHz
{
	unsigned char data i;

	i = 78;
	while (--i);
}


float ultrasonic_get(){
	u8 i=20;
	u8 cnt=0;
	float curr_dis=0;
	P47=1;
	Delay10us();
	P47=0;
//	do{
//		Delay10us();
//	}while(--i);
	os_wait2(K_TMO,4);
	while(P33==1){
		
		Delay10us();
		cnt++;
	}
	curr_dis=cnt*34/100/2;
	
	printf("dis:%f\n",curr_dis);
	return curr_dis;

}