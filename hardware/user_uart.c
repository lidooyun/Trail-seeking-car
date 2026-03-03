#include "user_uart.h"

//激活p30和p31引脚
//gpio
void uart_gpio_init(){
	// tx P30 rx P31
	GPIO_InitTypeDef uart_gpio;
	uart_gpio.Mode = GPIO_PullUp;
	uart_gpio.Pin = GPIO_Pin_0 | GPIO_Pin_1;
	
	GPIO_Inilize(GPIO_P3, &uart_gpio);
}

//激活p30和p31的串口功能
//uart
void user_uart_init(){
	
	COMx_InitDefine user_uart;
	
	user_uart.UART_Mode  = UART_8bit_BRTx;			//模式,         UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	user_uart.UART_BRT_Use = BRT_Timer1;		//使用波特率,   BRT_Timer1,BRT_Timer2,BRT_Timer3,BRT_Timer4
	user_uart.UART_BaudRate = 115200;	//9600	//波特率, 	   一般 110 ~ 115200
	//115200 8个电平跳变+1开始位+结束位置 = 10位
	//11.25kb/s
	user_uart.Morecommunicate = DISABLE;	//多机通讯允许, ENABLE,DISABLE
	user_uart.UART_RxEnable = ENABLE;		//允许接收,   ENABLE,DISABLE
	user_uart.BaudRateDouble = DISABLE;		//波特率加倍, ENABLE,DISABLE

	UART_Configuration(UART1, &user_uart);
	
	//中断开关
	NVIC_UART1_Init(ENABLE,Priority_1);
	
	//把引脚从gpio功能切换成uart功能
	UART1_SW(UART1_SW_P30_P31);
}

void user_uart_all_init(){
	uart_gpio_init();
	user_uart_init();
}



