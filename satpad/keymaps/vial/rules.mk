GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no

CAPS_WORD_ENABLE = yes
OLED_ENABLE = yes
ENCODER_MAP_ENABLE 	= yes

VIA_ENABLE = yes

# OLED WIDGETS

# WPM_ENABLE = no
# KEYCOUNT_ENABLE = yes
# KEYLOG_ENABLE = no
# KEYLOG_DEBUG = no
VIAL_ENABLE = yes
VIAL_INSECURE = yes

# Classic Pro Micro (native ATmega32U4 build, 28 KB flash): trim Vial extras
# so it fits. RP2040/STM32 converter builds keep everything.
ifeq ($(strip $(CONVERT_TO)),)
    QMK_SETTINGS = no
endif
