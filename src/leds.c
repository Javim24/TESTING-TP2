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
 * @file leds.c
 * @author Javier Mosconi (jfmosconi@gmail.com)
 * @brief Implementación de funciones públicas y privadas del driver de leds
 * @date 2024-07-18
 *
 * @copyright Copyright (c) 2024
 *
 */

/* === Headers files inclusions =============================================================== */
#include "leds.h"

/* === Macros definitions ====================================================================== */
#define LED_OFFSET   1
#define FIRST_BIT    1
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON  0xFFFF

/* === Private variable declarations =========================================================== */
/**
 * @brief Variable privada que almacena el puerto de leds.
 */
static led_port_t * puerto_virtual;

/* === Private function declarations =========================================================== */
/**
 * @brief Genera una máscara para la posición en memoria de cada led.
 *
 * @param led: Número de led del que se quiere obtener la máscara.
 * @return led_port_t
 */
static led_port_t led_to_mask(uint16_t led) {
    return (FIRST_BIT << (led - LED_OFFSET));
}

/**
 * @brief Cambia el estado del puerto al que diga el parámetro value.
 *
 * @param value: Valor que se quiere configurar en el puerto.
 */
static void port_set_value(led_port_t value) {
    *puerto_virtual = value;
}

/**
 * @brief Aplica una máscara para encender un led.
 *
 * @param mask: Máscara que se aplica para el encendido de leds.
 */
static void port_apply_on_mask(led_port_t mask) {
    *puerto_virtual |= mask;
}

/**
 * @brief Aplica una máscara para apagar un led.
 *
 * @param mask: Máscara que se aplica para el apagado de leds.
 */
static void port_apply_off_mask(led_port_t mask) {
    *puerto_virtual &= ~mask;
}

/**
 * @brief Devuelve el estado actual del puerto.
 *
 * @return led_port_t: Valor que está almacenado en el puerto.
 */
static led_port_t port_get_value(void) {
    return *puerto_virtual;
}

/* === Public function implementation ========================================================== */

void leds_init(led_port_t * puerto) {
    puerto_virtual = puerto;
    leds_turn_off_all();
}

void leds_turn_on(uint16_t led) {
    port_apply_on_mask(led_to_mask(led));
}

void leds_turn_off(uint16_t led) {
    port_apply_off_mask(led_to_mask(led));
}

void leds_turn_on_all() {
    port_set_value(ALL_LEDS_ON);
}

void leds_turn_off_all() {
    port_set_value(ALL_LEDS_OFF);
}

bool leds_is_led_on(uint16_t led) {
    return (bool)(port_get_value() & led_to_mask(led));
}

led_port_t leds_led_to_mask(uint16_t led) {
    return led_to_mask(led);
}

/* === End of documentation ==================================================================== */
