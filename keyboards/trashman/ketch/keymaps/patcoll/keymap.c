#include QMK_KEYBOARD_H
#include "patcoll.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

LAYOUT_all(
  SFT_TAB, CTL_Q,   LT1_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_ESC, LT1_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   SFT_SLSH,
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC,       KC_SPC, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT
),

LAYOUT_all( /* Right */
  KC_GRV,  CTL_1,   KC_2,    LT2_3,   LT2_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BSLS,
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  RESET,   _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

LAYOUT_all( /* Left */
  KC_TILDE,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_BSPC,
  _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,   _______,   _______,   KC_PGUP,  _______,
  RESET,   _______, _______, _______,     _______,      _______, _______, KC_HOME, KC_PGDN, KC_END
),

LAYOUT_all( /* Tab */
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, _______,
  RESET,   _______, _______, _______,     _______,      _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
),

LAYOUT_all( /* Q */
  _______,  _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_PSCR,
  _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_MS_U, _______,
  RESET,   _______, KC_BTN1, KC_BTN1,     KC_BTN1,      KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R
),
};
