#ifndef LED_H_
#define LED_H_

void led_init();
int led_blink(const int count, const int delay_ms);
int led_delay(const unsigned int delay_ms);
#endif /* LED_H_ */
