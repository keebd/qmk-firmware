VIA_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no
VIAL_ENABLE = yes
VIAL_INSECURE = yes
ENCODER_MAP_ENABLE = yes

# Classic Pro Micro (native ATmega32U4 build, 28 KB flash): trim Vial extras
# so it fits. RP2040/STM32 converter builds keep everything.
ifeq ($(strip $(CONVERT_TO)),)
    QMK_SETTINGS = no
    TAP_DANCE_ENABLE = no
    COMBO_ENABLE = no
    KEY_OVERRIDE_ENABLE = no
    CAPS_WORD_ENABLE = no
    LAYER_LOCK_ENABLE = no
    REPEAT_KEY_ENABLE = no
endif
