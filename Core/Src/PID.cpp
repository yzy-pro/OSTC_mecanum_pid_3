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