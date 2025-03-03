#ifndef ROBOT_H
#define ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif
#include "math.h"

#define R_of_robot ((float)1)//@@@
#define R_of_wheel ((float)1)//@@@

#define alpha ((float)45)//@@@
#define beta (90 - alpha)
#define theta ((float)45)//@@@

    #define alpha_rad (M_PI / 180.0 * alpha )
    #define beta_rad (M_PI / 180.0 * beta )
    #define theta_rad (M_PI / 180.0 * theta )
typedef struct
{
    float x_velocity;
    float y_velocity;
    float omega_velocity;
}Robot_condition;

typedef struct
{
    float A_velocity;
    float B_velocity;
    float C_velocity;
    float D_velocity;
}Wheel_condition;

typedef struct
{
    int A_velocity;
    int B_velocity;
    int C_velocity;
    int D_velocity;
}Wheel_pwm;

typedef struct
{
    float speed;
    float angle;
    float omega;
}Settings;


void robot_control(Settings setting);
#ifdef __cplusplus
}
#endif

#endif //ROBOT_H
