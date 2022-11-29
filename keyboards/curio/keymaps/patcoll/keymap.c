/*  #<{(| Copyright 2021 projectcain  */
/*   *  */
/*   * This program is free software: you can redistribute it and/or modify  */
/*   * it under the terms of the GNU General Public License as published by  */
/*   * the Free Software Foundation, either version 2 of the License, or  */
/*   * (at your option) any later version.  */
/*   *  */
/*   * This program is distributed in the hope that it will be useful,  */
/*   * but WITHOUT ANY WARRANTY; without even the implied warranty of  */
/*   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  */
/*   * GNU General Public License for more details.  */
/*   * |)}># */
/*  */
/* #include QMK_KEYBOARD_H */
/* enum layers{ */
/*   BASE, */
/*   NUM, */
/*   SYM, */
/*   META */
/* }; */
/*  */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*   [BASE] = LAYOUT_all( */
/*     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_DEL, */
/*     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOTE,          LT(SYM, KC_ENT), */
/*     RCTL_T(S(KC_9)),        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,          S(KC_0), */
/*          KC_RCTRL, KC_LGUI, KC_LALT,     MO(1), SFT_T(KC_BSPC), KC_SPACE,  KC_SPACE,  MO(2),            KC_LEFT, KC_DOWN, KC_RIGHT */
/*   ), */
/*  */
/*   [NUM] = LAYOUT_all( */
/*     KC_TRNS,    KC_PGUP,    KC_HOME,    KC_UP,    KC_END,    KC_WBAK,    KC_PSLS,    KC_7,    KC_8,    KC_9,    KC_PMNS,    KC_DEL,    QK_BOOT, */
/*     KC_TRNS,    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_WFWD,    KC_PAST,    KC_4,    KC_5,    KC_6,    KC_PPLS,             KC_TRNS, */
/*     KC_LBRC,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT,             KC_RBRC, */
/*         KC_RCTRL, KC_LGUI, KC_LALT,     MO(1), SFT_T(KC_BSPC), KC_SPACE,  KC_SPACE,  MO(2),            KC_LEFT, KC_DOWN, KC_RIGHT */
/*   ), */
/*    */
/*   [SYM] = LAYOUT_all( */
/*     RGB_TOG,      S(KC_GRV),    KC_GRV,    KC_BSLS,    S(KC_BSLS),    KC_TRNS,    KC_TRNS,    S(KC_MINS),    KC_EQL,    KC_TRNS,    C(KC_W),    C(KC_T),   KC_TRNS, */
/*     KC_TRNS,    S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    KC_SCLN,    S(KC_SCLN),          KC_TRNS, */
/*     S(KC_LBRC),    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,             S(KC_RBRC), */
/*           KC_RCTRL, KC_LGUI, KC_LALT,     MO(1), SFT_T(KC_BSPC), KC_SPACE,  KC_SPACE,  MO(2),            KC_LEFT, KC_DOWN, KC_RIGHT */
/*   ), */
/*  */
/* }; */
/*  */
/*  */
/* enum combos { */
/*   KL_SLSH, */
/*   JK_MINUS */
/* }; */
/*  */
/* const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END}; */
/* const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END}; */
/*  */
/* combo_t key_combos[COMBO_COUNT] = { */
/*   [KL_SLSH] = COMBO(kl_combo, S(KC_SLSH)), */
/*   [JK_MINUS] = COMBO(jk_combo, KC_MINUS) */
/* }; */

#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_all(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, CS_BSPC, CS_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_ARROWS__________, SFT_SLSH,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, SFT_SPC, SFT_SPC,            RSE_ENT, KC_LCTL, __QWERTY_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC, CS_BSPC,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
  _______, _______, _______, _______, ALT_TAB, ALT_TAB,            ALT_TAB,  _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______,
  _______, _______, _______, _______, _______, _______,            _______,  _______, __OSK_R4_ARROW_KEYS___
),

[_LOWER] = LAYOUT_wrapper(
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
  _______, _______, _______, _______, _______, _______,            _______, _______, __LOWER_R4_ARROW_KEYS__
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
  _______, _______, _______, _______, _______, _______,            _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
  _______, _______, _______, _______, _______, _______,            _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
  _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1,            KC_BTN1, KC_BTN2, __MOUSE_R3_ARROW_KEYS__
),
};
