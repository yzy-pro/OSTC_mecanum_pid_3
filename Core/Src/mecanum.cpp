#include "mecanum.h"
#include "robot.h"
#include "math.h"

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
    //是上面函数的反解，还没算完
}