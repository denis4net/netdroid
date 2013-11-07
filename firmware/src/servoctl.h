#ifndef SERVOCTL_H
#define SERVOCTL_H

#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

enum DIRECTION { DIRECTION_CLOCKWISE, DIRECTION_ANTICLOCKWISE };

typedef struct
{
} servo_t;

void servo_init();
//void servo_spin(servo_t servo, DIRECTION dir);

#endif