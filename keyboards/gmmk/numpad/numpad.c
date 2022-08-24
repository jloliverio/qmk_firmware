/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "numpad.h"
#define RGB_MATRIX_ENABLE
#ifdef RGB_MATRIX_ENABLE

const aw_led g_aw_leds[DRIVER_LED_TOTAL] = {
/* Each AW20216 channel is controlled by a register at some offset between 0x00
 * and 0xD7 inclusive.
 * See drivers/awinic/aw20216.h for the mapping between register offsets and
 * driver pin locations.
 *   driver
 *   |  R location
 *   |  |         G location
 *   |  |         |         B location
 *   |  |         |         | */
    {0, CS4_SW1,  CS5_SW1,  CS6_SW1  },  //  0  NUM
    {0, CS4_SW2,  CS5_SW2,  CS6_SW2  },  //  1  /
    {0, CS7_SW1,  CS8_SW1,  CS9_SW1  },  //  2  *
    {0, CS7_SW2,  CS8_SW2,  CS9_SW2  },  //  3  -
    {0, CS4_SW3,  CS5_SW3,  CS6_SW3  },  //  4  7
    {0, CS4_SW4,  CS5_SW4,  CS6_SW4  },  //  5  8
    {0, CS7_SW3,  CS8_SW3,  CS9_SW3  },  //  6  9
    {0, CS7_SW4,  CS8_SW4,  CS9_SW4  },  //  7  +
    {0, CS4_SW5,  CS5_SW5,  CS6_SW5  },  //  8  4
    {0, CS4_SW6,  CS5_SW6,  CS6_SW6  },  //  9  5
    {0, CS7_SW5,  CS8_SW5,  CS9_SW5  },  //  10 6
    {0, CS4_SW7,  CS5_SW7,  CS6_SW7  },  //  11 1
    {0, CS4_SW8,  CS5_SW8,  CS6_SW8  },  //  12 2
    {0, CS7_SW7,  CS8_SW7,  CS9_SW7  },  //  13 3
    {0, CS7_SW8,  CS8_SW8,  CS9_SW8  },  //  14 ENTER
    {0, CS4_SW9,  CS5_SW9,  CS6_SW9  },  //  15 0
    {0, CS7_SW9,  CS8_SW9,  CS9_SW9  },  //  16 .
    {0, CS1_SW1,  CS2_SW1,  CS3_SW1  },  //  17 LED18
    {0, CS1_SW2,  CS2_SW2,  CS3_SW2  },  //  18 LED19
    {0, CS1_SW3,  CS2_SW3,  CS3_SW3  },  //  19 LED20
    {0, CS1_SW4,  CS2_SW4,  CS3_SW4  },  //  20 LED21
    {0, CS1_SW5,  CS2_SW5,  CS3_SW5  },  //  21 LED22
    {0, CS1_SW6,  CS2_SW6,  CS3_SW6  },  //  22 LED23
    {0, CS1_SW7,  CS2_SW7,  CS3_SW7  },  //  23 LED24
    {0, CS10_SW1, CS11_SW1, CS12_SW1 },  //  24 LED27
    {0, CS10_SW2, CS11_SW2, CS12_SW2 },  //  25 LED28
    {0, CS10_SW3, CS11_SW3, CS12_SW3 },  //  26 LED29
    {0, CS10_SW4, CS11_SW4, CS12_SW4 },  //  27 LED30
    {0, CS10_SW5, CS11_SW5, CS12_SW5 },  //  28 LED31
    {0, CS10_SW6, CS11_SW6, CS12_SW6 },  //  29 LED32
    {0, CS10_SW7, CS11_SW7, CS12_SW7 },  //  30 LED33
};

#undef ___
#define ___ NO_LED
#define RGB_LAYOUT LAYOUT

led_config_t g_led_config = {{
    /* RGB_LAYOUT
            //   (0,  1,  2,  3,  4,  5,  */
	/* 			 6,  7,  8,  9,  10, 11, */
	/* 			 12, 13, 14, 15, 16, 17, */
	/* 			 18, 19, 20, 21, 22, 23, */
	/* 			 24, 25, 26, 27, 28, 29, */
	/* 			 30, 31, 32) */
    { 0,  1,  2,  3},
    { 4,  5,  6,  7},
    { 8,  9,  10, 11},
    { 12, 13, 14, 15},
    { 16,         17}
}, {
    {0,    0 },  //  0  LED0
    {44,   0 },  //  1  NUM
    {88,   0 },  //  2  /
    {96,   0 },  //  3  *
    {132,  0 },  //  4  -
    {176,  0 },  //  5  LED5
    {0,   10 },  //  6  LED6
    {44,  10 },  //  7  7
    {88,  10 },  //  8  8
    {96,  10 },  //  9  9
    {132, 10 },  //  10 +
    {176, 10 },  //  11 LED11
    {0,   20 },  //  12 LED12
    {44,  20 },  //  13 LED13
    {88,  20 },  //  14 LED14
    {96,  20 },  //  15 LED15
    {132, 20 },  //  16 LED16
    {176, 20 },  //  17 LED17
    {0,   30 },  //  18 LED18
    {44,  30 },  //  19 4
    {88,  30 },  //  20 5
    {96,  30 },  //  21 6
    {132, 30 },  //  22 CALC
    {176, 30 },  //  23 LED23
    {0,   40 },  //  24 LED24
    {44,  40 },  //  25 1
    {88,  40 },  //  26 2
    {96,  40 },  //  27 3
    {132, 40 },  //  28 ENTER
    {176, 40 },  //  29 LED29
    {0,   50 },  //  30 LED30
    {44,  50 },  //  31 LED31
    {88,  50 }  //   32 LED32
}, {
    4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4,
	4, 4, 4, 4, 4, 4,
    4, 4, 4
} };
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (!clockwise) {
        tap_code_delay(KC_VOLU, 10);
    } else {
        tap_code_delay(KC_VOLD, 10);
    }
    return false;
}
#endif