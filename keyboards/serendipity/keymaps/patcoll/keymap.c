/* #<{(| SPDX-License-Identifier: GPL-2.0-or-later |)}># */
/*  */
/* #include QMK_KEYBOARD_H */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*  */
/* 	[0] = LAYOUT( */
/*     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*     KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, KC_BSPC, _______, */
/*     CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,_______, */
/*     KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_LSFT, _______, */
/* 		KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL, KC_HYPR, KC_MEH,  _______ */
/* 	), */
/*  */
/* 	[1] = LAYOUT( */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
/* 	), */
/*  */
/* 	[2] = LAYOUT( */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
/* 	), */
/*  */
/* 	[3] = LAYOUT( */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, */
/* 		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX */
/* 	), */
/*  */
/* }; */


#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, KC_BSPC, _______,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,_______,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_LSFT, _______,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL, KC_HYPR, KC_MEH,  _______
),

[_NAV] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC, _______, _______,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS, _______,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______, _______,
  _______, _______, _______, ALT_TAB, ALT_TAB, _______, _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______, _______, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE, _______,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS, _______,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR, _______, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______, _______,
  _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, _______, _______, _______, _______
),
};
