/* Copyright 2022 DZTECH <moyi4681@live.cn>
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

 #include "quantum.h"
 #include "rgb_matrix.h"

#ifdef RGB_MATRIX_ENABLE

const is31fl3737_led_t PROGMEM g_is31fl3737_leds[IS31FL3737_LED_COUNT] = {
    { 1, SW11_CS12, SW10_CS12, SW12_CS12 },
    { 1, SW11_CS11, SW10_CS11, SW12_CS11 },
    { 1, SW11_CS10, SW10_CS10, SW12_CS10 },
    { 1, SW11_CS9,  SW10_CS9,  SW12_CS9 },
    { 1, SW11_CS8,  SW10_CS8,  SW12_CS8 },
    { 1, SW11_CS7,  SW10_CS7,  SW12_CS7 },
    { 1, SW11_CS6,  SW10_CS6,  SW12_CS6 },
    { 1, SW11_CS5,  SW10_CS5,  SW12_CS5 },
    { 1, SW11_CS4,  SW10_CS4,  SW12_CS4 },
    { 1, SW11_CS3,  SW10_CS3,  SW12_CS3 },
    { 1, SW11_CS2,  SW10_CS2,  SW12_CS2 },
    { 1, SW11_CS1,  SW10_CS1,  SW12_CS1 },
    { 1, SW8_CS1,  SW7_CS1,  SW9_CS1 },
    { 1, SW8_CS2,  SW7_CS2,  SW9_CS2 },
    { 1, SW8_CS3,  SW7_CS3,  SW9_CS3 },

    { 0, SW2_CS12, SW1_CS12, SW3_CS12 },
    { 0, SW2_CS11, SW1_CS11, SW3_CS11 },
    { 0, SW2_CS10, SW1_CS10, SW3_CS10 },
    { 0, SW2_CS9,  SW1_CS9,  SW3_CS9 },
    { 0, SW2_CS8,  SW1_CS8,  SW3_CS8 },
    { 0, SW2_CS7,  SW1_CS7,  SW3_CS7 },
    { 0, SW2_CS6,  SW1_CS6,  SW3_CS6 },
    { 0, SW2_CS5,  SW1_CS5,  SW3_CS5 },
    { 0, SW2_CS4,  SW1_CS4,  SW3_CS4 },
    { 0, SW2_CS3,  SW1_CS3,  SW3_CS3 },
    { 0, SW2_CS2,  SW1_CS2,  SW3_CS2 },
    { 0, SW2_CS1,  SW1_CS1,  SW3_CS1 },
    { 1, SW8_CS6,  SW7_CS6,  SW9_CS6 },
    { 1, SW8_CS5,  SW7_CS5,  SW9_CS5 },
    { 1, SW8_CS4,  SW7_CS4,  SW9_CS4 },

    { 0, SW5_CS12, SW4_CS12, SW6_CS12 },
    { 0, SW5_CS11, SW4_CS11, SW6_CS11 },
    { 0, SW5_CS10, SW4_CS10, SW6_CS10 },
    { 0, SW5_CS9,  SW4_CS9,  SW6_CS9 },
    { 0, SW5_CS8,  SW4_CS8,  SW6_CS8 },
    { 0, SW5_CS7,  SW4_CS7,  SW6_CS7 },
    { 0, SW5_CS6,  SW4_CS6,  SW6_CS6 },
    { 0, SW5_CS5,  SW4_CS5,  SW6_CS5 },
    { 0, SW5_CS4,  SW4_CS4,  SW6_CS4 },
    { 0, SW5_CS3,  SW4_CS3,  SW6_CS3 },
    { 0, SW5_CS2,  SW4_CS2,  SW6_CS2 },
    { 0, SW5_CS1,  SW4_CS1,  SW6_CS1 },
    { 1, SW8_CS7,  SW7_CS7,  SW9_CS7 },
    { 1, SW8_CS8,  SW7_CS8,  SW9_CS8 },

    { 0, SW8_CS12, SW7_CS12, SW9_CS12 },
    { 0, SW8_CS11, SW7_CS11, SW9_CS11 },
    { 0, SW8_CS10, SW7_CS10, SW9_CS10 },
    { 0, SW8_CS9,  SW7_CS9,  SW9_CS9 },
    { 0, SW8_CS8,  SW7_CS8,  SW9_CS8 },
    { 0, SW8_CS7,  SW7_CS7,  SW9_CS7 },
    { 0, SW8_CS6,  SW7_CS6,  SW9_CS6 },
    { 0, SW8_CS5,  SW7_CS5,  SW9_CS5 },
    { 0, SW8_CS4,  SW7_CS4,  SW9_CS4 },
    { 0, SW8_CS3,  SW7_CS3,  SW9_CS3 },
    { 0, SW8_CS2,  SW7_CS2,  SW9_CS2 },
    { 0, SW8_CS1,  SW7_CS1,  SW9_CS1 },
    { 0, SW11_CS9,  SW10_CS9,  SW12_CS9 },
    { 0, SW11_CS8,  SW10_CS8,  SW12_CS8 },

    { 0, SW11_CS12, SW10_CS12, SW12_CS12 },
    { 0, SW11_CS11, SW10_CS11, SW12_CS11 },
    { 0, SW11_CS10, SW10_CS10, SW12_CS10 },
    { 0, SW11_CS7,  SW10_CS7,  SW12_CS7 },
    { 0, SW11_CS4,  SW10_CS4,  SW12_CS4 },
    { 0, SW11_CS3,  SW10_CS3,  SW12_CS3 },
    { 0, SW11_CS2,  SW10_CS2,  SW12_CS2 },
    { 0, SW11_CS1,  SW10_CS1,  SW12_CS1 },
    { 0, SW11_CS6,  SW10_CS6,  SW12_CS6 },
    { 0, SW11_CS5,  SW10_CS5,  SW12_CS5 },
};

led_config_t g_led_config = {
     {
    {  0,  1,  2,  3,  4,  5,  6,  7,   8,  9,  10,  11, 12,    13,  14 },
    {  15, 16, 17, 18, 19, 20, 21, 22,  23, 24, 25,  26, 27,    28,  29 },
    {  30, 31, 32, 33, 34, 35, 36, 37,  38, 39, 40,  41, NO_LED,42,  43 },
    {  44, 45, 46, 47, 48, 49, 50, 51,  52, 53, 54,  NO_LED,55, 56,  57 },
    {  58, 59, 60, NO_LED, NO_LED,  61, NO_LED, NO_LED,  NO_LED, 62, 63,  64,  65,  66,  67 }
},
     {
    {0,0},{15,0},{30,0},{45,0},{60,0},{75,0},{90,0},{105,0},{120,0},{135,0},{150,0},{165,0},{180,0},{203,0},{224,0},
	{4,16},{23,16},{38,16},{53,16},{68,16},{83,16},{98,16},{113,16},{128,16},{143,16},{158,16},{173,16},{188,16},{206,16},{224,16},
	{6,32},{26,32},{41,32},{56,32},{71,32},{86,32},{101,32},{116,32},{131,32},{146,32},{161,32},{176,32},{201,32},{224,32},
	{9,48},{34,48},{49,48},{64,48},{79,48},{94,48},{109,48},{124,48},{139,48},{154,48},{169,48},{189,48},{210,48},{224,48},
        {   2,  64 }, {  21,  64 }, {  39,  64 },                                           {  96,  64 },                             { 150,  64 }, { 165,  64 }, { 180,  64 }, { 195,  64 }, { 210,  64 }, { 224,  64 }
},
     {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 4, 1, 1, 1, 1, 1, 1
} };

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, 0xFF, 0xFF, 0xFF);
    }
    return true;
}

#endif
