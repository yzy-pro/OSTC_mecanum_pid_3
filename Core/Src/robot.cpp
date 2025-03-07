#include "robot.h"
#include "mecanum.h"
#include "encoder.h"
#include "motor.h"
#include "main.h"
#include "tim.h"

void robot_init()
{
    HAL_TIM_PWM_Start(&A_B_MOTOR_TIM, TIM_CHANNEL_ALL);
    HAL_TIM_PWM_Start(&C_D_MOTOR_TIM, TIM_CHANNEL_ALL);

    HAL_TIM_Encoder_Start(&A_ENCODER_TIM, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&B_ENCODER_TIM, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&C_ENCODER_TIM, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&D_ENCODER_TIM, TIM_CHANNEL_ALL);

}

void robot_control(Settings setting)//通过其他算法算出来期望速度
{
    Robot_condition Robot_target = Setting2Robot(setting);//换算为xy速度和角速度
    Wheel_condition Wheel_target = Robot2Wheel(Robot_target);//换算成每个轮子需要的速度
    Wheel_condition Wheel_current = Encoder2Wheel();//从编码器读取当前速度

    Wheel_pwm pwm_settings = velocity_control(Wheel_target, Wheel_current);//用PID算出需要输出的pwm值
    motors_control(pwm_settings);//操作电机
}

