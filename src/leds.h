#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief 
 * 
 * @param puerto 
 */
void leds_init(uint16_t * puerto);

void leds_turn_on(uint16_t led);
void leds_turn_on_all(void);
void leds_turn_off(uint16_t led);
void leds_turn_off_all(void);

bool leds_is_led_on(uint16_t led);

uint16_t leds_led_to_mask(uint16_t led);

#endif