#include "bluetooth.h"


void bluetooth_gpio_init(){
	// tx P30 rx P31
	GPIO_InitTypeDef bluetooth_gpio;
	bluetooth_gpio.Mode = GPIO_PullUp;
	bluetooth_gpio.Pin = GPIO_Pin_0 | GPIO_Pin_1;
	
	GPIO_Inilize(GPIO_P1, &bluetooth_gpio);
}

void bluetooth_uart_init(){
	COMx_InitDefine bluetooth_uart;
	
	bluetooth_uart.UART_Mode  = UART_8bit_BRTx;			//模式,         UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	bluetooth_uart.UART_BRT_Use = BRT_Timer2;		//使用波特率,   BRT_Timer1,BRT_Timer2,BRT_Timer3,BRT_Timer4
	bluetooth_uart.UART_BaudRate = 115200;	//9600	//波特率, 	   一般 110 ~ 115200
	//115200 8个电平跳变+1开始位+结束位置 = 10位
	//11.25kb/s
	bluetooth_uart.Morecommunicate = DISABLE;	//多机通讯允许, ENABLE,DISABLE
	bluetooth_uart.UART_RxEnable = ENABLE;		//允许接收,   ENABLE,DISABLE
	bluetooth_uart.BaudRateDouble = DISABLE;		//波特率加倍, ENABLE,DISABLE

	UART_Configuration(UART2, &bluetooth_uart);
	
	//中断开关
	NVIC_UART2_Init(ENABLE,Priority_1);
	
	//把引脚从gpio功能切换成uart功能
	UART2_SW(UART2_SW_P10_P11);
	
}


void bluetooth_init(){
	bluetooth_gpio_init();
	bluetooth_uart_init();
}
u8 led_state=0;
u8 buzzer_state=0;
u8 auto_tracke_task = 0;
void data_tackle(u8* data_num ,u8 Cnt){
	char x,y;
	if(Cnt>8)return;
	if(data_num[0]==0xDD&&data_num[1]==0x77){
		printf("head success\n");
		if(data_num[4]==0x01){
			led_state=!led_state;
			if(led_state){
				led_on();
			}
			else{
				led_off();
			}
		}
		
		if(data_num[5]==0x01){
			buzzer_state=!buzzer_state;
			if(buzzer_state){
				buzzer_start();
			}
			else{
				buzzer_stop();
			}
		}
		if(data_num[6]==0x01){
			printf("Button C is pressing");
		}
		if(data_num[7] == 0x01){
			auto_tracke_task = ~auto_tracke_task;
			if(auto_tracke_task){
				os_create_task(track_task_num);
			}
			else{
				os_delete_task(track_task_num);
			}
		}
		
		if(auto_tracke_task){
			return;
		}
		
		x=data_num[2];
		y=data_num[3];
		
		Motors_move((float) x,(float) y);
	}
}


void bluetooth_receive(){
	u8 i=0;
	if(COM2.RX_TimeOut>0&& --COM2.RX_TimeOut==0){
		if(COM2.RX_Cnt>0){
			for(;i<COM2.RX_Cnt;i++){
				TX1_write2buff(RX2_Buffer[i]);
				//printf("test");
				//printf("%s\n",RX2_Buffer[i]);
			}
			data_tackle(RX2_Buffer,COM2.RX_Cnt);
		}
		COM2.RX_Cnt=0;
	}
	
}