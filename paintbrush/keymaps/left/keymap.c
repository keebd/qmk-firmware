// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#include QMK_KEYBOARD_H

enum layers {
  _ART_BASE,
  _ART_NUM,
  _ART_CUS,
  _ART_PUNC,
  _ART_MOU,
  _ART_NAV,
  _ART_SYM,
};

#include "aliases.c"
#include "combos.c"
#include "oled_matrix.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ART_BASE] = LAYOUT(
    LT(_ART_SYM,KC_A),KC_R,KC_T,LT(_ART_NUM,KC_S),
    LT(_ART_PUNC,KC_E),KC_Y,KC_I,LT(_ART_CUS,KC_O)
),

[_ART_NUM] = LAYOUT(
    KC_1,KC_2,KC_3,KC_TRNS,
    KC_4,KC_5,KC_6,KC_TRNS
),


[_ART_PUNC] = LAYOUT(
    KC_EXLM,KC_BSLS,KC_SCLN,KC_GRV,
    KC_TRNS,KC_QUES,KC_MINS,KC_EQL
),

[_ART_CUS] = LAYOUT(
    KC_MPLY,KC_MUTE,KC_KB_VOLUME_UP,KC_TRNS,
    KC_MPRV,KC_MNXT,KC_KB_VOLUME_DOWN,KC_TRNS
),

[_ART_SYM] = LAYOUT(
    KC_TRNS,KC_LPRN,KC_RPRN,KC_LCBR,
    KC_TRNS,KC_LBRC,KC_RBRC,KC_RCBR
),

[_ART_MOU] = LAYOUT(
    MS_BTN1,MS_UP,MS_BTN2,MS_WHLU,
    MS_LEFT,MS_DOWN,MS_RGHT,MS_WHLD
),

[_ART_NAV] = LAYOUT(
    KC_HOME,KC_UP,KC_END,KC_PGUP,
    KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN
),
};
