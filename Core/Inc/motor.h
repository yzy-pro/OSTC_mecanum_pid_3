#ifndef MOTOR_H
#define MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "robot.h"

#define abs_max_speed 720 // ARR为 720 - 1

void motor_control(int name, int speed);
//电机控制函数
//轮子编号，速度（pwm）

void motors_control(Wheel_pwm pwm);



#ifdef __cplusplus
}
#endif

#endif //MOTOR_H
