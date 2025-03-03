#ifndef PID_H
#define PID_H

#ifdef __cplusplus
extern "C" {
#endif
#include "robot.h"
#define PID_rate 50//@@@

typedef struct
{
    float kp;
    float ki;
    float kd;
    float error_limit;
}PID;

int velocity_PID(float target, float current);
Wheel_pwm velovity_control(Wheel_condition target, Wheel_condition current);

#ifdef __cplusplus
}
#endif
#endif //PID_H
