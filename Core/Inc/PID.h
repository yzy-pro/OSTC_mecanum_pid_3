#ifndef PID_H
#define PID_H

#ifdef __cplusplus
extern "C" {
#endif

#define PID_rate 50//@@@

typedef struct
{
    float kp;
    float ki;
    float kd;
    float error_limit;
}PID;

int velocity_PID(float target, float current);

#ifdef __cplusplus
}
#endif
#endif //PID_H
