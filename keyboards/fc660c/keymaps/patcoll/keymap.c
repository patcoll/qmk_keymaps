/*
Copyright 2017 Balz Guenat

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
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_GRV,  ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,KC_ENT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_RSFT,          KC_UP,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC,                                     KC_RALT, KC_RGUI, KC_HYPR,          KC_LEFT, KC_DOWN, KC_RGHT
),

[_NAV] = LAYOUT_wrapper(
  _______, _________________FUNC_LEFT_________________, _________________FUNC_RIGHT________________, _______, _______, _______, _______,
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, _______, _______, _______, _______,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, _______, _______,
  _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,          _______,
  _______, _______, _______, _______,                                     _______, _______, _______,          _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _______, _______________SYMBOLS_LEFT________________, _______________SYMBOLS_RIGHT_______________, _______, _______, _______, _______,
  KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, _______, _______,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,          _______,
  _______, _______, _______, _______,                                     _______, _______, _______,          _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _______, ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________, _______, _______, _______, _______,
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______, _______,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,          _______,
  _______, _______, _______, _______,                                     _______, _______, _______,          _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______, _______,
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______, _______, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,          _______,
  _______, _______, _______, _______,                                     _______, _______, _______,          _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______, _______,
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______, _______, _______, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,          _______,
  _______, _______, KC_BTN1, KC_BTN1,                                     KC_BTN2, _______, _______,          _______, _______, _______
),
};

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*   [_QWERTY] = LAYOUT( */
/*         KC_GRV, ________________NUMBER_LEFT________________,   ________________NUMBER_RIGHT_______________,   KC_MINS,KC_EQL, KC_BSPC,     KC_PGUP, */
/*         SFT_TAB,CTL_Q,  NAV_W,  KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_PGDN, */
/*         CTL_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     KC_ENT, */
/*         KC_LSFT,NAV_Z,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP, */
/*         KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                       KC_RALT,KC_RCTL,KC_HYPR,     KC_LEFT,KC_DOWN,KC_RGHT */
/*     ), */
/*   [_NAV] = LAYOUT( */
/*         _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     KC_PSCR, */
/*         KC_LSFT,CTL_1,  KC_2,   CS_3,   MOUSE_4,  KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,_______,_______,     _______, */
/*         KC_LCTL,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,TO(_MOUSE),  _______,     _______, */
/*         KC_LSFT,KC_LCTL,KC_LGUI,KC_LALT,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END, _______,_______,      KC_PGUP, */
/*         RESET,  _______,_______,                _______,                _______,_______,_______,       KC_HOME,KC_PGDN,KC_END */
/*     ), */
/*   [_MOUSE] = LAYOUT( */
/*         _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______, */
/*         _______,KC_LCTL,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______, */
/*         _______,_______,_______,_______,_______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,     _______, */
/*         _______,_______,_______,_______,TO(_QWERTY),  _______,KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,_______,_______,     KC_VOLU, */
/*         _______,_______,KC_BTN1,                KC_BTN1,                KC_BTN2,_______,_______,     _______,KC_VOLD,KC_MPLY */
/*     ), */
/* }; */

