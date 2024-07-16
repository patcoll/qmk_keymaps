// Copyright 2023 LAZDESIGNERS
// SPDX-License-Identifier: GPL-2.0-or-later

/* #include QMK_KEYBOARD_H */
/* #include "../../rgb.c" */
/*  */
/* #define LT1_SPC LT(1, KC_SPC) */
/*  */
/* // For testing only */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [0] = LAYOUT( */
/*                RGB_TOG, KC_MUTE, */
/*                KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   */
/*                KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT, */
/*                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_UP,    MO(2), */
/*                KC_LCTL, KC_LALT, KC_LGUI,          LT1_SPC, KC_SPC,           KC_LEFT, KC_DOWN, KC_RGHT */
/*              ), */
/*     [1] = LAYOUT( */
/*                KC_NO,   KC_NO, */
/*                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    */
/*                KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, */
/*                KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_COMM, KC_NO,   KC_NO, */
/*                KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO */
/*              ), */
/*     [2] = LAYOUT( */
/*                KC_NO,   KC_NO, */
/*                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    */
/*                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     */
/*                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  */
/*                KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO */
/*              ), */
/* }; */
/*  */
/* #ifdef ENCODER_MAP_ENABLE */
/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = { */
/*     [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) }, */
/*     [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  }, */
/*     [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  } */
/* }; */
/* #endif */

/* #include "../../rgb.c" */

#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_MUTE, RGB_TOG,
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL, KC_HYPR, KC_MEH
),

[_GAMING] = LAYOUT_wrapper(
  _______, _______,
  _________________GAMING_L1_________________, _________________GAMING_R1_________________,
  _________________GAMING_L2_________________, _________________GAMING_R2_________________,
  _________________GAMING_L3_________________, _________________GAMING_R3_________________,
  _______, _______, _______, KC_SPC,   KC_ENT, _______, _______, _______
),

[_NAV] = LAYOUT_wrapper(
  _______, _______,
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, __________________NAV_R2___________________,
  __________________NAV_L3___________________, __________________NAV_R3___________________,
  _______, _______, _______, ALT_TAB, ALT_TAB, _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  _______, _______,
  __________________OSK_L1___________________, __________________OSK_R1___________________,
  __________________OSK_L2___________________, __________________OSK_R2___________________,
  __________________OSK_L3___________________, __________________OSK_R3___________________,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _______, _______,
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  _________________RAISE_L3__________________, _________________RAISE_R3__________________,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _______,
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________, _________________MEDIA_R3__________________,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _______,
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________, _________________MOUSE_R3__________________,
  _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN2, _______, _______
),
};

#ifdef RGB_MATRIX_ENABLE
// LED index
// 7, 6, 5, 4, 3, 2, 1, 0

led_config_t g_led_config = {
    // Key Matrix to LED Index
    {
         {   0  ,    0  ,    1  ,   2   ,   3   ,   4   ,    5   ,   6   ,   7   ,    7   ,   7     },
         {   0  ,    0  ,    1  ,   2   ,   3   ,   4   ,    5   ,   6   ,   7   ,    7   ,   7     },
         {   0  ,    0  ,    1  ,   2   ,   3   ,   4   ,    5   ,   6   ,   7   ,    7             },
         {   0  ,    0  ,    1  ,           3   ,   4   ,            6   ,   7   ,    7             }
    },
    // LED Index to Physical Positon
    {
        { 0  , 8  },
        { 32, 16 },
        { 64, 24 },
        { 96, 32 },
        { 128 , 40 },
        { 160 , 48 },
        { 192 , 56 },
        { 224 , 64 }
    },
    //  LED Index to Flag
    { 1, 1, 1, 1, 1, 1, 1, 1 }
};

#define RGB_MATRIX_TYPING_HEATMAP_SPREAD 80
#define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 32


#endif
