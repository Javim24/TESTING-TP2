/*
- Voy a prender un led y volver a apagarlo para ver si se apaga
- Prender dos leds, apagar uno, y ver que solo se apaga el que corresponde y que el otro sigue prendido
- Prender todos los leds juntos
- Prender y apagar todos los leds juntos
- Prender un led, voy a consultar el estado y tiene que figurar como prendido
- Voy a consultar el estado de  un led apagado y tiene que figurar como apagado
- Revisar que los leds estén bien mapeados en memoria
*/


#include "unity.h"
#include "leds.h"

void test_todos_los_leds_deben_arrancar_apagados(void){
    uint16_t puerto_virtual = 0xFFFF;

    leds_init(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}