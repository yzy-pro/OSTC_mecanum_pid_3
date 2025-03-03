#include "encoder.h"
#include "tim.h"
#include "main.h"

int Encoder_Getcounter (const int name)
{
    int counter{};
    if (name == 'A')
    {
        counter = __HAL_TIM_GetCounter(&A_ENCODER_TIM);
    }
    else if (name == 'B')
    {
        counter = __HAL_TIM_GetCounter(&B_ENCODER_TIM);
    }
    else if (name == 'C')
    {
        counter = __HAL_TIM_GetCounter(&C_ENCODER_TIM);
    }
    else if (name == 'D')
    {
        counter = __HAL_TIM_GetCounter(&D_ENCODER_TIM);
    }

    return counter;

}

void Encoder_Setcounter (const int name, const int value)
{
    if (name == 'A')
    {
        __HAL_TIM_SetCounter(&A_ENCODER_TIM, value);
    }
    else if (name == 'B')
    {
        __HAL_TIM_SetCounter(&B_ENCODER_TIM, value);
    }
    else if (name == 'C')
    {
        __HAL_TIM_SetCounter(&C_ENCODER_TIM, value);
    }
    else if (name == 'D')
    {
        __HAL_TIM_SetCounter(&D_ENCODER_TIM, value);
    }
}

void Encoder_Reset(void)
{
    Encoder_Setcounter ('A', 0);
    Encoder_Setcounter ('B', 0);
    Encoder_Setcounter ('C', 0);
    Encoder_Setcounter ('D', 0);
}


Wheel_condition Encoder2Wheel(void)
{
    float v_A = Encoder_Getcounter('A') * conversion_factor;
    float v_B = Encoder_Getcounter('B') * conversion_factor;
    float v_C = Encoder_Getcounter('C') * conversion_factor;
    float v_D = Encoder_Getcounter('D') * conversion_factor;
    Encoder_Reset();

    Wheel_condition Wheel={
        .A_velocity = v_A,
        .B_velocity = v_B,
        .C_velocity = v_C,
        .D_velocity = v_D
    };

    return Wheel;
}