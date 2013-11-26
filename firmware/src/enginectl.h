#ifndef ENGINECTL_H
#define ENGINECTL_H
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

enum ENGINE_DIRECTION {  FORWARD, BACKWARD };

typedef struct
{
} engine_t;

void engine_init();
void engine_go_forward(int time, int speed);
void engine_go_backward(int time, int speed);
void engine_turn_right_forward(int angle);
void engine_turn_right_backward(int angle);
void engine_turn_left_forward(int angle);
void engine_turn_left_backward(int angle);

#endif
