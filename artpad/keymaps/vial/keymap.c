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

#include QMK_KEYBOARD_H
#define ANIM_SIZE 512

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
      KC_A, KC_B, KC_C, KC_D, KC_E,
      KC_F, KC_G, KC_H, KC_I, KC_J,
      KC_K, KC_L, KC_M, KC_N, KC_O, MO(1)),

  [1] = LAYOUT_all(
      KC_P, KC_Q, KC_R, KC_S, KC_T,
      KC_U, KC_V, KC_W, KC_X, RGB_SAI,
      KC_Z, KC_1, KC_2, KC_3, RGB_SAD, KC_TRNS)
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_logo(void) {
    static const char PROGMEM oled_logo[ANIM_SIZE] = {
        // 'logo_64x128', 32x128px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x7a, 0x7e, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 
        0xe0, 0xa0, 0xe0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x3f, 0xb3, 0x7f, 0xff, 
        0xff, 0x7f, 0x1f, 0x1f, 0x32, 0x3e, 0x7f, 0x7f, 0xfe, 0xfe, 0xf8, 0xfc, 0xfc, 0xf8, 0xf8, 0x00, 
        0x00, 0x80, 0x80, 0xc0, 0xc0, 0xf0, 0xf0, 0xf0, 0xe8, 0xe8, 0xf0, 0xf8, 0xf8, 0xf1, 0xf0, 0xff, 
        0xff, 0xfc, 0xfe, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x07, 
        0x01, 0x07, 0x07, 0x07, 0x03, 0x07, 0x05, 0x05, 0x07, 0x03, 0x03, 0x07, 0x07, 0x03, 0x07, 0x03, 
        0x03, 0x3f, 0x07, 0x0f, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7e, 0x7e, 0xfe, 0xfc, 
        0xfc, 0xfc, 0xfc, 0xf4, 0xf8, 0xf0, 0xe0, 0xf0, 0xf0, 0xfc, 0xfc, 0xfe, 0xf8, 0xe0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe, 0x3f, 0x7f, 
        0xff, 0xff, 0xff, 0xfd, 0xf1, 0xc1, 0x01, 0x03, 0x03, 0x03, 0x07, 0xff, 0xff, 0xff, 0x1b, 0x00, 
        0x80, 0xe0, 0xf0, 0xfc, 0xfe, 0xff, 0x3f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 
        0x03, 0x0f, 0x1f, 0x17, 0x2f, 0x5f, 0x1f, 0x36, 0x34, 0x3c, 0xbd, 0xdf, 0xcf, 0xc3, 0x00, 0x00, 
        0x00, 0x07, 0x83, 0xc3, 0xc1, 0x40, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 
        0x00, 0x00, 0x13, 0x1b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 
        0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7e, 0xfe, 0xfe, 0xfe, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xf0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x7f, 0xff, 0xff, 0xff, 0x00, 
        0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 
        0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x43, 0xc3, 0x07, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x7f, 0x00, 0x00, 
        0x00, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10, 0xf0, 0x20, 0x20, 
        0x20, 0x20, 0x21, 0x41, 0x41, 0x41, 0x41, 0x81, 0x81, 0x81, 0x81, 0x81, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x1f, 0x10, 0x10, 
        0x18, 0x08, 0x08, 0x08, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x03, 0x03, 0x00, 0x00, 
        0x00, 0xf0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 
        0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xf0, 0x00, 0x00, 
        0x00, 0x0f, 0x30, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x20, 0x1f, 0x00, 0x00
    };

    oled_write_raw_P(oled_logo, ANIM_SIZE);
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