/* Copyright 2021 Kyle McCreery
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

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        // 32x128px
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_raw_P(qmk_logo, false);
}

bool oled_task_user(void) {
    oled_set_cursor(0,0);
    render_logo();
    return false;
}
#endif


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
    [1] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)  },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_A, KC_B, KC_C, KC_D, KC_E,
      KC_F, KC_G, KC_H, KC_I, KC_J,
      KC_K, KC_L, KC_M, KC_N, KC_O, MO(1)),

  [1] = LAYOUT(
      KC_P, KC_Q, KC_R, KC_S, KC_T,
      KC_U, KC_V, KC_W, KC_X, RGB_SAI,
      KC_Z, KC_1, KC_2, KC_3, RGB_SAD, KC_TRNS)
};