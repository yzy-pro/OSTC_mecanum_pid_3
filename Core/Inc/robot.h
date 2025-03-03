#ifndef ROBOT_H
#define ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif

#define R_of_robot ((float)1)//@@@
#define R_of_wheel ((float)1)//@@@

#define alpha ((float)45)//@@@
#define beta (90 - alpha)
#define theta ((float)45)//@@@

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
}Wheel_velocity;

#ifdef __cplusplus
}
#endif

#endif //ROBOT_H
