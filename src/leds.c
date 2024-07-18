#include "leds.h"

#define LED_OFFSET  1
#define FIRST_BIT   1
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON  0xFFFF

static uint16_t * puerto_virtual;

static uint16_t led_to_mask(uint16_t led){
    return (FIRST_BIT << (led - LED_OFFSET));
}

static void port_set_value(uint16_t value){
    *puerto_virtual = value;
}

static void port_apply_on_mask(uint16_t mask){
    *puerto_virtual |= mask;
}

static void port_apply_off_mask(uint16_t mask){
    *puerto_virtual &= ~mask;
}

static uint16_t port_get_value(void){
    return *puerto_virtual;
}

void leds_init(uint16_t * puerto){
    puerto_virtual = puerto;
    leds_turn_off_all();
}

void leds_turn_on(uint16_t led){
    port_apply_on_mask(led_to_mask(led));
}

void leds_turn_off(uint16_t led){
    port_apply_off_mask(led_to_mask(led));
}

void leds_turn_on_all(){
    port_set_value(ALL_LEDS_ON);
}

void leds_turn_off_all(){
    port_set_value(ALL_LEDS_OFF);
}

bool leds_is_led_on(uint16_t led){
    return (bool) (port_get_value() & led_to_mask(led));
}

uint16_t leds_led_to_mask(uint16_t led){
    return led_to_mask(led);
}