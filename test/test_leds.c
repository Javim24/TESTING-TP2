/************************************************************************************************
Copyright (c) 2024, Javier Mosconi <jfmosconi@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file test_leds.c
 * @author Javier Mosconi (jfmosconi@gmail.com)
 * @brief Implementación de funciones de test del módulo led
 * @date 2024-07-18
 *
 * @copyright Copyright (c) 2024
 */

/* === Headers files inclusions =============================================================== */
#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private variable declarations =========================================================== */
static uint16_t puerto_virtual;

/* === Private function declarations =========================================================== */

/* === Public function implementation ========================================================== */

void setUp(void) {
    leds_init(&puerto_virtual);
}

/**
 * @brief Test que prueba que al arrancar el sistema todos los leds
 *        deben estar apagados.
 */
void test_todos_los_leds_deben_arrancar_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;

    leds_init(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Test que prueba el encendido de un solo led.
 */
void test_prender_un_solo_led(void) {
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

/**
 * @brief Test que prueba el encendido de un led y luego su apagado.
 */
void test_prender_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Test que enciende dos leds, apaga uno y verifica que sólo
 *        se apaga el que corresponde, y el otro sigue encendido.
 */
void test_prender_dos_leds_y_apagar_un_led(void) {
    leds_turn_on(3);
    leds_turn_on(7);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 6, puerto_virtual);
}

/**
 * @brief Test que enciende todos los leds juntos.
 */
void test_prender_todos_leds_juntos(void) {
    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

/**
 * @brief Test que enciende y apaga todos los leds juntos.
 */
void test_prender_y_apagar_todos_leds_juntos(void) {
    leds_turn_on_all();
    leds_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Test que enciende un led, consulta el estado usando la función led_is_led_on.
 */
void test_prender_led_consultar_estado_encendido(void) {
    leds_turn_on(3);
    TEST_ASSERT_TRUE(leds_is_led_on(3));
}

/**
 * @brief Test que consulta el estado de un led apagado y verifica que esté apagado.
 */
void test_consultar_estado_led_apagado(void) {
    leds_turn_off(3);
    TEST_ASSERT_FALSE(leds_is_led_on(3));
}

/**
 * @brief Test que enciende dos leds, apaga uno y consulta el estado de ambos.
 */
void test_encender_dos_leds_apagar_uno_consultar_estado(void) {
    leds_turn_on(3);
    leds_turn_on(4);
    leds_turn_off(3);
    TEST_ASSERT_TRUE(leds_is_led_on(4));
    TEST_ASSERT_FALSE(leds_is_led_on(3));
}

/**
 * @brief Test que enciende un led con un número mayor al rango permitido.
 */
void test_encender_led_fuera_de_rango(void) {
    leds_turn_on(17);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/* === End of documentation ==================================================================== */
