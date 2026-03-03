#include "config.h"

void user_uart_receive(){
	printf("%s\n",RX1_Buffer);
}

void user_uart_task() _task_ user_uart_task_num{
	while(1){
		if(COM1.RX_TimeOut > 0 && --COM1.RX_TimeOut == 0) {
			if(COM1.RX_Cnt>0) {
				user_uart_receive();
			}
			COM1.RX_Cnt = 0;
    }
		os_wait2(K_TMO,1);
	}
}