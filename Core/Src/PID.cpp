#include "PID.h"

int velocity_PID(float target, float current)
{
    static PID velocity_PID = {
        .kp = 0,
        .ki = 0,
        .kd = 0,
        .error_limit = 0,
    };//@@@

    static float bias{}, last_bias{}, sum_bias{};
    int pwm_velocity{};

    bias = current - target;
    sum_bias += bias;

    sum_bias = (sum_bias > velocity_PID.error_limit) ? velocity_PID
    .error_limit : sum_bias;

    pwm_velocity = velocity_PID.kp * bias + velocity_PID.ki * sum_bias
    + velocity_PID.kd * (bias - last_bias);
    last_bias = bias;

    return pwm_velocity;
}

Wheel_pwm velovity_control(Wheel_condition target, Wheel_condition current)
{
    int pwm_A = velocity_PID(target.A_velocity, current.A_velocity);
    int pwm_B = velocity_PID(target.B_velocity, current.B_velocity);
    int pwm_C = velocity_PID(target.C_velocity, current.C_velocity);
    int pwm_D = velocity_PID(target.D_velocity, current.D_velocity);

    Wheel_pwm pwm_setting = {
    .A_velocity = pwm_A,
    .B_velocity = pwm_B,
    .C_velocity = pwm_C,
    .D_velocity = pwm_D,};

    return pwm_setting;
}