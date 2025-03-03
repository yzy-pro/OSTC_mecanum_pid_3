#include "robot.h"
#include "mecanum.h"
#include "encoder.h"
#include "motor.h"

void robot_control(Settings setting)
{
    Robot_condition Robot_target = Setting2Robot(setting);
    Wheel_condition Wheel_target = Robot2Wheel(Robot_target);
    Wheel_condition Wheel_current = Encoder2Wheel();

    Wheel_pwm pwm_settings = velovity_control(Wheel_target, Wheel_current);
    motors_control(pwm_settings);
}

