#include QMK_KEYBOARD_H
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_arrow(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_ARROWS__________, SFT_SLSH,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC,                   RSE_ENT, CTL_ENT, __QWERTY_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3_ARROWS____________, _______,
  _______, _______, _______, ALT_TAB,                   ALT_TAB,  _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______,
  _______, _______, _______, _______,                   _______,  _______, __OSK_R4_ARROW_KEYS___
),

[_LOWER] = LAYOUT_wrapper(
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3_ARROWS___________, _______,
  _______, _______, _______, _______,                   _______, _______, __LOWER_R4_ARROW_KEYS__
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3_ARROWS___________, _______,
  _______, _______, _______, _______,                   _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3_ARROWS___________, _______,
  _______, _______, _______, _______,                   _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3_ARROWS___________, _______,
  _______, KC_BTN1, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, __MOUSE_R3_ARROW_KEYS__
),
};

/* #include QMK_KEYBOARD_H */
/* #include "patcoll.h" */
/*  */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*  */
/* [_QWERTY] = LAYOUT_arrow_command( */
/*   SFT_TAB, CTL_Q,   NAV_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*   CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
/*   KC_LSFT, NAV_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_LSFT, */
/*   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC,       KC_SPC, MT(MOD_LSFT | MOD_LCTL, KC_SPC), KC_LEFT, KC_DOWN, KC_RGHT */
/* ), */
/*  */
/* [_NAV] = LAYOUT_arrow_command( */
/*   KC_LSFT, CTL_1,   KC_2,    CS_3,    MOUSE_4, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CS_BSPC, */
/*   MO_NAV,  _______, _______, MO_LWR,  MO_RSE,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BSLS, */
/*   _______, KC_LCTL, KC_LGUI, KC_LALT, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, _______, */
/*   RESET,   _______, _______, MO_RSE,     MO_RSE,                 MO_RSE,  _______, KC_MNXT, KC_VOLD, KC_MPLY */
/* ), */
/*  */
/* #<{(| LAYOUT_all( |)}># */
/* #<{(|   KC_TILDE,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_BSPC, |)}># */
/* #<{(|   _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE, |)}># */
/* #<{(|   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,   _______,   _______,   KC_PGUP,  _______, |)}># */
/* #<{(|   RESET,   _______, _______, _______,     _______,               _______, _______, KC_HOME, KC_PGDN, KC_END |)}># */
/* #<{(| ), |)}># */
/*  */
/* [_LOWER] = LAYOUT_arrow_command( #<{(| Lower |)}># */
/*   KC_TILDE,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_BSPC, */
/*   _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE, */
/*   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,   _______,   _______,   KC_PGUP,  _______, */
/*   RESET,   _______, _______, _______, _______,                   _______, _______, KC_HOME, KC_PGDN, KC_END */
/* ), */
/*  */
/* [_RAISE] = LAYOUT_arrow_command( #<{(| Raise |)}># */
/*   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
/*   _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   RESET,   _______, _______, _______, _______,                   _______, _______, _______, _______, _______ */
/* ), */
/*  */
/* #<{(| LAYOUT_all( #<{(| Tab |)}># |)}># */
/* #<{(|   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, |)}># */
/* #<{(|   _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, |)}># */
/* #<{(|   _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, _______, |)}># */
/* #<{(|   RESET,   _______, _______, _______,     _______,               _______, _______, KC_MNXT, KC_VOLD, KC_MPLY |)}># */
/* #<{(| ), |)}># */
/*  */
/* [_MOUSE] = LAYOUT_arrow_command( #<{(| Q |)}># */
/*   _______,  _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_PSCR, */
/*   _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_MS_U, _______, */
/*   RESET,   _______, KC_BTN1, KC_BTN1,     KC_BTN1,               KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R */
/* ), */
/*  */
/*  */
/* }; */



/* [_QWERTY] = LAYOUT_arrow_command( */
/*   LT3_TAB, LT4_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
/*   CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
/*   SFT_ESC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   SFT_SLSH, */
/*   KC_LCTL, KC_LGUI, KC_LGUI, KC_LALT, LT2_SPC,                   LT1_ENT, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT */
/* ), */
/*  */
/* LAYOUT_arrow_command( #<{(| Right |)}># */
/*   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
/*   _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, */
/*   _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, */
/*   RESET,   _______, _______, _______, _______,                   _______, _______, _______, _______, _______ */
/* ), */
/*  */
/* LAYOUT_arrow_command( #<{(| Left |)}># */
/*   KC_TILDE,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_BSPC, */
/*   _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE, */
/*   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,   _______,   _______,   KC_PGUP,  _______, */
/*   RESET,   _______, _______, _______, _______,                   _______, _______, KC_HOME, KC_PGDN, KC_END */
/* ), */
/*  */
/* LAYOUT_arrow_command( #<{(| Tab |)}># */
/*   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, */
/*   _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, _______, */
/*   _______, _______, _______, _______, _______,                   _______, _______, KC_MNXT, KC_VOLD, KC_MPLY */
/* ), */
/*  */
/* LAYOUT_arrow_command( #<{(| Q |)}># */
/*   _______,  _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_PSCR, */
/*   _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U,  KC_MS_R, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_MS_U, _______, */
/*   _______, _______, _______, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R */
/* ), */
/* }; */

/* void persistent_default_layer_set(uint16_t default_layer) { */
/*   eeconfig_update_default_layer(default_layer); */
/*   default_layer_set(default_layer); */
/* } */
/*  */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*       switch(keycode) { */
/*         case DVORAK: */
/*           if (record->event.pressed) { */
/*             persistent_default_layer_set(1UL<<_DV); */
/*           } */
/*           return false; */
/*         case QWERTY: */
/*           if (record->event.pressed) { */
/*             persistent_default_layer_set(1UL<<_QW); */
/*           } */
/*           return false; */
/*         case COLEMAK: */
/*           if (record->event.pressed) { */
/*             persistent_default_layer_set(1UL<<_CM); */
/*           } */
/*           return false; */
/*         default: */
/*           return true; */
/*       } */
/*     return true; */
/* }; */
