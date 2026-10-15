/* Copyright 2020 marksard
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

enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST
};

// Base layer mod tap
#define KC_Z_SF  LSFT_T(KC_Z)
#define KC_SLSF  RSFT_T(KC_SLSH)

// Lower layer mod tap
#define KC_11SF  LSFT_T(KC_F11)
#define KC_GRSF  RSFT_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x10(
  //,---------------------------------------------------------------------------------------------------.
          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
          KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,   KC_ENT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_Z_SF,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSF,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       KC_LCTL,  KC_LALT,  KC_LGUI,    LOWER,  KC_BSPC,   KC_SPC,    RAISE,  KC_RGUI,   KC_APP,  KC_RCTL
  //,---------------------------------------------------------------------------------------------------.
  ),

  [_LOWER] = LAYOUT_ortho_4x10(
  //,---------------------------------------------------------------------------------------------------.
         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  KC_MINS,   KC_EQL,  KC_LBRC,  KC_RBRC,  KC_BSLS,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
         KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SCLN,  KC_QUOT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_11SF,   KC_F12,   KC_ESC,   KC_TAB,    KANJI,   KC_DEL,  XXXXXXX,  XXXXXXX,  KC_INT1,  KC_GRSF,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       _______,  _______,  _______,  _______,   KC_DEL,  _______,  _______,  _______,  _______,  _______
  //,---------------------------------------------------------------------------------------------------.
  ),

  [_RAISE] = LAYOUT_ortho_4x10(
  //,---------------------------------------------------------------------------------------------------.
          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_RSFT,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MINS,  KC_INT1,  KC_COMM,   KC_DOT,  KC_SLSF,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  //,---------------------------------------------------------------------------------------------------.
  ),

  [_ADJUST] = LAYOUT_ortho_4x10(
  //,---------------------------------------------------------------------------------------------------.
       QK_BOOT,   RGBRST,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_INS,  KC_PSCR,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       UG_TOGG,  UG_HUEU,  UG_SATU,  UG_VALU,  XXXXXXX,  MS_LEFT,  MS_DOWN,  MS_UP,  MS_RGHT,  KC_NUM,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       UG_NEXT,  UG_HUED,  UG_SATD,  UG_VALD,  XXXXXXX,  MS_BTN1,  MS_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  //,---------------------------------------------------------------------------------------------------.
  )
};

#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef OLED_ENABLE

void render_logo(void) {

  static const char PROGMEM logo_buf[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};

  oled_write_P(logo_buf, false);
}

void render_lock_status(void) {

  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();

  oled_write_P(PSTR("Lock:"), false);
  if (led_state.num_lock) {
    oled_write_P(PSTR("Num "), false);
  }
  if (led_state.caps_lock) {
    oled_write_P(PSTR("Caps "), false);
  }
  if (led_state.scroll_lock) {
    oled_write_P(PSTR("Scrl"), false);
  }

  oled_write_P(PSTR("\n"), false);
}

static char keylog_buf[24] = "Key state ready.\n";
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', '-', ' ', '@', ' ', ' ',
    ' ', ';', ':', ' ', ',', '.', '/', ' ', ' ', ' '};

void update_key_status(uint16_t keycode, keyrecord_t *record) {

  if (!record->event.pressed) return;

  char name = (keycode < 60) ? code_to_name[keycode] : ' ';
  snprintf(keylog_buf, sizeof(keylog_buf) - 1, "Key:%dx%d %2x %c\n",
          record->event.key.row, record->event.key.col,
          (uint16_t)keycode, name);
}

void render_key_status(void) {

  oled_write(keylog_buf, false);
}

#ifdef RGBLIGHT_ENABLE
extern rgblight_config_t rgblight_config;

static char led_buf[24] = "LED state ready.\n";
rgblight_config_t rgblight_config_bak;
void update_led_status(void) {

  if (rgblight_config_bak.enable != rgblight_config.enable ||
      rgblight_config_bak.mode != rgblight_config.mode ||
      rgblight_config_bak.hue != rgblight_config.hue ||
      rgblight_config_bak.sat != rgblight_config.sat ||
      rgblight_config_bak.val != rgblight_config.val
  ) {
    snprintf(led_buf, sizeof(led_buf) - 1, "LED%c:%2d hsv:%2d %2d %2d\n",
      rgblight_config.enable ? '*' : '.', (uint8_t)rgblight_config.mode,
      (uint8_t)(rgblight_config.hue / RGBLIGHT_HUE_STEP),
      (uint8_t)(rgblight_config.sat / RGBLIGHT_SAT_STEP),
      (uint8_t)(rgblight_config.val / RGBLIGHT_VAL_STEP));
      rgblight_config_bak = rgblight_config;
  }
  oled_write(led_buf, false);
}
#endif

typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 5
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Base"},
  {L_BASE + 1, "Base"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST_TRI, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {
  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_leyer_status());

  oled_write(layer_status_buf, false);
}

static inline void render_status(void) {

  update_led_status();
  update_keymap_status();
  render_lock_status();
  render_key_status();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
    return false;
}

#endif