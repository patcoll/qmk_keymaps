#ifndef CONFIG_H
#define CONFIG_H
#include "config_common.h"

#define VENDOR_ID     0xFEAE
#define PRODUCT_ID    0x8847
#define DEVICE_VER    0x0001
#define MANUFACTURER  TheVan Keyboards
#define PRODUCT       CaraVan 2
#define DESCRIPTION   CaraVan Split 40%

#define MATRIX_ROWS 3
#define MATRIX_COLS 16
#define MATRIX_ROW_PINS { D0, D1, D2 }
#define MATRIX_COL_PINS { 1, 2, 3, 4, 5, 6, 0, 7, 13, 12, 11, 10, 9, 14, 15, 8 }




#define DIODE_DIRECTION ROW2COL

#define BACKLIGHT_LEVELS 1
// #define BACKLIGHT_PIN undefined

#define DEBOUNCE 5
// #define TAPPING_TERM 175

#define USB_MAX_POWER_CONSUMPTION 100
// #define PERMISSIVE_HOLD
#define MULTIPLEX_PINS { D4, D6, D7, B4 }
#define MULTIPLEX 4
#define RGB_DI_PIN F0
#define RGBLIGHT_LIMIT_VAL 255
#define RGBLED_NUM 20
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) )
#endif
