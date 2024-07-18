#include "leds.h"

static uint16_t * puerto_virtual;

void leds_init(uint16_t * puerto){
    puerto_virtual = puerto;
    *puerto_virtual = 0x0000;
}

void leds_turn_on(uint16_t led){
    *puerto_virtual |= (1 << (led - 1));
}

void leds_turn_off(uint16_t led){
    *puerto_virtual &= ~(1 << (led - 1));
}

void leds_turn_on_all(){
    *puerto_virtual = 0xFFFF;
}