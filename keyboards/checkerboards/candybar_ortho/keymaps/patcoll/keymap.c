/* Copyright 2021 Nathan Spears
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

#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
  _MOUSE
};

#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_ENT LCTL_T(KC_ENT)
#define LT3_Z LT(_NAV, KC_Z)
#define LT4_X LT(_MOUSE, KC_X)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define SFT_SLSH MT(MOD_LSFT, KC_SLSH)
#define LT1_ENT LT(_RAISE, KC_ENT)
#define LT1_BSPC LT(_RAISE, KC_BSPC)
#define LT2_SPC LT(_LOWER, KC_SPC)
#define LT3_TAB LT(_NAV, KC_TAB)
#define LT4_Q   LT(_MOUSE, KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_grid(
  LT3_TAB, LT4_Q,   KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_ESC, LT3_Z,   LT4_X,   KC_C,    KC_V,    KC_B,    _______, _______, _______, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   SFT_SLSH,
  KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, LT2_SPC, KC_SPC,  KC_SPC,  _______, _______, _______, CTL_ENT, CTL_ENT, LT1_ENT, KC_LALT, KC_LEFT, KC_DOWN, KC_RGHT
),

[_LOWER] = LAYOUT_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, _______, _______, KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, _______, _______, KC_F12,  _______, _______, _______, KC_PGUP, _______,
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL, KC_LCTL, _______, _______, KC_HOME, KC_PGDN, KC_END
),

[_RAISE] = LAYOUT_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, _______, _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, _______, _______, KC_F12,  KC_NUHS, KC_NUBS, _______, KC_BRIU, _______,
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL, KC_LCTL, _______, _______, _______, KC_BRID, _______
),

[_NAV] = LAYOUT_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL, KC_LCTL, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
),

[_MOUSE] = LAYOUT_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_MS_U, _______,
  _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R
),

};

