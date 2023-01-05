/* Copyright 2021 yohewi
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
#include "keymap_jp.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _DEFAULT,
    _RAISE,
    _LOWER,
    _NUMBER,
    _CLIPSTUDIO
};

enum custom_keycodes {
  IMEON,
  IMEOFF,
};

// Base layer mod tap
#define KC_MHAL LALT_T(KC_MHEN)
#define KC_HNCT RCTL_T(KC_HENK)
#define KC_ZSFT LSFT_T(KC_Z)
#define KC_DOSF RSFT_T(KC_DOT)
#define KC_ESCT LCTL_T(KC_ESC)
#define KC_ENAL RALT_T(KC_ENT)
#define KC_ACT  LCTL_T(KC_A)

// Raise layer mod tap
#define KC_F9SF LSFT_T(KC_F9)

// Layer tap
#define KC_RA MO(_RAISE)
#define KC_SPLO LT(_LOWER, KC_SPC)
#define KC_NM MO(_NUMBER)

// WWW BACK/FORWARD short alias
#define KC_BCK KC_WWW_BACK
#define KC_FWD KC_WWW_FORWARD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_DEFAULT] = LAYOUT(
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
      KC_ACT,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    \
      KC_ZSFT, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOSF, \
      KC_ESCT, KC_LGUI, KC_MHAL, KC_SPLO,          KC_RA,   KC_HNCT, KC_BSPC, KC_ENAL ),
    [_RAISE] = LAYOUT(
      KC_DEL,  KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_MENU, KC_HOME, KC_UP,   KC_END,  KC_BSPC, \
      KC_F5,   KC_F6,   KC_F7,   KC_F8,   A(KC_ENT),A(KC_UP), KC_LEFT, KC_RGHT, KC_ENT, \
      KC_F9SF, KC_F10,  KC_F11,  KC_F12,  KC_FWD,  KC_BCK,  KC_DOWN, KC_PGUP, KC_PGDN, \
      _______, _______, _______, KC_ENT,           _______, _______, _______, _______ ),
    [_LOWER] = LAYOUT(
      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), KC_BSPC, \
      KC_LSFT, KC_NM  , JP_PLUS, JP_ASTR, JP_AT,   KC_RO,   JP_MINS, JP_SCLN, JP_COLN, \
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, JP_YEN,  JP_CIRC, KC_SLSH, JP_LBRC, JP_RBRC, \
      _______, _______, _______, KC_TAB,          KC_TAB,  _______, _______, _______ ),
    [_NUMBER] = LAYOUT(
      KC_1   , KC_2   , KC_3   , KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_BSPC, \
      KC_LCTL, XXXXXXX, JP_PLUS, JP_ASTR, JP_MINS, JP_UNDS, KC_4,    KC_5,    KC_6, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_1,    KC_2,    KC_3, \
      _______, _______, _______, _______,          KC_0,    KC_0,    KC_DOT,  _______ ),
    [_CLIPSTUDIO] = LAYOUT(
      KC_ESC,     KC_W,         KC_E,       KC_R,        KC_T,    LCTL(KC_Y), LCTL(KC_R), LCTL(KC_0), KC_O, KC_P, \
      KC_ACT,     LCTL(KC_S),   LCTL(KC_D), LCTL(KC_E),  KC_G,    KC_H,       LCTL(KC_J), KC_K,       KC_L, \
      LCTL(KC_Z), KC_X,         LCTL(KC_C), LCTL(KC_V),  KC_B,    LCTL(KC_T), KC_M,       KC_LBRC,    KC_RBRC, \
      _______,    LCTL(KC_LALT), KC_LALT,     KC_SPC,      KC_LSFT, KC_ENT,     KC_LCTL,    LCTL(KC_LSFT) ),
    [5] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),
    [6] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),
    [7] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),
    [8] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),
    [9] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),
    [10] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),
    [11] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ )
};
