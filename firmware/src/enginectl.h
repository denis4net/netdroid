#ifndef ENGINECTL_H
#define ENGINECTL_H
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>

void engine_init();
void engine_go_forward(int time_ms, int speed);
void engine_go_backward(int time_ms, int speed);
void engine_go_forward_continuously(int speed);
void engine_stop();

void engine_turn_right_forward(int angle);
void engine_turn_right_backward(int angle);
void engine_turn_left_forward(int angle);
void engine_turn_left_backward(int angle);

#endif
