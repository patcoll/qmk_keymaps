/* #<{(| SPDX-License-Identifier: GPL-2.0-or-later |)}># */
/*  */
/* #include QMK_KEYBOARD_H */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [0] = LAYOUT( */
/*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
/*     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT */
/*     ), */
/*  */
/*     [1] = LAYOUT( */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/*     ), */
/*  */
/*     [2] = LAYOUT( */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/*     ), */
/*  */
/*     [3] = LAYOUT( */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/*     ) */
/*  */
/* }; */


#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
  SFT_SPC, SFT_SPC, SFT_SPC, RSE_ENT, KC_LCTL
),

[_GAMING] = LAYOUT_wrapper(
  _________________GAMING_L1_________________, _________________GAMING_R1_________________,
  _________________GAMING_L2_________________, _________________GAMING_R2_________________,
  _________________GAMING_L3_________________, _________________GAMING_R3_________________,
  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, __________________NAV_R2___________________,
  __________________NAV_L3___________________, __________________NAV_R3___________________,
  ALT_TAB, ALT_TAB, ALT_TAB, ALT_TAB, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, __________________OSK_R1___________________,
  __________________OSK_L2___________________, __________________OSK_R2___________________,
  __________________OSK_L3___________________, __________________OSK_R3___________________,
  _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  _________________RAISE_L3__________________, _________________RAISE_R3__________________,
  _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________, _________________MEDIA_R3__________________,
  _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________, _________________MOUSE_R3__________________,
  KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN2
),
};
