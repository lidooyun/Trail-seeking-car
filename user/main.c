#include "config.h"


void system_init(){
	EAXSFR();
	led_init();
	key_init();
	user_uart_all_init();
	bluetooth_init();
	EA=1;
	bat_all_init();
	track_gpio_init();
	gpio_ultrasonic_init();
	motor_all_init();
	//motor_set(0,0,0,0);
	buzzer_init();
	buzzer_pwm_init();
}

void main_start() _task_ 0{
	system_init();
	os_create_task(key_task_num);
	os_create_task(user_uart_task_num);
	os_create_task(bluetooth_task_num);
	os_create_task(bat_task_num);
	
	
	os_delete_task(0);
}

void key_down(){
	printf("key_down");
	led_on();
	Motors_move(0 ,50);
}

void key_up(){
	printf("key_up");
	led_off();
	Motors_move(0,0);
	os_send_signal(1);
}
