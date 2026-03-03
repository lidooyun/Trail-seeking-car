#include "config.h"
u8 i;
void bat_task() _task_ bat_task_num{
	while(1){
		get_bat_v();
		printf("bat_v = %f\n",V_NUM);
			if(V_NUM<10){
				for(i=0;i<3;i++){
					buzzer_start();
					os_wait2(K_TMO,100);
					buzzer_stop();
					os_wait2(K_TMO,100);
				}		
			}
		os_wait2(K_TMO,200);
	}
}