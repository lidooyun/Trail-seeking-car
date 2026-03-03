#include "bat.h"
float V_NUM;

void bat_gpio_init(){
		GPIO_InitTypeDef bat_gpio;
		bat_gpio.Mode = GPIO_HighZ;
		bat_gpio.Pin = GPIO_Pin_3;
		
		GPIO_Inilize(GPIO_P1, &bat_gpio);
}

void bat_adc_init(){
		ADC_InitTypeDef bat_adc;
	
		bat_adc.ADC_SMPduty = 31;		//ADC 模拟信号采样时间控制, 0~31（注意： SMPDUTY 一定不能设置小于 10）
		bat_adc.ADC_Speed = ADC_SPEED_2X1T;			//设置 ADC 工作时钟频率	ADC_SPEED_2X1T~ADC_SPEED_2X16T
		bat_adc.ADC_AdjResult = ADC_RIGHT_JUSTIFIED;	//ADC结果调整,	ADC_LEFT_JUSTIFIED,ADC_RIGHT_JUSTIFIED
		bat_adc.ADC_CsSetup = 0;		//ADC 通道选择时间控制 0(默认),1
		bat_adc.ADC_CsHold = 1;			//ADC 通道选择保持时间控制 0,1(默认),2,3
		
		ADC_Inilize(&bat_adc);
	
		ADC_PowerControl(ENABLE);
}

void bat_all_init(){
	bat_gpio_init();
	bat_adc_init();
}
void get_bat_v(){
	V_NUM=Get_ADCResult(3)*5.7*2.5/4096;
	
}
