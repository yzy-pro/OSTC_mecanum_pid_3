
#ifndef ENCODER_H
#define ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif
#include "robot.h"
#include "PID.h"

#define encoder_resolution 13 //编码器分辨率
#define encoder_gear_ratio 30 //减速比
#define encoder_resolution_u (4 * encoder_resolution * encoder_gear_ratio)//4分频

#define conversion_factor (2 * M_PI * R_of_wheel *PID_rate / \
encoder_resolution_u) //轮子速度m/s与编码器转换系数

int Encoder_Getcounter (int name);
void Encoder_Setcounter (int name, int value);
void Encoder_Reset(void);

Wheel_condition Encoder2Wheel(void);

#ifdef __cplusplus
}
#endif

#endif //ENCODER_H
