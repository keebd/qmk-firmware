// Copyright (c) 2021 Mike "KemoNine" Crosson
// SPDX-License-Identifier: Apache-2.0
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x7E71
#define PRODUCT_ID      0x7E72
#define DEVICE_VER      0x0001
#define MANUFACTURER    ardux
#define PRODUCT         paintbrush
#define DESCRIPTION     paintbrush

/* Board layout */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4
#define UNUSED_PINS

/* Prevent jitters in key presses */
#define DEBOUNCE 5