#ifndef __motor_h_
#define __motor_h_

#include "config.h"
void motor_all_init();
//motor_run：小车直行 left_speed左边的速度right_speed右边的速度
//speed：-100-0-100  -100-0后退  0-100前进
void motor_run(float left_speed ,float right_speed);
//motor_turn_left 小车左转 
//speed ：10-100
void motor_turn_left(float speed);
//motor_turn_right 小车右转 
//speed ：10-100
void motor_turn_right(float speed);
//motor_round 小车原地转圈 
//speed ：0-100
void motor_round(float speed);
//motor_stop 小车停止
void motor_stop();
void Motors_move(float x, float y);
void motor_set(float fl_speed ,float fr_speed ,float bl_speed ,float br_speed);
#endif