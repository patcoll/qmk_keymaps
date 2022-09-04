/*
Copyright 2021 Bryan Ong

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

/* #include QMK_KEYBOARD_H */
/*  */
/* // Defines names for use in layer keycodes and the keymap */
/* enum layer_names { */
/*     _BASE, */
/*     _FN */
/* }; */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [_BASE] = LAYOUT_ava_split_bs( */
/*         KC_ESC,    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,   KC_EQL,     KC_BSPC,    KC_BSPC, */
/*         KC_PGUP,   KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,      KC_LBRC,    KC_RBRC,    KC_BSLS, */
/*         KC_PGDN,   KC_CAPS,            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN,   KC_QUOT,                KC_ENT, */
/*         KC_END,    KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM,    KC_DOT,    KC_SLSH,    KC_UP,      KC_DEL, */
/*                    KC_LCTL,   KC_LGUI,                            KC_LALT, KC_SPC,          KC_SPC,  LT(_FN, KC_SPC),                           KC_LEFT,    KC_DOWN,    KC_RGHT), */
/*     [_FN] = LAYOUT_ava_split_bs( */
/*         KC_TRNS,   KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,       KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,                KC_TRNS,    KC_TRNS, */
/*         KC_TRNS,   KC_TRNS,   KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,   RGB_RMOD,   RGB_MOD,    RGB_TOG, */
/*         KC_TRNS,   KC_TRNS,   KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    RGB_VAD,   RGB_VAI,                KC_TRNS, */
/*         QK_BOOT,     KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    RGB_SAD,   RGB_SAI,    KC_TRNS,    RGB_HUI, */
/*                    KC_TRNS,   KC_TRNS,                   KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS,                                 KC_TRNS,    KC_TRNS,    KC_TRNS), */
/* }; */


#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_ava(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  _______, SFT_TAB, _________________QWERTY_L1_________________,          _________________QWERTY_R1_________________, KC_BSPC, KC_BSPC, _______,
  _______, CTL_ESC, _________________QWERTY_L2_________________,          _________________QWERTY_R2_________________, SFT_QUOT,         _______,
  _______, KC_LSFT, _________________QWERTY_L3_________________, _______, _________________QWERTY_R3_________________, KC_UP,   _______,
           KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC,                            RSE_ENT, KC_LCTL, __QWERTY_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LSFT, __________________NAV_L1___________________,          __________________NAV_R1___________________, CS_BSPC, _______, _______,
  _______, KC_LCTL, __________________NAV_L2___________________,          __________________NAV_R2___________________, KC_BSLS,          _______,
  _______, KC_LSFT, __________________NAV_L3___________________, _______, __________________NAV_R3___________________, _______, _______,
           _______, _______, _______, ALT_TAB,                            ALT_TAB, _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, __________________OSK_L1___________________,          __________________OSK_R1___________________, _______, _______, _______,
  _______, _______, __________________OSK_L2___________________,          __________________OSK_R2___________________, _______,          _______,
  _______, _______, __________________OSK_L3___________________, _______, __________________OSK_R3___________________, _______, _______,
           _______, _______, _______, _______,                            _______, _______, __OSK_R4_ARROW_KEYS___
),

[_LOWER] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_TILDE,_________________LOWER_L1__________________,          _________________LOWER_R1__________________, _______, _______, _______,
  _______, _______, _________________LOWER_L2__________________,          _________________LOWER_R2__________________, KC_PIPE,          _______,
  _______, _______, _________________LOWER_L3__________________, _______, _________________LOWER_R3__________________, _______, _______,
           _______, _______, _______, _______,                            _______, _______, __LOWER_R4_ARROW_KEYS__
),

[_RAISE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_GRV,  _________________RAISE_L1__________________,          _________________RAISE_R1__________________, _______, _______, _______,
  _______, _______, _________________RAISE_L2__________________,          _________________RAISE_R2__________________, KC_BSLS,          _______,
  _______, _______, _________________RAISE_L3__________________, _______, _________________RAISE_R3__________________, _______, _______,
           _______, _______, _______, _______,                            _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _________________MEDIA_L1__________________,          _________________MEDIA_R1__________________, _______, _______, _______,
  _______, _______, _________________MEDIA_L2__________________,          _________________MEDIA_R2__________________, _______,          _______,
  _______, _______, _________________MEDIA_L3__________________, _______, _________________MEDIA_R3__________________, _______, _______,
           _______, _______, _______, _______,                            _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _________________MOUSE_L1__________________,          _________________MOUSE_R1__________________, KC_PSCR, _______, _______,
  _______, _______, _________________MOUSE_L2__________________,          _________________MOUSE_R2__________________, _______,          _______,
  _______, _______, _________________MOUSE_L3__________________, _______, _________________MOUSE_R3__________________, _______, _______,
           _______, _______, KC_BTN1, KC_BTN1,                            KC_BTN1, KC_BTN2, __MOUSE_R3_ARROW_KEYS__
),
};
