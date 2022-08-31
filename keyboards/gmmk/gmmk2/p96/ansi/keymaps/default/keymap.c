/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "analog.h"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      NUM      /       *       -
//      7        8       9       +
//      4        5       6       CALC
//      1        2       3       RET
//      0                        .

  [0] = LAYOUT( 
    KC_NUM,  KC_PSLS,   KC_PAST,   KC_PMNS, 
		KC_P7,   KC_P8,     KC_P9,     KC_PPLS, 
		KC_P4,   MO(1),     KC_P6,     KC_CALC, 
		KC_P1,   KC_P2,     KC_P3,     KC_PENT, 
		KC_P0,                         KC_PDOT 
	),
  [1] = LAYOUT( 
    KC_NUM,  KC_PSLS,   KC_PAST,   KC_PMNS, 
		KC_P7,   KC_P8,     KC_P9,     KC_PPLS, 
		KC_P4,   _______,   KC_P6,     KC_CALC, 
		KC_P1,   KC_P2,     KC_P3,     KC_PENT, 
		KC_P0,                         QK_BOOT 
	)
};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
#endif


// uint8_t divisor = 0;

// void slider(void) {
//     if (divisor++) { // only run the slider function 1/256 times it's called
//         return;
//     }

//     xprintf(analogReadPin(SLIDER_PIN));
// }

// void matrix_scan_user(void) {
//     slider();
// }
