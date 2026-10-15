#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                 KC_MPRV,    KC_MPLY, KC_MNXT,
                 C(KC_LEFT), KC_CALC, C(KC_RIGHT),
        KC_MUTE, S(KC_P),    MO(1),   S(KC_N)
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
