#include "track.h"

void track_gpio_init(){
	GPIO_InitTypeDef track_gpio;
	track_gpio.Mode=GPIO_PullUp;
	track_gpio.Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_Inilize(GPIO_P0,&track_gpio);
}

int track_scan(){
	
	int sum=0;
	int cnt=0;
	if(RRIGHT==1){sum+=64;cnt++;}
	if(RIGHT==1){sum+=32;cnt++;}
	if(MID==1){cnt++;}
	if(LEFT==1){sum-=32;cnt++;}
	//if(LLEFT==1){sum-=64;cnt++;}
	printf("sum=%d, cnt=%d, pos=%d\n",sum,cnt,sum/cnt);
	if(cnt==0){return 0;}
	return sum/cnt;
}