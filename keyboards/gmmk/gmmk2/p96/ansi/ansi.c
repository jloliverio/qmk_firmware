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
    {0, CS4_SW1,  CS5_SW1,  CS6_SW1  },  //  0  NUM  , º
    {0, CS4_SW2,  CS5_SW2,  CS6_SW2  },  //  1  /    , 1
    {0, CS7_SW1,  CS8_SW1,  CS9_SW1  },  //  2  *    , Tab
    {0, CS7_SW2,  CS8_SW2,  CS9_SW2  },  //  3  -    , Q
    {0, CS4_SW3,  CS5_SW3,  CS6_SW3  },  //  4  7    , 2
    {0, CS4_SW4,  CS5_SW4,  CS6_SW4  },  //  5  8    , 3
    {0, CS7_SW3,  CS8_SW3,  CS9_SW3  },  //  6  9    , W
    {0, CS7_SW4,  CS8_SW4,  CS9_SW4  },  //  7  +    , E
    {0, CS4_SW5,  CS5_SW5,  CS6_SW5  },  //  8  4    , 4
    {0, CS4_SW6,  CS5_SW6,  CS6_SW6  },  //  9  5    , 5
    {0, CS7_SW5,  CS8_SW5,  CS9_SW5  },  //  10 6    , R
    {0, CS4_SW7,  CS5_SW7,  CS6_SW7  },  //  11 1    , 6
    {0, CS4_SW8,  CS5_SW8,  CS6_SW8  },  //  12 2    , 7
    {0, CS7_SW7,  CS8_SW7,  CS9_SW7  },  //  13 3    , Y
    {0, CS7_SW8,  CS8_SW8,  CS9_SW8  },  //  14 ENTER, U
    {0, CS4_SW9,  CS5_SW9,  CS6_SW9  },  //  15 0    , 8
    {0, CS7_SW9,  CS8_SW9,  CS9_SW9  },  //  16 .    , I
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
    {0, CS13_SW12,   CS14_SW12,   CS15_SW12},   //   7, k70, F7
    {0, CS13_SW12,   CS14_SW12,   CS15_SW12},   //   8, k80, F8
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //   9, k90, F9
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  10, ka0, F10
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  11, kb0, F11
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  12, kc0, F12
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  13, kd0, Printscreen
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  14, k06, Delete
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  15, k16, Insert
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  16, k26, Page Up
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  17, k36, Page Down

    //{0, CS4_SW1,   CS5_SW1,   CS6_SW1},   //*  18, k01, `
    //{0, CS4_SW2,   CS5_SW2,   CS6_SW2},   //*  19, k11, 1
    //{0, CS4_SW3,   CS5_SW3,   CS6_SW3},   //*  20, k21, 2
    //{0, CS4_SW4,   CS5_SW4,   CS6_SW4},   //*  21, k31, 3
    //{0, CS4_SW5,   CS5_SW5,   CS6_SW5},   //*  22, k41, 4
    //{0, CS4_SW6,   CS5_SW6,   CS6_SW6},   //*  23, k51, 5
    //{0, CS4_SW7,   CS5_SW7,   CS6_SW7},   //*  24, k61, 6
    //{0, CS4_SW8,   CS5_SW8,   CS6_SW8},   //*  25, k71, 7
    //{0, CS4_SW9,   CS5_SW9,   CS6_SW9},   //*  26, k81, 8
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  27, k91, 9
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  28, ka1, 0
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  29, kb1, -
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  30, kc1, =
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  31, kd1, Backspace
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  32, k46, Num Lock
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  33, k56, Num /
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  34, k66, Num *
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  35, k76, Num -

    //{0, CS7_SW1,   CS8_SW1,   CS9_SW1},   //*  36, k02, Tab
    //{0, CS7_SW2,   CS8_SW2,   CS9_SW2},   //*  37, k12, Q
    //{0, CS7_SW3,   CS8_SW3,   CS9_SW3},   //*  38, k22, W
    //{0, CS7_SW4,   CS8_SW4,   CS9_SW4},   //*  39, k32, E
    //{0, CS7_SW5,   CS8_SW5,   CS9_SW5},   //*  40, k42, R
    {0, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  41, k52, T
    //{0, CS7_SW7,   CS8_SW7,   CS9_SW7},   //*  42, k62, Y
    //{0, CS7_SW8,   CS8_SW8,   CS9_SW8},   //*  43, k72, U
    //{0, CS7_SW9,   CS8_SW9,   CS9_SW9},   //*  44, k82, I
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  45, k92, O
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  46, ka2, P
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  47, kb2, [
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  48, kc2, ]
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  49, kd3, "\\"
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  50, k86, Num 7
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  51, k96, Num 8
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  52, ka6, Num 9
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  53, kb6, Num +

    //{0, CS10_SW1,  CS11_SW1,  CS12_SW1},  //*  54, k03, Caps Lock
    //{0, CS10_SW2,  CS11_SW2,  CS12_SW2},  //*  55, k13, A
    //{0, CS10_SW3,  CS11_SW3,  CS12_SW3},  //*  56, k23, S
    //{0, CS10_SW4,  CS11_SW4,  CS12_SW4},  //*  57, k33, D
    //{0, CS10_SW5,  CS11_SW5,  CS12_SW5},  //*  58, k43, F
    //{0, CS10_SW6,  CS11_SW6,  CS12_SW6},  //*  59, k53, G
    //{0, CS10_SW7,  CS11_SW7,  CS12_SW7},  //*  60, k63, H
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  61, k73, J
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  62, k83, K
    {0, CS13_SW12, CS14_SW12, CS15_SW12}, //  63, k93, L
    {0, CS13_SW12, CS14_SW12, CS15_SW12}, //  64, ka3, ;
    {0, CS13_SW12, CS14_SW12, CS15_SW12}, //  65, kb3, '
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  66, kc3, Enter
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  67, ka7, Num 4
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  68, kb7, Num 5
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  69, kc7, Num 6

    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  70, k04, Shift_L
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  71, k24, Z
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  72, k34, X
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  73, k44, C
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  74, k54, V
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  75, k64, B
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  76, k74, N
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  77, k84, M
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  78, k94, ,
    {0, CS13_SW12, CS14_SW12, CS15_SW12}, //  79, ka4, .
    {0, CS13_SW12, CS14_SW12, CS15_SW12}, //  80, kb4, /
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  81, kd4, Shift_R
    {1, CS13_SW12,   CS14_SW12,   CS15_SW12},   //  82, k17, Up
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  83, k67, Num 1
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  84, k77, Num 2
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  85, k87, Num 3
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  86, k97, Enter_R

    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  87, k05, Ctrl_L
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  88, k15, Win_L
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  89, k25, Alt_L
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  90, k65, Space
    {0, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  91, k95, Alt_R
    {0, CS13_SW12, CS14_SW12, CS15_SW12}, //  92, ka5, FN
    {0, CS13_SW12, CS14_SW12, CS15_SW12}, //  93, kc5, Ctrl_R
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  94, k07, Left
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  95, k27, Down
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  96, k37, Right
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  97, k47, Num 0
    {1, CS13_SW12,  CS14_SW12,  CS15_SW12},  //  98, k57, Num .

    {1, CS13_SW1,  CS14_SW1,  CS15_SW1},  //  101, LED 1
    {1, CS13_SW2,  CS14_SW2,  CS15_SW2},  //  102, LED 2
    {1, CS13_SW3,  CS14_SW3,  CS15_SW3},  //  103, LED 3
    {1, CS13_SW4,  CS14_SW4,  CS15_SW4},  //  104, LED 4
    {1, CS13_SW5,  CS14_SW5,  CS15_SW5},  //  105, LED 5
    {1, CS13_SW6,  CS14_SW6,  CS15_SW6},  //  106, LED 6
    {1, CS13_SW7,  CS14_SW7,  CS15_SW7},  //  107, LED 7
    {1, CS13_SW8,  CS14_SW8,  CS15_SW8},  //  108, LED 8
    {1, CS13_SW9,  CS14_SW9,  CS15_SW9},  //  109, LED 9
    {1, CS13_SW10, CS14_SW10, CS15_SW10}, //  110, LED 10
    {1, CS16_SW1,  CS17_SW1,  CS18_SW1},  //  111, LED 11
    {1, CS16_SW2,  CS17_SW2,  CS18_SW2},  //  112, LED 12
    {1, CS16_SW3,  CS17_SW3,  CS18_SW3},  //  113, LED 13
    {1, CS16_SW4,  CS17_SW4,  CS18_SW4},  //  114, LED 14
    {1, CS16_SW5,  CS17_SW5,  CS18_SW5},  //  115, LED 15
    {1, CS16_SW6,  CS17_SW6,  CS18_SW6},  //  116, LED 16
    {1, CS16_SW7,  CS17_SW7,  CS18_SW7},  //  117, LED 17
    {1, CS16_SW8,  CS17_SW8,  CS18_SW8},  //  118, LED 18
    {1, CS16_SW9,  CS17_SW9,  CS18_SW9},  //  119, LED 19
    {1, CS16_SW10, CS17_SW10, CS18_SW10}  //  120, LED 20
};

#undef ___
#define ___ NO_LED
#define RGB_LAYOUT LAYOUT

led_config_t g_led_config = {{
    { 17,   0,   2,  24, ___, ___, ___, ___},
    { 18,   1,   3,  25, ___, ___, ___, ___},
    { 19,   4,   6,  26, ___, ___, ___, ___},
    { 20,   5,   7,  27, ___, ___, ___, ___},
    { 21,   8,  10,  28, ___, ___, ___, ___},
    { 22,   9, ___,  29, ___, ___, ___, ___},
    { 23,  11,  13,  30, ___, ___, ___, ___},
    {___,  12,  14, ___, ___, ___, ___, ___},
    {___,  15,  16, ___, ___, ___, ___, ___},
    {___, ___, ___, ___, ___, ___, ___, ___},
    {___, ___, ___, ___, ___, ___, ___, ___},
    {___, ___, ___, ___, ___, ___, ___, ___},
    {___, ___, ___, ___, ___, ___, ___, ___},
    {___, ___, ___, ___, ___, ___, ___, ___}
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