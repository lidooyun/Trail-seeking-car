#include "key.h"

void key_init(){
	GPIO_InitTypeDef key_GPIO;

	key_GPIO.Mode = GPIO_PullUp;
	key_GPIO.Pin = GPIO_Pin_5;

	GPIO_Inilize(GPIO_P0, &key_GPIO);

}
//加标记位
//功能可以实现 非常消耗资源
u8 key_last_state = 0;
extern void key_down();
extern void key_up();
void key_scan(){
	//判断条件进行修改
	//if 判断当前的状态和上一次的状态
	//if 当前是抬起的上一次就是按下状态
	if(key == 1 && key_last_state == 0){
		//更新上一次的状态
		key_last_state = 1;
		key_up();
		
	//如果当前状态是按下，上一次的状态抬起
	}else if(key == 0&& key_last_state == 1){
		key_last_state = 0;
		key_down();
	}

}