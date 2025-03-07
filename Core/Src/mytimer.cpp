#include "mytimer.h"
#include "stm32f1xx_hal.h"

bool encoder_timer()
{
    static uint32_t encoderTick = 0;
    if (uwTick - encoderTick < 10)
    {
        return false;
    }

    encoderTick = uwTick;
    return true;
}
