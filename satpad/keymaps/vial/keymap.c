#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  LAYER_LENGTH
};

// Default combos, seeded into Vial's editable combo slots (Vial keeps them in
// EEPROM, so a static key_combos[] table would clash). They are reapplied
// whenever Vial resets its data: on a full EEPROM reset and on the first boot
// of each new firmware build.
static const vial_combo_entry_t default_combos[] = {
    { { KC_N, KC_M,    KC_NO, KC_NO }, KC_SPC  },
    { { KC_O, KC_P,    KC_NO, KC_NO }, KC_BSPC },
    { { KC_L, KC_QUOT, KC_NO, KC_NO }, KC_ENT  },
    { { KC_A, KC_S,    KC_NO, KC_NO }, KC_TAB  },
    { { KC_Q, KC_W,    KC_NO, KC_NO }, KC_ESC  },
};

static void seed_default_combos(void) {
    for (uint8_t i = 0; i < ARRAY_SIZE(default_combos); i++) {
        dynamic_keymap_set_combo(i, &default_combos[i]);
    }
}

static bool vial_data_reset_pending = false;

// Runs before via_init() checks its EEPROM magic, which changes every build.
void via_init_kb(void) {
    vial_data_reset_pending = !via_eeprom_is_valid();
}

void keyboard_post_init_user(void) {
    if (vial_data_reset_pending) {
        seed_default_combos();
    }
}

void eeconfig_init_user(void) {
    seed_default_combos();
}
#define BSFT  LSFT_T(KC_B)
#define VCTL  LCTL_T(KC_V)
#define CGUI  LGUI_T(KC_C)
#define XALT  LALT_T(KC_X)

#define ______ KC_NO
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,    \
        KC_A,   KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,       KC_L,   KC_QUOT,    \
        KC_Z,   XALT,   CGUI,   VCTL,   BSFT,   KC_SPC,     KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_DOWN, KC_UP) },
};