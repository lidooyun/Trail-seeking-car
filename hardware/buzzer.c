#include "buzzer.h"
//激活gpio
void buzzer_init(){
	GPIO_InitTypeDef buzzer_gpio;
	buzzer_gpio.Mode = GPIO_OUT_PP;
	buzzer_gpio.Pin = GPIO_Pin_4;
	GPIO_Inilize(GPIO_P3,&buzzer_gpio);

}
//激活pwm功能
void buzzer_pwm_init(){
	PWMx_InitDefine buzzer_pwm;
	buzzer_pwm.PWM_Mode = CCMRn_PWM_MODE1;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
	
	buzzer_pwm.PWM_Period = MAIN_Fosc/1000; 	//1ms	//周期时间,   0~65535
	buzzer_pwm.PWM_Duty = 0;	//赫兹		//占空比时间, 0~Period
	buzzer_pwm.PWM_DeadTime = 0;	//死区发生器设置, 0~255
	buzzer_pwm.PWM_EnoSelect = ENO8P;		//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	buzzer_pwm.PWM_CEN_Enable = ENABLE;		//使能计数器, ENABLE,DISABLE
	buzzer_pwm.PWM_MainOutEnable = ENABLE;//主输出使能,  ENABLE,DISABLE

	PWM_Configuration(PWM8, &buzzer_pwm);
	PWM_Configuration(PWMB, &buzzer_pwm);
	
	//切换PWM8选择PWM8_SW_P34
  PWM8_SW(PWM8_SW_P34);		
}
//num:百分之多少 0-100；
//updata_buzzer： 更新蜂鸣器的声音
void updata_buzzer(u8 num){

	PWMx_Duty buzzer_duty;
	//x% =  x/100
	buzzer_duty.PWM8_Duty = MAIN_Fosc/1000 * num /100;//占空比
	UpdatePwm(PWM8, &buzzer_duty);
}

void buzzer_start(){
	updata_buzzer(50);
}

void buzzer_stop(){
	updata_buzzer(0);
}