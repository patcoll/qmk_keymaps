#include QMK_KEYBOARD_H
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

/* enum custom_keycodes { */
/* 	MACRO1 = SAFE_RANGE */
/* }; */
/*  */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/* 	if (record->event.pressed) { */
/* 		switch (keycode) { */
/* 			case MACRO1: */
/* 				SEND_STRING("I'm so sorry... -PyroL"); */
/* 				return false; */
/* 		} */
/* 	} */
/* 	return true; */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________QWERTY_L3_FOUR________,    SFT_SPC, KC_B,    KC_N,    KC_M
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, __________________NAV_R2___________________,
  ___________NAV_L3_FOUR____________, _______, KC_PGDN, KC_PGUP, _______
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________, _________________LOWER_R2__________________,
  __________LOWER_L3_FOUR___________, _______, KC_COMM, KC_DOT,  KC_SLSH
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  __________RAISE_L3_FOUR___________, _______, KC_COMM, KC_DOT,  KC_SLSH
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  __________MEDIA_L3_FOUR___________, _______, KC_VOLD, KC_VOLU, KC_MPLY
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  __________MOUSE_L3_FOUR___________, KC_BTN1, KC_WH_D, KC_WH_U, _______
),

	/* [HOME] = LAYOUT( */
	/* 	LCTL_T(KC_Q), LT(1, KC_W), KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, */
	/* 	KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TO(1), */
	/* 	LT(1, KC_Z), LT(2, KC_X), KC_C, LCTL_T(KC_V), MT(MOD_LSFT, KC_SPC), KC_B, KC_N, KC_M), */
  /*  */
	/* [MODS] = LAYOUT( */
	/* 	LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, */
	/* 	LSFT_T(KC_BSPC), _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TO(2), */
	/* 	KC_LCTL, KC_LGUI, KC_LALT, TO(0), MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT, KC_SLSH), */
  /*  */
	/* [MODS2] = LAYOUT( */
	/* 	LCTL_T(KC_F1), KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, */
	/* 	KC_LSFT, KC_F11, KC_F12, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, TO(3), */
	/* 	RGB_VAI, RGB_VAD, RGB_HUI, TO(0), MT(MOD_LSFT, KC_SPC), MT(MOD_MEH, KC_COMM), MT(MOD_HYPR, KC_DOT), KC_SLSH), */
  /*  */
	/* [OTHER] = LAYOUT( */
	/* 	KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, */
	/* 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, */
	/* 	RESET, KC_NO, KC_NO, TO(0), KC_BTN1, KC_MPLY, KC_VOLD, KC_VOLU), */
  /*  */
	/* [NAV] = LAYOUT( */
	/* 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, */
	/* 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, */
	/* 	RESET, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO), */
};

/* void matrix_init_user(void) { */
/* } */
/*  */
/* void matrix_scan_user(void) { */
/* } */
