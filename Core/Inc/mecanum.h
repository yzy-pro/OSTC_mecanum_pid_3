#ifndef MECANUM_H
#define MECANUM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "robot.h"

Wheel_condition Robot2Wheel(Robot_condition);
Robot_condition Wheel2Robot(Wheel_condition);

#ifdef __cplusplus
}
#endif

#endif //MECANUM_H
