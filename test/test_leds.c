#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

void setUp(void) {
    leds_init(&puerto_virtual);
}

// Al arrancar el sistema todos los leds deben estar apagados
void test_todos_los_leds_deben_arrancar_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;

    leds_init(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Después de arrancar el sistema, con todos los leds apagados, voy a prender un led cualquiera
void test_prender_un_solo_led(void) {
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

// Voy a prender un led y volver a apagarlo para ver si se apaga
void test_prender_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Prender dos leds, apagar uno, y ver que solo se apaga el que corresponde y que el otro sigue
// prendido
void test_prender_dos_leds_y_apagar_un_led(void) {
    leds_turn_on(3);
    leds_turn_on(7);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 6, puerto_virtual);
}

// Prender todos los leds juntos
void test_prender_todos_leds_juntos(void) {
    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

// Prender y apagar todos los leds juntos
void test_prender_y_apagar_todos_leds_juntos(void) {
    leds_turn_on_all();
    leds_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Prender un led, voy a consultar el estado y tiene que figurar como prendido
void test_prender_led_consultar_estado_encendido(void) {
    leds_turn_on(3);
    TEST_ASSERT_TRUE(leds_is_led_on(3));
}

// Voy a consultar el estado de  un led apagado y tiene que figurar como apagado
void test_consultar_estado_led_apagado(void) {
    leds_turn_off(3);
    TEST_ASSERT_FALSE(leds_is_led_on(3));
}

// Revisar que los leds estén bien mapeados en memoria
void test_revisar_mapeo_de_leds_en_memoria(void) {
    TEST_ASSERT_EQUAL_HEX16(1 << 2, leds_led_to_mask(3));
}

// Encender dos leds, apagar uno y consultar el estado de ambos
void test_encender_dos_leds_apagar_uno_consultar_estado(void) {
    leds_turn_on(3);
    leds_turn_on(4);
    leds_turn_off(3);
    TEST_ASSERT_TRUE(leds_is_led_on(4));
    TEST_ASSERT_FALSE(leds_is_led_on(3));
}

// Encender un led con número mayor al máximo (16)
void test_encender_led_fuera_de_rango(void) {
    leds_turn_on(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}
