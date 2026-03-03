#include "motor.h"
//初始化gpio
void motor_front_gpio_init(){
	GPIO_InitTypeDef motor_front_gpio;
	motor_front_gpio.Mode = GPIO_OUT_PP;
	motor_front_gpio.Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Inilize(GPIO_P1,&motor_front_gpio);
}
//初始化gpio
void motor_back_gpio_init(){
	GPIO_InitTypeDef motor_back_gpio;
	motor_back_gpio.Mode = GPIO_OUT_PP;
	motor_back_gpio.Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_Inilize(GPIO_P2,&motor_back_gpio);
}

void motor_pwma_init(u8 state){
	PWMx_InitDefine motor_pwma;
	motor_pwma.PWM_Period = MAIN_Fosc/1000;		//周期时间,   0~65535
	motor_pwma.PWM_DeadTime = 0;	//死区发生器设置, 0~255
	if(state == ENABLE){
		motor_pwma.PWM_CEN_Enable = ENABLE;		//使能计数器, ENABLE,DISABLE
		motor_pwma.PWM_MainOutEnable = ENABLE;//主输出使能,  ENABLE,DISABLE
	}else if(state == DISABLE){
		motor_pwma.PWM_CEN_Enable = DISABLE;		//使能计数器, ENABLE,DISABLE
		motor_pwma.PWM_MainOutEnable = DISABLE;//主输出使能,  ENABLE,DISABLE

	}
		PWM_Configuration(PWMA, &motor_pwma);
}

//初始化pwm 左前轮
//speed = -100 - 0 - 100
void motor_fl_pwm_init(float speed){
	PWMx_InitDefine motor_fl_pwm;
	u8 forward = 1;
	
	if(speed	>= 100){
		speed = 100;
	}
	if(speed<=-100){
		speed = -100;
	}
	forward =  (speed>=0);
	if(forward){
		motor_fl_pwm.PWM_EnoSelect = ENO3N;		//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	}else{
		motor_fl_pwm.PWM_EnoSelect = ENO3P;
	}
	speed = (speed>=0 ? speed : -speed);
	motor_fl_pwm.PWM_Mode = CCMRn_PWM_MODE2;
	motor_fl_pwm.PWM_Duty = (MAIN_Fosc/1000) * (speed/100);			//占空比时间, 0~Period
	printf("speed = %f\n",speed);
	printf("motor_fl_pwm.PWM_Duty  = %d\n",motor_fl_pwm.PWM_Duty );
	PWM_Configuration(PWM3, &motor_fl_pwm);
	PWM3_SW(PWM3_SW_P14_P15);
}

//初始化pwm 右前轮
//speed = -100 - 0 - 100
void motor_fr_pwm_init(float speed){
	PWMx_InitDefine motor_fr_pwm;
	u8 forward = 1;
	
	if(speed	>= 100){
		speed = 100;
	}
	if(speed<=-100){
		speed = -100;
	}
	forward =  (speed>=0);
	if(forward){
		motor_fr_pwm.PWM_EnoSelect = ENO4P;		//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	}else{
		motor_fr_pwm.PWM_EnoSelect = ENO4N;
	}
	speed = (speed>=0 ? speed : -speed);
	motor_fr_pwm.PWM_Mode = CCMRn_PWM_MODE2;
	motor_fr_pwm.PWM_Duty = MAIN_Fosc/1000 * speed/100;			//占空比时间, 0~Period
	PWM_Configuration(PWM4, &motor_fr_pwm);
	PWM4_SW(PWM4_SW_P16_P17);
	
}

//初始化pwm 左后轮
//speed = -100 - 0 - 100
void motor_bl_pwm_init(float speed){
	PWMx_InitDefine motor_bl_pwm;
	u8 forward = 1;
	
	if(speed	>= 100){
		speed = 100;
	}
	if(speed<=-100){
		speed = -100;
	}
	forward =  (speed>=0);
	if(forward){
		motor_bl_pwm.PWM_EnoSelect = ENO1N;		//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	}else{
		motor_bl_pwm.PWM_EnoSelect = ENO1P;
	}
	speed = (speed>=0 ? speed : -speed);
	motor_bl_pwm.PWM_Mode = CCMRn_PWM_MODE2;
	motor_bl_pwm.PWM_Duty = MAIN_Fosc/1000 * speed/100;			//占空比时间, 0~Period
	PWM_Configuration(PWM1, &motor_bl_pwm);
	PWM1_SW(PWM1_SW_P20_P21);
}

//初始化pwm 右后轮
//speed = -100 - 0 - 100
void motor_br_pwm_init(float speed){
	PWMx_InitDefine motor_br_pwm;
	u8 forward = 1;
	
	if(speed	>= 100){
		speed = 100;
	}
	if(speed<=-100){
		speed = -100;
	}
	forward =  (speed>=0);
	if(forward){
		motor_br_pwm.PWM_EnoSelect = ENO2P;		//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	}else{
		motor_br_pwm.PWM_EnoSelect = ENO2N;
	}
	speed = (speed>=0 ? speed : -speed);
	motor_br_pwm.PWM_Mode = CCMRn_PWM_MODE2;
	motor_br_pwm.PWM_Duty = MAIN_Fosc/1000 * speed/100;			//占空比时间, 0~Period
	PWM_Configuration(PWM2, &motor_br_pwm);
	PWM2_SW(PWM2_SW_P22_P23);
}

void motor_set(float fl_speed ,float fr_speed ,float bl_speed ,float br_speed){
	
	motor_fl_pwm_init(fl_speed);
	motor_fr_pwm_init(fr_speed);
	motor_bl_pwm_init(bl_speed);
	motor_br_pwm_init(br_speed);
}

void motor_run(float left_speed ,float right_speed){
	motor_set(left_speed ,right_speed,left_speed ,right_speed);
}

void motor_turn_left(float speed){

		motor_run(speed-10 ,speed+10);
}

void motor_turn_right(float speed){

		motor_run(speed+10 ,speed-10);
}

void motor_round(float speed){

		motor_run(-speed ,speed);
}

void motor_stop(){

	motor_run(0 ,0);
}

void motor_all_init(){
	//gpio
	motor_front_gpio_init();
	motor_back_gpio_init();
	//pwm
	motor_pwma_init(ENABLE);
	//所有轮子设置0
	//motor_run(0,0);
}

static float clip_speed(float speed) {

    if(speed < -100) {
        return -100;
    } else if(speed > 100) {
        return 100;
    }
    return speed;
}

/**
┏		↑Y+  ┓

    x
←	 	0 		→
X-					X+
		x
┗		↓Y-	┛

X    -100			0   	100
Y		 -100 		0			100

Y 100
X -50
**/
void Motors_move(float x, float y) {
    // 把数值限制在 -60 -> 60
    motor_fl_pwm_init(0.6 * clip_speed(y + x));
    motor_bl_pwm_init(0.6 * clip_speed(y - x));
    motor_fr_pwm_init(0.6 * clip_speed(y - x));
    motor_br_pwm_init(0.6 * clip_speed(y + x));		
}