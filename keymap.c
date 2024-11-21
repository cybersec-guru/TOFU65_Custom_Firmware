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


#include QMK_KEYBOARD_H
#include "quantum.h"


     /* TOFU_JR
      *      ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
      * Row 1│Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Hom│
      *      ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
      * Row 2│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │PgU│
      *      ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
      * Row 3│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │PgD│
      *      ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
      * Row 4│ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │End│
      *      ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
      * Row 5│Ctrl│GUI │Alt │                        │Alt│ Fn│Ctl│ ← │ ↓ │ → │
      *      └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
      */

// Refer to keyboard template for row and column
// Row 0, Key 1 = 0
// Row 1, Key 1 = 15
// Row 2, Key 1 = 30
// Row 3, Key 1 = 44
// Row 4, Key 1 = 58
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
        KC_LCTL,  KC_LGUI, KC_LALT,                            KC_SPC,           KC_RALT, MO(1), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SCRL, KC_PAUS, QK_BOOT, KC_PGUP,
        KC_CAPS, RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,         EE_CLR,  KC_PGDN,
        KC_LSFT, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______,          KC_VOLU, KC_MUTE,
        QK_BOOT, QK_RBT, _______,                            _______,          _______, _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT
    ),
};


const uint8_t key_index_map[MATRIX_ROWS][MATRIX_COLS] = {
/* TOFU_JR
*      ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
* Row 1│ 0 │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │10 │11 │12 │   13  │ 14│
*      ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
* Row 2│ 15  │16 │17 │18 │19 │20 │21 │22 │23 │24 │25 │26 │27 │ 28  │ 29│
*      ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
* Row 3│  30  │31 │32 │33 │34 │35 │36 │37 │38 │39 │40 │41 │   42   │ 43│
*      ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
* Row 4│   44   │45 │46 │47 │48 │49 │50 │51 │52 │53 │54 │  55  │56 │ 57│
*      ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
* Row 5│ 58 │ 59 │ 60 │          61            │ 62│ 63│ 64│ 65│ 66│ 67│
*      └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
*/
// Row 0
{  0,  1,  2,      3,      4,  5,      6,      7,      8,  9, 10,     11,      12,  13, 14},
// Row 1
{ 15, 16, 17,     18,     19, 20,     21,     22,     23, 24, 25,     26,      27,  28, 29},
// Row 2
{ 30, 31, 32,     33,     34, 35,     36,     37,     38, 39, 40,     41,  NO_LED,  42, 43},
// Row 3
{ 44, 45, 46,     47,     48, 49,     50,     51,     52, 53, 54, NO_LED,      55,  56, 57},
// Row 4
{ 58, 59, 60, NO_LED, NO_LED, 61, NO_LED, NO_LED, NO_LED, 62, 63,     64,      65,  66, 67}
};

bool rgb_matrix_indicators_user(void) {
    // Iterate over all keys in the matrix
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t key_index = key_index_map[row][col]; // Get the key's LED index from the map
             if (key_index != NO_LED) {
            // Set default per-key colors
            // P = Purple, B = Blue
            /* TOFU_JR
            *      ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
            * Row 1│ B │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │   B   │ B │
            *      ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
            * Row 2│  B  │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │  P  │ B │
            *      ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
            * Row 3│   B  │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │    B   │ B │
            *      ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
            * Row 4│   B    │ P │ P │ P │ P │ P │ P │ P │ P │ P │ P │   B  │ B │ B │
            *      ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
            * Row 5│  B │ B  │ B  │           P            │ B │ B │ B │ B │ B │ B │
            *      └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
            */
            if (key_index == 0 ||   // ESC
                key_index == 13 ||  // BACKSPACE
                key_index == 14 ||  // DELETE
                key_index == 15 ||  // TAB
                key_index == 29 ||  // PAGE UP
                key_index == 30 ||  // CAPS
                key_index == 42 ||  // ENTER
                key_index == 43 ||  // PAGE DOWN
                key_index == 44 ||  // LEFT SHIFT
                key_index == 55 ||  // RIGHT SHIFT
                key_index == 57 ||  // HOME
                key_index == 58 ||  // LEFT CTRL
                key_index == 59 ||  // LEFT WIN
                key_index == 60 ||  // LEFT ALT
                key_index == 62 ||  // RIGHT ALT
                key_index == 63 ||  // FUNCTION
                key_index == 64     // RUGHT CTRL
                ) {
                rgb_matrix_set_color(key_index, 0, 238, 255); // BLUE
            // WASD Keys
            } else if (key_index == 17 ||  // KC_W
                       key_index == 31 ||  // KC_A
                       key_index == 32 ||  // KC_S
                       key_index == 33     // KC_D
                       ) {
                rgb_matrix_set_color(key_index, 123, 0, 254); // Dark Purple

            // ARROW KEYS
            } else if (key_index == 56 ||  // KC_UP
                       key_index == 65 ||  // KC_LEFT
                       key_index == 66 ||  // KC_DOWN
                       key_index == 67     // KC_RIGHT
                       ) {
                rgb_matrix_set_color(key_index, 0, 238, 255); // Blue

                      // ROW 0
            } else if  (key_index == 1 ||  // KC_1
                      key_index == 2 ||  // KC_2
                      key_index == 3 ||  // KC_3
                      key_index == 4 ||  // KC_4
                      key_index == 5 ||  // KC_5
                      key_index == 6 ||  // KC_6
                      key_index == 7 ||  // KC_7
                      key_index == 8 ||  // KC_8
                      key_index == 9 ||  // KC_9
                      key_index == 10 || // KC_0
                      key_index == 11 || // KC_MINS
                      key_index == 12 || // KC_EQL
                      // ROW 1
                      key_index == 16 || // KC_Q
                      key_index == 18 || // KC_E
                      key_index == 19 || // KC_R
                      key_index == 20 || // KC_T
                      key_index == 21 || // KC_Y
                      key_index == 22 || // KC_U
                      key_index == 23 || // KC_I
                      key_index == 24 || // KC_O
                      key_index == 25 || // KC_P
                      key_index == 26 || // KC_LBRC
                      key_index == 27 || // KC_RBRC
                      key_index == 28 || // KC_BSLS
                      // ROW 2
                      key_index == 34 || // KC_F
                      key_index == 35 || // KC_G
                      key_index == 36 || // KC_H
                      key_index == 37 || // KC_J
                      key_index == 38 || // KC_K
                      key_index == 39 || // KC_L
                      key_index == 40 || // KC_SCLN
                      key_index == 41 || // KC_QUOT
                      // ROW 3
                      key_index == 45 || // KC_Z
                      key_index == 46 || // KC_X
                      key_index == 47 || // KC_C
                      key_index == 48 || // KC_V
                      key_index == 49 || // KC_B
                      key_index == 50 || // KC_N
                      key_index == 51 || // KC_M
                      key_index == 52 || // KC_COMM
                      key_index == 53 || // KC_DOT
                      key_index == 54 || // KC_SLSH
                      // ROW 4
                      key_index == 61    // SPACE
                      ) {
                rgb_matrix_set_color(key_index, 205, 29, 222); }  // Purple
            // Apply reactive color when the key is pressed
            if (matrix_is_on(row, col)) {
                    switch (key_index) {

                        // ESC
                        case 0:
                            rgb_matrix_set_color(0, 205, 29, 222);
                            break;
                        // 1
                        case 1:
                            rgb_matrix_set_color(1, 0, 238, 255);
                            break;
                        // 2
                        case 2:
                            rgb_matrix_set_color(2, 0, 238, 255);
                        // 3
                        case 3:
                            rgb_matrix_set_color(3, 0, 238, 255);
                            break;
                        // 4
                        case 4:
                            rgb_matrix_set_color(4, 0, 238, 255);
                            break;
                        // 5
                        case 5:
                            rgb_matrix_set_color(5, 0, 238, 255);
                            break;
                        // 6
                        case 6:
                            rgb_matrix_set_color(6, 0, 238, 255);
                            break;
                        // 7
                        case 7:
                            rgb_matrix_set_color(7, 0, 238, 255);
                            break;
                        // 8
                        case 8:
                            rgb_matrix_set_color(8, 0, 238, 255);
                            break;
                        // 9
                        case 9:
                            rgb_matrix_set_color(9, 0, 238, 255);
                            break;
                        // 0
                        case 10:
                            rgb_matrix_set_color(10, 0, 238, 255);
                            break;
                        // -
                        case 11:
                            rgb_matrix_set_color(11, 0, 238, 255);
                            break;
                        // =
                        case 12:
                            rgb_matrix_set_color(12, 0, 238, 255);
                            break;
                        // BACKSPACE
                        case 13:
                            rgb_matrix_set_color(13, 205, 29, 222);
                            break;
                        // DELETE
                        case 14:
                            rgb_matrix_set_color(14, 205, 29, 222);
                            break;
                        // TAB
                        case 15:
                            rgb_matrix_set_color(15, 205, 29, 222);
                            break;
                        // Q
                        case 16:
                            rgb_matrix_set_color(16, 0, 238, 255);
                            break;
                        // W
                        case 17:
                            rgb_matrix_set_color(17, 0, 238, 255);
                            break;
                        // E
                        case 18:
                            rgb_matrix_set_color(18, 0, 238, 255);
                            break;
                        // R
                        case 19:
                            rgb_matrix_set_color(19, 0, 238, 255);
                            break;
                        // T
                        case 20:
                            rgb_matrix_set_color(20, 0, 238, 255);
                            break;
                        // Y
                        case 21:
                            rgb_matrix_set_color(21, 0, 238, 255);
                            break;
                        // U
                        case 22:
                            rgb_matrix_set_color(22, 0, 238, 255);
                            break;
                        // I
                        case 23:
                            rgb_matrix_set_color(23, 0, 238, 255);
                            break;
                        // O
                        case 24:
                            rgb_matrix_set_color(24, 0, 238, 255);
                            break;
                        // P
                        case 25:
                            rgb_matrix_set_color(25, 0, 238, 255);
                            break;
                        // [
                        case 26:
                            rgb_matrix_set_color(26, 0, 238, 255);
                            break;
                        // ]
                        case 27:
                            rgb_matrix_set_color(27, 0, 238, 255);
                            break;
                        // |
                        case 28:
                            rgb_matrix_set_color(28, 0, 238, 255);
                            break;
                        // PAGE UP
                        case 29:
                            rgb_matrix_set_color(29, 205, 29, 222);
                            break;
                        // CAPS LOCK
                        case 30:
                            rgb_matrix_set_color(30, 205, 29, 222);
                            break;
                        // A
                        case 31:
                            rgb_matrix_set_color(31, 0, 238, 255);
                            break;
                        // S
                        case 32:
                            rgb_matrix_set_color(32, 0, 238, 255);
                            break;
                        // D
                        case 33:
                            rgb_matrix_set_color(33, 0, 238, 255);
                            break;
                        // F
                        case 34:
                            rgb_matrix_set_color(34, 0, 238, 255);
                            break;
                        // G
                        case 35:
                            rgb_matrix_set_color(35, 0, 238, 255);
                            break;
                        // H
                        case 36:
                            rgb_matrix_set_color(36, 0, 238, 255);
                            break;
                        // J
                        case 37:
                            rgb_matrix_set_color(37, 0, 238, 255);
                            break;
                        // K
                        case 38:
                            rgb_matrix_set_color(38, 0, 238, 255);
                            break;
                        // L
                        case 39:
                            rgb_matrix_set_color(39, 0, 238, 255);
                            break;
                        // ;
                        case 40:
                            rgb_matrix_set_color(40, 0, 238, 255);
                            break;
                        // '
                        case 41:
                            rgb_matrix_set_color(41, 0, 238, 255);
                            break;
                        // ENTER
                        case 42:
                            rgb_matrix_set_color(42, 205, 29, 222);
                            break;
                        // PAGE DOWN
                        case 43:
                            rgb_matrix_set_color(43, 205, 29, 222);
                            break;
                        // LEFT SHIFT
                        case 44:
                            rgb_matrix_set_color(44, 205, 29, 222);
                            break;
                        // Z
                        case 45:
                            rgb_matrix_set_color(45, 0, 238, 255);
                            break;
                        // X
                        case 46:
                            rgb_matrix_set_color(46, 0, 238, 255);
                            break;
                        // C
                        case 47:
                            rgb_matrix_set_color(47, 0, 238, 255);
                            break;
                        // V
                        case 48:
                            rgb_matrix_set_color(48, 0, 238, 255);
                            break;
                        // B
                        case 49:
                            rgb_matrix_set_color(49, 0, 238, 255);
                            break;
                        // N
                        case 50:
                            rgb_matrix_set_color(50, 0, 238, 255);
                            break;
                        // M
                        case 51:
                            rgb_matrix_set_color(51, 0, 238, 255);
                            break;
                        // ,
                        case 52:
                            rgb_matrix_set_color(52, 0, 238, 255);
                            break;
                        // .
                        case 53:
                            rgb_matrix_set_color(53, 0, 238, 255);
                            break;
                        // /
                        case 54:
                            rgb_matrix_set_color(54, 0, 238, 255);
                            break;
                        // RIGHT SHIFT
                        case 55:
                            rgb_matrix_set_color(55, 205, 29, 222);
                            break;
                        // UP ARROW KEY
                        case 56:
                            rgb_matrix_set_color(56, 205, 29, 222);
                            break;
                        // HOME
                        case 57:
                            rgb_matrix_set_color(57, 205, 29, 222);
                            break;
                        // LEFT CONTROL
                        case 58:
                            rgb_matrix_set_color(58, 205, 29, 222);
                            break;
                        // WIN KEY
                        case 59:
                            rgb_matrix_set_color(59, 205, 29, 222);
                            break;
                        // LEFT ALT
                        case 60:
                            rgb_matrix_set_color(60, 205, 29, 222);
                            break;
                        // SPACE
                        case 61:
                            rgb_matrix_set_color(61, 0, 238, 255);
                            break;
                        // RIGHT ALT
                        case 62:
                            rgb_matrix_set_color(62, 205, 29, 222);
                            break;
                        // FUNCTION KEY
                        case 63:
                            rgb_matrix_set_color(63, 205, 29, 222);
                            break;
                        // RIGHT CONTROL
                        case 64:
                            rgb_matrix_set_color(64, 205, 29, 222);
                            break;
                        // LEFT ARROW KEY
                        case 65:
                            rgb_matrix_set_color(65, 205, 29, 222);
                            break;
                        // DOWN ARROW KEY
                        case 66:
                            rgb_matrix_set_color(66, 205, 29, 222);
                            break;
                        // RIGHT ARROW KEY
                        case 67:
                            rgb_matrix_set_color(67, 205, 29, 222);
                            break;
                    }

                }

            }
        }
    }
    return true;
};




