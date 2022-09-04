

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*   [_BASE] = LAYOUT_split_space( */
/*     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P, */
/*     KC_GA,  KC_AS,  KC_CD,  KC_SF,   KC_G,   KC_H,  KC_SJ,   KC_CK,  KC_AL, KC_ENT, */
/*     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT, */
/*     KC_LCTL, KC_LALT, KC_LGUI, KC_BSPC, LT(_NUM_SYM,KC_SPACE), KC_RALT, KC_RGUI, KC_RCTL */
/*   ), */
/*  */
/*   [_NUM_SYM] = LAYOUT_split_space( */
/*     KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, */
/*     KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS, */
/*     KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_RCBR, KC_SCLN, KC_QUOTE, */
/*     RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/*   ) */
/* }; */

#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_split_space(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________, _________QWERTY_R3_FOUR________,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL, KC_HYPR, KC_MEH
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, __________________NAV_R2___________________,
  __________________NAV_L3___________________, _____________NAV_R3_FOUR__________,
  _______, _______, _______, ALT_TAB, ALT_TAB, _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, __________________OSK_R1___________________,
  __________________OSK_L2___________________, __________________OSK_R2___________________,
  __________________OSK_L3___________________, _____________OSK_R3_FOUR__________,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________, _________________LOWER_R2__________________,
  _________________LOWER_L3__________________, __________LOWER_R3_FOUR___________,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  _________________RAISE_L3__________________, __________RAISE_R3_FOUR___________,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________, __________MEDIA_R3_FOUR___________,
  _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________, __________MOUSE_R3_FOUR___________,
  _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN2, _______, _______
),
};
