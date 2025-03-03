#include "motor.h"
#include "tim.h"

void motor_control(const int name, int speed)
{
    if (speed > abs_max_speed || speed < -abs_max_speed)
    {
        if (speed > abs_max_speed)
        {
            speed = abs_max_speed;
        }
        else if (speed < -abs_max_speed)
        {
            speed = -abs_max_speed;
        }
    }

    if (name == 'A')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, A_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, A_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, A_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, A_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, A_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, A_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'B')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, B_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, B_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, B_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, B_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, B_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&A_B_MOTOR_TIM, B_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'C')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, C_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, C_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, C_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, C_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, C_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, C_MOTOR_2_Pin, speed);
        }

    }
    else if (name == 'D')
    {
        if (speed == 0)
        {
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, D_MOTOR_1_Pin, abs_max_speed);
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, D_MOTOR_2_Pin, abs_max_speed);
        }
        else if (speed > 0)
        {
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, D_MOTOR_1_Pin, speed);
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, D_MOTOR_2_Pin, 0);
        }
        else if (speed < -0)
        {
            speed = -speed;
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, D_MOTOR_1_Pin, 0);
            __HAL_TIM_SetCompare(&C_D_MOTOR_TIM, D_MOTOR_2_Pin, speed);
        }
    }
}

void motors_control(Wheel_pwm pwm)
{
    motor_control('A', pwm.A_velocity);
    motor_control('B', pwm.B_velocity);
    motor_control('C', pwm.C_velocity);
    motor_control('D', pwm.D_velocity);
}
