/*
- Prender dos leds, apagar uno, y ver que solo se apaga el que corresponde y que el otro sigue prendido
- Prender todos los leds juntos
- Prender y apagar todos los leds juntos
- Prender un led, voy a consultar el estado y tiene que figurar como prendido
- Voy a consultar el estado de  un led apagado y tiene que figurar como apagado
- Revisar que los leds estén bien mapeados en memoria
*/


#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

void setUp(void){
    leds_init(&puerto_virtual);
}

// Al arrancar el sistema todos los leds deben estar apagados
void test_todos_los_leds_deben_arrancar_apagados(void){
    uint16_t puerto_virtual = 0xFFFF;

    leds_init(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Después de arrancar el sistema, con todos los leds apagados, voy a prender un led cualquiera
void test_prender_un_solo_led(void){
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// Voy a prender un led y volver a apagarlo para ver si se apaga
void test_prender_apagar_un_solo_led(void){
    leds_turn_on(3);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}