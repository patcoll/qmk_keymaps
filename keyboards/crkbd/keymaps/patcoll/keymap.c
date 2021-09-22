/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_LSFT,
  KC_LALT, LWR_SPC, SFT_SPC,                   RSE_ENT, RSE_ENT, KC_LCTL
),

[_NAV] = LAYOUT_wrapper(
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC,
  MO_NAV,  __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  _______, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
  _______, _______, _______,                   _______,  _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
  _______, _______, _______,                   _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
  _______, _______, _______,                   _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
  _______, _______, _______,                   _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
  _______, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, _______
),
};
