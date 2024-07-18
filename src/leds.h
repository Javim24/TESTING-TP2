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

#ifndef LEDS_H
#define LEDS_H

/**
 * @file leds.h
 * @author Javier Mosconi (jfmosconi@gmail.com)
 * @brief Declaración de funciones públicas para el driver de leds
 * @date 2024-07-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */


/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */
typedef uint16_t led_port_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Función que inicializa el driver de leds.
 * 
 * @param puerto 
 */
void leds_init(led_port_t * puerto);

/**
 * @brief Enciende un led.
 * 
 * @param led 
 */
void leds_turn_on(uint16_t led);

/**
 * @brief Enciende todos los leds a la vez.
 * 
 */
void leds_turn_on_all(void);

/**
 * @brief Apaga un led.
 * 
 * @param led 
 */
void leds_turn_off(uint16_t led);

/**
 * @brief Apaga todos los leds a la vez.
 * 
 */
void leds_turn_off_all(void);

/**
 * @brief Consulta si un led está encendido.
 * 
 * @param led 
 * @return true si el led está encendido.
 * @return false si el led está apagado.
 */
bool leds_is_led_on(uint16_t led);

/**
 * @brief Devuelve el mapeo en memoria a partir de un número de led.
 * 
 * @param led 
 * @return led_port_t 
 */
led_port_t leds_led_to_mask(uint16_t led);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */