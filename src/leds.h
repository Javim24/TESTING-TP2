#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>

/**
 * @brief 
 * 
 * @param puerto 
 */
void leds_init(uint16_t * puerto);

void leds_turn_on(uint16_t led);

#endif