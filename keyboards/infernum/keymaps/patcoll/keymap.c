/* #include QMK_KEYBOARD_H */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* 	[0] = LAYOUT( */
/*     KC_Q,   KC_W,       KC_E,     KC_R,    KC_T,   KC_MPLY,     KC_Y,      KC_U,        KC_I,     KC_O,     KC_P, */
/*     KC_A,   KC_S,       KC_D,     KC_F,    KC_G,                KC_H,      KC_J,        KC_K,     KC_L,  KC_QUOT, */
/*     KC_Z,   KC_X,       KC_C,     KC_V,    KC_B,                KC_N,      KC_M,     KC_COMM,   KC_DOT,  KC_SLSH, */
/*                      KC_LCTL,  KC_LALT,  KC_SPC,   KC_MUTE,  KC_BSPC,   KC_RGUI,     KC_RALT */
/*   ), */
/* 	[1] = LAYOUT( */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/*  */
/* 	), */
/*  */
/* 	[2] = LAYOUT( */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* 	), */
/*  */
/* 	[3] = LAYOUT( */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* 	), */
/*  */
/* 	[4] = LAYOUT( */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* 	), */
/*  */
/* 	[5] = LAYOUT( */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* 	), */
/*  */
/* 	[6] = LAYOUT( */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* 	), */
/*  */
/* 	[7] = LAYOUT( */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/* 		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* 	), */
/*  */
/* }; */
/*  */
/* #if defined(ENCODER_MAP_ENABLE) */
/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = { */
/*     [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }, */
/*     [1] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }, */
/*     [2] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }, */
/*     [3] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }, */
/*     [4] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }, */
/* 	[5] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }, */
/* 	[6] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }, */
/* 	[7] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }, */
/*     //                  Encoder 1					Encoder 2 */
/* }; */
/* #endif */
/*  */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/* 	return true; */
/* } */

#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, KC_MUTE, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________,          _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________,          _________________QWERTY_R3_________________,
  KC_LGUI, KC_LALT, SFT_SPC, _______, RSE_ENT, KC_LCTL, KC_HYPR
),

[_GAMING] = LAYOUT_wrapper(
  _________________GAMING_L1_________________, _______, _________________GAMING_R1_________________,
  _________________GAMING_L2_________________,          _________________GAMING_R2_________________,
  _________________GAMING_L3_________________,          _________________GAMING_R3_________________,
  _______, KC_SPC,  KC_SPC,  _______, KC_SPC,  KC_SPC,  _______
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, _______, __________________NAV_R1___________________,
  __________________NAV_L2___________________,          __________________NAV_R2___________________,
  __________________NAV_L3___________________,          __________________NAV_R3___________________,
  _______, _______, ALT_TAB, _______, ALT_TAB, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, _______, __________________OSK_R1___________________,
  __________________OSK_L2___________________,          __________________OSK_R2___________________,
  __________________OSK_L3___________________,          __________________OSK_R3___________________,
  _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _______, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________,          _________________LOWER_R2__________________,
  _________________LOWER_L3__________________,          _________________LOWER_R3__________________,
  _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _______, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________,          _________________RAISE_R2__________________,
  _________________RAISE_L3__________________,          _________________RAISE_R3__________________,
  _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _______, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________,          _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________,          _________________MEDIA_R3__________________,
  _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _______, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________,          _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________,          _________________MOUSE_R3__________________,
  _______, KC_NO,   KC_BTN1, _______, KC_BTN1, KC_BTN2, _______
),
};
