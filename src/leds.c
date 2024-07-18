#include "leds.h"

#define LED_OFFSET  1
#define FIRST_BIT   1
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON  0xFFFF

static uint16_t * puerto_virtual;

static uint16_t led_to_mask(uint16_t led){
    return (FIRST_BIT << (led - LED_OFFSET));
}

void leds_init(uint16_t * puerto){
    puerto_virtual = puerto;
    *puerto_virtual = ALL_LEDS_OFF;
}

void leds_turn_on(uint16_t led){
    *puerto_virtual |= led_to_mask(led);
}

void leds_turn_off(uint16_t led){
    *puerto_virtual &= ~led_to_mask(led);
}

void leds_turn_on_all(){
    *puerto_virtual = ALL_LEDS_ON;
}

void leds_turn_off_all(){
    *puerto_virtual = ALL_LEDS_OFF;
}

bool leds_is_led_on(uint16_t led){
    return (bool) (*puerto_virtual & led_to_mask(led));
}

uint16_t leds_led_to_mask(uint16_t led){
    return led_to_mask(led);
}