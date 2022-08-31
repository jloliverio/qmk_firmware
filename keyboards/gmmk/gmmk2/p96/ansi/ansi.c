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

#include "ansi.h"

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
    {0, CS4_SW1,  CS5_SW1,  CS6_SW1  },  //  0  NUM  , º   <- Key Esc
    {0, CS4_SW2,  CS5_SW2,  CS6_SW2  },  //  1  /    , 1   <- Key F1
    {0, CS7_SW1,  CS8_SW1,  CS9_SW1  },  //  2  *    , Tab <- Key F2
    {0, CS7_SW2,  CS8_SW2,  CS9_SW2  },  //  3  -    , Q   <- Key F3
    {0, CS4_SW3,  CS5_SW3,  CS6_SW3  },  //  4  7    , 2   <- Key º
    {0, CS4_SW4,  CS5_SW4,  CS6_SW4  },  //  5  8    , 3   <- Key 1
    {0, CS7_SW3,  CS8_SW3,  CS9_SW3  },  //  6  9    , W   <- Key 2
    {0, CS7_SW4,  CS8_SW4,  CS9_SW4  },  //  7  +    , E   <- Key 3
    {0, CS4_SW5,  CS5_SW5,  CS6_SW5  },  //  8  4    , 4   <- Key Tab
    {0, CS4_SW6,  CS5_SW6,  CS6_SW6  },  //  9  5    , 5   <- Key Q
    {0, CS7_SW5,  CS8_SW5,  CS9_SW5  },  //  10 6    , R   <- Key W
    {0, CS4_SW7,  CS5_SW7,  CS6_SW7  },  //  11 1    , 6   <- Key Caps Lock
    {0, CS4_SW8,  CS5_SW8,  CS6_SW8  },  //  12 2    , 7   <- Key A
    {0, CS7_SW7,  CS8_SW7,  CS9_SW7  },  //  13 3    , Y   <- Key S
    {0, CS7_SW8,  CS8_SW8,  CS9_SW8  },  //  14 ENTER, U   <- Key D
    {0, CS4_SW9,  CS5_SW9,  CS6_SW9  },  //  15 0    , 8   <- Key Shift_L
    {0, CS7_SW9,  CS8_SW9,  CS9_SW9  },  //  16 .    , I   <- Key C
    {0, CS1_SW1,  CS2_SW1,  CS3_SW1  },  //  17 LED18, Esc
    {0, CS1_SW2,  CS2_SW2,  CS3_SW2  },  //  18 LED19, F1
    {0, CS1_SW3,  CS2_SW3,  CS3_SW3  },  //  19 LED20, F2
    {0, CS1_SW4,  CS2_SW4,  CS3_SW4  },  //  20 LED21, F3
    {0, CS1_SW5,  CS2_SW5,  CS3_SW5  },  //  21 LED22, F4
    {0, CS1_SW6,  CS2_SW6,  CS3_SW6  },  //  22 LED23, F5
    {0, CS1_SW7,  CS2_SW7,  CS3_SW7  },  //  23 LED24, F6
    {0, CS10_SW1, CS11_SW1, CS12_SW1 },  //  24 LED27, Caps Lock
    {0, CS10_SW2, CS11_SW2, CS12_SW2 },  //  25 LED28, A
    {0, CS10_SW3, CS11_SW3, CS12_SW3 },  //  26 LED29, S
    {0, CS10_SW4, CS11_SW4, CS12_SW4 },  //  27 LED30, D
    {0, CS10_SW5, CS11_SW5, CS12_SW5 },  //  28 LED31, F
    {0, CS10_SW6, CS11_SW6, CS12_SW6 },  //  29 LED32, G
    {0, CS10_SW7, CS11_SW7, CS12_SW7 },  //  30 LED33, H
    //{0, CS1_SW1,   CS2_SW1,   CS3_SW1},   //*   0, k00, Esc
    //{0, CS1_SW2,   CS2_SW2,   CS3_SW2},   //*   1, k10, F1
    //{0, CS1_SW3,   CS2_SW3,   CS3_SW3},   //*   2, k20, F2
    //{0, CS1_SW4,   CS2_SW4,   CS3_SW4},   //*   3, k30, F3
    //{0, CS1_SW5,   CS2_SW5,   CS3_SW5},   //*   4, k40, F4
    //{0, CS1_SW6,   CS2_SW6,   CS3_SW6},   //*   5, k50, F5
    //{0, CS1_SW7,   CS2_SW7,   CS3_SW7},   //*   6, k60, F6

    //{0, CS4_SW1,   CS5_SW1,   CS6_SW1},   //*  18, k01, `
    //{0, CS4_SW2,   CS5_SW2,   CS6_SW2},   //*  19, k11, 1
    //{0, CS4_SW3,   CS5_SW3,   CS6_SW3},   //*  20, k21, 2
    //{0, CS4_SW4,   CS5_SW4,   CS6_SW4},   //*  21, k31, 3
    //{0, CS4_SW5,   CS5_SW5,   CS6_SW5},   //*  22, k41, 4
    //{0, CS4_SW6,   CS5_SW6,   CS6_SW6},   //*  23, k51, 5
    //{0, CS4_SW7,   CS5_SW7,   CS6_SW7},   //*  24, k61, 6
    //{0, CS4_SW8,   CS5_SW8,   CS6_SW8},   //*  25, k71, 7
    //{0, CS4_SW9,   CS5_SW9,   CS6_SW9},   //*  26, k81, 8

    //{0, CS7_SW1,   CS8_SW1,   CS9_SW1},   //*  36, k02, Tab
    //{0, CS7_SW2,   CS8_SW2,   CS9_SW2},   //*  37, k12, Q
    //{0, CS7_SW3,   CS8_SW3,   CS9_SW3},   //*  38, k22, W
    //{0, CS7_SW4,   CS8_SW4,   CS9_SW4},   //*  39, k32, E
    //{0, CS7_SW5,   CS8_SW5,   CS9_SW5},   //*  40, k42, R
    //{0, CS7_SW7,   CS8_SW7,   CS9_SW7},   //*  42, k62, Y
    //{0, CS7_SW8,   CS8_SW8,   CS9_SW8},   //*  43, k72, U
    //{0, CS7_SW9,   CS8_SW9,   CS9_SW9},   //*  44, k82, I

    //{0, CS10_SW1,  CS11_SW1,  CS12_SW1},  //*  54, k03, Caps Lock
    //{0, CS10_SW2,  CS11_SW2,  CS12_SW2},  //*  55, k13, A
    //{0, CS10_SW3,  CS11_SW3,  CS12_SW3},  //*  56, k23, S
    //{0, CS10_SW4,  CS11_SW4,  CS12_SW4},  //*  57, k33, D
    //{0, CS10_SW5,  CS11_SW5,  CS12_SW5},  //*  58, k43, F
    //{0, CS10_SW6,  CS11_SW6,  CS12_SW6},  //*  59, k53, G
    //{0, CS10_SW7,  CS11_SW7,  CS12_SW7},  //*  60, k63, H
};

#undef ___
#define ___ NO_LED
#define RGB_LAYOUT LAYOUT

led_config_t g_led_config = {{
    { 0,   1,   2,   3  },
    { 4,   5,   6,   7  },
    { 8,   9,   10,  ___},
    { 11,  12,  13,  14 },
    { 15,  ___, ___, 16 }
}, {
    {45,  0  },  //  0  NUM
    {90,  0  },  //  1  /
    {134, 0  },  //  2  *
    {179, 0  },  //  3  -
    {45,  16 },  //  4  7
    {90,  16 },  //  5  8
    {134, 16 },  //  6  9
    {179, 24 },  //  7  +
    {45,  32 },  //  8  4
    {90,  32 },  //  9  5
    {134, 32 },  //  10 6
    {45,  48 },  //  11 1
    {90,  48 },  //  12 2
    {134, 48 },  //  13 3
    {179, 56 },  //  14 ENTER
    {67,  64 },  //  15 0
    {134, 64 },  //  16 .
    {0,   0  },  //  17 LED18
    {0,   11 },  //  18 LED19
    {0,   21 },  //  19 LED20
    {0,   32 },  //  20 LED21
    {0,   43 },  //  21 LED22
    {0,   53 },  //  22 LED23
    {0,   64 },  //  23 LED24
    {224, 0  },  //  24 LED27
    {224, 11 },  //  25 LED28
    {224, 21 },  //  26 LED29
    {224, 32 },  //  27 LED30
    {224, 43 },  //  28 LED31
    {224, 53 },  //  29 LED32
    {224, 64 }   //  30 LED33
}, {
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4,
    4, 4, 4, 4,
    4,       4,
    2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2
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

void keyboard_pre_init_user(void) {
#ifdef RGB_MATRIX_PW_EN
    //setPinOutput_writeHigh(RGB_MATRIX_PW_EN);
    setPinOutput(RGB_MATRIX_PW_EN);
    writePinHigh(RGB_MATRIX_PW_EN);
#endif
}

void keyboard_post_init_user() {
  //rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  //rgblight_sethsv_noeeprom(HSV_MAGENTA); // sets the color to teal/cyan without saving
  //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    if (rgb_matrix_is_enabled()) {
        #ifdef CONSOLE_ENABLE
          uprintf("RGB is enabled \n");
          uprintf("RGB MATRIX MODE: ");
          uprintf("%u \n",rgb_matrix_get_mode());
          uprintf("RGB MATRIX VALUE: ");
          uprintf("%u \n",rgb_matrix_get_val());
        #endif
    }
    else if(!rgb_matrix_is_enabled()) {
        #ifdef CONSOLE_ENABLE
          uprintf("RGB is NOT enabled \n");
        #endif
    }
    // uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
    return true;
}
