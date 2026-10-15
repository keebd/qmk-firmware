VIA_ENABLE = yes
VIAL_ENABLE = yes
OLED_ENABLE = yes
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
WPM_ENABLE = yes
TAP_DANCE_ENABLE = yes
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

QMK_SETTINGS = yes
LTO_ENABLE = yes
# Classic Pro Micro (native ATmega32U4 build, 28 KB flash): trim Vial extras
# so it fits. RP2040/STM32 converter builds keep everything.
ifeq ($(strip $(CONVERT_TO)),)
    QMK_SETTINGS = no
    TAP_DANCE_ENABLE = no
    COMBO_ENABLE = no
    KEY_OVERRIDE_ENABLE = no
endif
