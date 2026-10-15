/*
Copyright 2021 @mangoiv

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 30000
#endif

#define EE_HANDS

#define VIAL_KEYBOARD_UID {0xBA, 0x2C, 0xAB, 0x9D, 0xDD, 0x88, 0x7C, 0x3D}
#define VIAL_UNLOCK_COMBO_ROWS {0, 4}
#define VIAL_UNLOCK_COMBO_COLS {2, 2}
