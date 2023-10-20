/* Copyright 2021 qpockets
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

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID    0x7170
#define PRODUCT_ID   0x7171
#define DEVICE_VER   0x0001
#define MANUFACTURER qpockets
#define PRODUCT      orbital

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 11

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { C7, F0, B7, D2 }
#define MATRIX_COL_PINS { B6, B5, B4, D7, D4, C6, F1, F4, F5, F6, F7 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* ROTARY ENCODERS */
#define ENCODERS_PAD_A { D5, D1 }
#define ENCODERS_PAD_B { D3, D0 }

#define ENCODER_RESOLUTION 6

#define RGB_DI_PIN  D6
#define RGBLED_NUM 2
#define RGBLIGHT_LIMIT_VAL 80
#define RGBLIGHT_LAYERS
#define RGBLIGHT_DISABLE_KEYCODES

#ifdef COMBO_ENABLE
    #define COMBO_COUNT 7
    #define COMBO_TERM 25
#endif

#ifdef MOUSEKEY_ENABLE
    #define MK_COMBINED
    #define MK_3_SPEED
    #define MK_C_OFFSET_UNMOD 16
    #define MK_C_INTERVAL_UNMOD 16
    #define MK_C_OFFSET_0 4
    #define MK_C_INTERVAL_0 32
    #define MK_C_OFFSET_1 8
    #define MK_C_INTERVAL_1 16
    #define MK_C_OFFSET_2 22
    #define MK_C_INTERVAL_2 16
    #define MOUSEKEY_DELAY 250
    #define MOUSEKEY_INTERVAL 16
    #define MOUSEKEY_MAX_SPEED 10
    #define MOUSEKEY_TIME_TO_MAX 0
    #define MOUSEKEY_WHEEL_TIME_TO_MAX 10
    #define MOUSEKEY_WHEEL_INTERVAL 25
    #define MOUSEKEY_WHEEL_MAX_SPEED 128
    #define MOUSEKEY_WHEEL_DELAY 200
#endif

#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 200

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 4

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* optical sensor settings */
#define PMW33XX_CS_PIN B0
#define POINTING_DEVICE_ROTATION_270

