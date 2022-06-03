/* Copyright 2020 jrfhoutx
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
/* #include QMK_KEYBOARD_H */
/*  */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*  #<{(| Keymap BASE: (Base Layer) Default Layer */
/*    * .----.,---------------------------------------------------------------------. */
/*    * | F1 || Esc |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P| [ | ] |    \   |  Del | */
/*    * |----||---------------------------------------------------------------------| */
/*    * | F2 || Tab   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return  |  PgUp| */
/*    * |----||---------------------------------------------------------------------| */
/*    * | F3 ||Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift | Up  |  PgDn| */
/*    * |----||---------------------------------------------------------------------| */
/*    * | F4 ||LCtrl|LGUI | Alt  |  Space  |  Space  | Alt |   |  L    |  Dn |   R  | */
/*    * `----'`---------------------------------------------------------------------' */
/*    |)}># */
/* [0] = LAYOUT_all( #<{(| Smolka Base |)}># */
/* 	KC_F1,   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,         KC_BSPC, KC_DEL, */
/*     KC_F2,   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,                  KC_ENT,  KC_HOME, */
/*     KC_F3,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,                  KC_UP,   KC_END, */
/*     KC_F4,   KC_LCTL, MO(1),   KC_LALT,          KC_SPC,           KC_TRNS, KC_SPC,           KC_TRNS, KC_RALT,         KC_LEFT, KC_DOWN, KC_RGHT */
/*   ), */
/*  */
/* [1] = LAYOUT_all( #<{(| Smolka Base |)}># */
/* 	RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS */
/*   ), */
/* }; */




#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_all(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _______, SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, KC_BSPC, KC_PGUP,
  _______, CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,         KC_PGDN,
  _______, KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_UP,   _______,
  _______, KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, SFT_SPC,                   RSE_ENT, KC_LCTL, KC_HYPR, __QWERTY_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  _______, KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC, _______, _______,
  _______, KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,          _______,
  _______, KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______, _______,
  _______, _______, _______, _______, ALT_TAB, ALT_TAB,                   ALT_TAB, _______, _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______, _______, _______,
  _______, _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,          _______,
  _______, _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______,  _______, __OSK_R4_ARROW_KEYS___
),

[_LOWER] = LAYOUT_wrapper(
  _______, KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______,
  _______, _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,          _______,
  _______, _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, __LOWER_R4_ARROW_KEYS__
),

[_RAISE] = LAYOUT_wrapper(
  _______, KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______,
  _______, _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,          _______,
  _______, _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______, _______,
  _______, _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,          _______,
  _______, _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR, _______, _______,
  _______, _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,          _______,
  _______, _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______, _______,
  _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, _______, __MOUSE_R3_ARROW_KEYS__
),
};
