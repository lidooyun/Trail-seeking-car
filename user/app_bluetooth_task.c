#include "config.h"

void bluetooth_task() _task_ bluetooth_task_num{
	while(1){
		bluetooth_receive();
		os_wait2(K_TMO,1);
	}
}