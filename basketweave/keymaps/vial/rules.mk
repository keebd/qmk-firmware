VIA_ENABLE = yes
LTO_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes
ENCODER_MAP_ENABLE = yes
# ATmega32A has 1 KB of EEPROM: skip Vial's EEPROM-backed extras so the
# 4 dynamic layers still fit.
QMK_SETTINGS = no
TAP_DANCE_ENABLE = no
COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no
