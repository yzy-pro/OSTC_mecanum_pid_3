#include "mecanum.h"
#include "robot.h"
#include <cmath>

Wheel_condition Robot2Wheel(Robot_condition Robot)
{
    //A
    float v_x_A = Robot.x_velocity - Robot.omega_velocity * R_of_robot * sin
    (alpha_rad);
    float v_y_A = Robot.y_velocity + Robot.omega_velocity * R_of_robot * cos
    (alpha_rad);
    float v_roller_A = v_x_A * sin(theta_rad - alpha_rad) + v_y_A * cos
    (theta_rad - alpha_rad);
    float v_A = v_roller_A / cos(theta_rad);

    //B
    float v_x_B = Robot.x_velocity - Robot.omega_velocity * R_of_robot * sin
    (alpha_rad);
    float v_y_B = Robot.y_velocity - Robot.omega_velocity * R_of_robot * cos
    (alpha_rad);
    float v_roller_B = -v_x_B * cos(beta_rad - theta_rad) + -v_y_B * sin
    (beta_rad - theta_rad);
    float v_B = v_roller_B / cos(theta_rad);

    //C
    float v_x_C = Robot.x_velocity + Robot.omega_velocity * R_of_robot * sin
    (alpha_rad);
    float v_y_C = Robot.y_velocity - Robot.omega_velocity * R_of_robot * cos
    (alpha_rad);
    float v_roller_C = -v_x_C * sin(theta_rad - alpha_rad) + -v_y_C * cos
    (theta_rad - alpha_rad);
    float v_C = v_roller_C / cos(theta_rad);

    //D
    float v_x_D = Robot.x_velocity + Robot.omega_velocity * R_of_robot * sin
    (alpha_rad);
    float v_y_D = Robot.y_velocity + Robot.omega_velocity * R_of_robot * cos
    (alpha_rad);
    float v_roller_D = v_x_D * cos(beta_rad - theta_rad) + v_y_D * sin
    (beta_rad - theta_rad);
    float v_D = v_roller_D / cos(theta_rad);

    Wheel_condition Wheel = {
        .A_velocity = v_A,
        .B_velocity = v_B,
        .C_velocity = v_C,
        .D_velocity = v_D,};

    return Wheel;
}

Robot_condition Wheel2Robot(Wheel_condition Wheel)
{
    //@@@
    //是上面函数的反解，还没算完

    //我让Chatgpt帮我反解的函数，但是还没检查，我很怀疑有错误

    // 计算机器人在 X 轴和 Y 轴的速度
    float v_x = (Wheel.A_velocity * sin(alpha_rad) + Wheel.B_velocity * sin(beta_rad) +
                 Wheel.C_velocity * sin(alpha_rad) + Wheel.D_velocity * cos(beta_rad)) * cos(theta_rad);

    float v_y = (Wheel.A_velocity * cos(alpha_rad) + Wheel.B_velocity * cos(beta_rad) +
                 Wheel.C_velocity * cos(alpha_rad) + Wheel.D_velocity * sin(beta_rad)) * cos(theta_rad);

    // 计算机器人的角速度
    float omega = (Wheel.A_velocity * R_of_robot * cos(alpha_rad) -
                   Wheel.B_velocity * R_of_robot * cos(beta_rad) +
                   Wheel.C_velocity * R_of_robot * cos(alpha_rad) -
                   Wheel.D_velocity * R_of_robot * cos(beta_rad)) /
                  (2 * R_of_robot * (sin(alpha_rad) + sin(beta_rad)));

    // 创建返回的机器人状态结构体
    Robot_condition Robot = {
        .x_velocity = v_x,
        .y_velocity = v_y,
        .omega_velocity = omega
    };

    return Robot;
}

Robot_condition Setting2Robot(Settings setting)
{
    float v_x = setting.speed * cos(setting.angle * M_PI / 180);
    float v_y = setting.speed * sin(setting.angle * M_PI / 180);

    Robot_condition Robot = {
        .x_velocity = v_x,
        .y_velocity = v_y,
        .omega_velocity = setting.omega
    };

    return Robot;
}