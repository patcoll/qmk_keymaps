/* Copyright 2022 LAZYDESIGNERS
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
/* #define LT1_SPC LT(1, KC_SPC) */
/*  */
/* // How long (in milliseconds) to wait between animation steps for each of the "Snake" animations */
/* const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {250, 200, 150}; */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [0] = LAYOUT( */
/*                KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   */
/*                KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT, */
/*                KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_UP,    MO(2), */
/*                KC_LCTL, KC_LALT, KC_LGUI,          LT1_SPC, KC_SPC,           KC_LEFT, KC_DOWN, KC_RGHT */
/*              ), */
/*     [1] = LAYOUT( */
/*                KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    */
/*                KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, */
/*                KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_COMM, KC_NO,   KC_NO, */
/*                KC_VOLD, KC_MUTE, KC_VOLU,          KC_TRNS, KC_TRNS,          RGB_TOG, RGB_MOD, KC_NO */
/*              ), */
/*     [2] = LAYOUT( */
/*                RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    */
/*                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     */
/*                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  */
/*                KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_NO,            KC_NO,   KC_NO,   KC_NO */
/*              ), */
/* }; */

#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________, _________QWERTY_R3_FOUR________, _______,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL, KC_HYPR, KC_MEH
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, __________________NAV_R2___________________,
  __________________NAV_L3___________________, _____________NAV_R3_FOUR__________, _______,
  _______, _______, _______, ALT_TAB, ALT_TAB, _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, __________________OSK_R1___________________,
  __________________OSK_L2___________________, __________________OSK_R2___________________,
  __________________OSK_L3___________________, _____________OSK_R3_FOUR__________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________, _________________LOWER_R2__________________,
  _________________LOWER_L3__________________, __________LOWER_R3_FOUR___________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  _________________RAISE_L3__________________, __________RAISE_R3_FOUR___________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________, __________MEDIA_R3_FOUR___________, _______,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________, __________MOUSE_R3_FOUR___________, _______,
  _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN2, _______, _______
),
};
