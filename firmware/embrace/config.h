#pragma once

// #ifndef CONFIG_H
// #define CONFIG_H

// #define VENDOR_ID     0xFEAE
// #define PRODUCT_ID    0x8847
// #define DEVICE_VER    0x0001
// #define MANUFACTURER  TheVan Keyboards
// #define PRODUCT       Embrace
// #define DESCRIPTION   Embrace

// #define MATRIX_ROWS 5
// #define MATRIX_COLS 12
// #define MATRIX_ROW_PINS { B0, D4, D6, B7, B3 }
// #define MATRIX_COL_PINS { F1, F4, F5, B6, B5, B4, D7, D0, D5, D3, D2, D1 }

// #define ENCODERS_PAD_A { B2 }
// #define ENCODERS_PAD_B { B1 }

// #define DIODE_DIRECTION ROW2COL

// #define BACKLIGHT_LEVELS 1
// #define BACKLIGHT_PIN F6

// #define DEBOUNCE 5
// #define TAPPING_TERM 175

// #define USB_MAX_POWER_CONSUMPTION 100
// #define PERMISSIVE_HOLD
// #define RGB_DI_PIN F0
// #define RGBLED_NUM 52
// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_SLEEP
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )

// #endif
