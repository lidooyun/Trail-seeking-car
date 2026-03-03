#include "config.h"


void track_task() _task_ track_task_num{
	int pos=0,last_pos=1;
	while(1){
		if(V_NUM<10){
			motor_run(0,0);
			continue;
		}
#if Ultrasonic_task
		if(ultrasonic_get()<10){
			motor_run(0,0);
			continue;
		}
#endif	
		
		
		pos=track_scan();
		
		if(pos==last_pos){
			os_wait2(K_TMO,1);	
			//Delay10us();
			continue;
		}
		if(pos==0){
			motor_run(25,25);		
			last_pos=pos;
			//Delay10us();
		}
		else if(pos<0){
			motor_run(5,30);		
			last_pos=pos;
			//os_wait2(K_TMO,1);
		}
		else{
			motor_run(30,5);
			last_pos=pos;
			//os_wait2(K_TMO,1);
		}
		os_wait2(K_TMO,1);	
				
	}
}