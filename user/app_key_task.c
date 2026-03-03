#include "config.h"

void key_task() _task_ key_task_num{
	while(1){
		key_scan();
		os_wait2(K_TMO,4);
	}
	
}