#include "caravan2.h"
enum custom_keycodes {
  M_IME = SAFE_RANGE,
  SCRNSHT
};


/////////////////////////////
//////////SHORTCUTS//////////
/////////////////////////////
#define KC_MAGLEFT LCTL(LALT(KC_P))
#define KC_MAGCENTER LCTL(LALT(KC_O))
#define KC_MAGRIGHT LCTL(LALT(KC_G))
#define KC_MAG6ONE LCTL(LALT(KC_1))
#define KC_MAG6TWO LCTL(LALT(KC_2))
#define KC_MAG6THREE LCTL(LALT(KC_3))
#define KC_MAG6FOUR LCTL(LALT(KC_4))
#define KC_MAG6FIVE LCTL(LALT(KC_5))
#define KC_MAG6SIX LCTL(LALT(KC_6))
/////////////////////////////
//////////SHORTCUTS//////////
/////////////////////////////


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT));
        return false;
    }
  }
  switch (keycode) {
    case SCRNSHT:
      if (record->event.pressed) {
        // when keycode SCRNSHT is pressed
        register_code(KC_LGUI);
	      register_code(KC_LSFT);
        register_code(KC_LCTL);
        register_code(KC_4);
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
        unregister_code(KC_LCTL);
        unregister_code(KC_4);
      } else {
        // when keycode is released
      }
      break;

  }
  return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LT(3, KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LALT, KC_LCTL, KC_NO, KC_LGUI, LT(1, KC_SPC), LT(2, KC_SPC), KC_RGUI, KC_RCTL, KC_RALT, KC_NO),
  [1] = LAYOUT(SCRNSHT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TRNS, KC_BSLS, KC_PIPE, KC_LPRN, KC_RPRN, KC_LBRC, KC_MINS, KC_SCLN, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_DOT, KC_NO, KC_TRNS, KC_TRNS, KC_LCTL, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [2] = LAYOUT(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_NO, KC_BSLS, KC_PIPE, KC_EQL, KC_COLN, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_6, KC_TRNS, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET),
  [3] = LAYOUT(KC_NO, KC_MAGLEFT, KC_MAGCENTER, KC_MAGRIGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_MAG6ONE, KC_MAG6TWO, KC_MAG6THREE, KC_MAG6FOUR, KC_MAG6FIVE, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_ENT, KC_NO, KC_MAG6SIX, RGB_MODE_KNIGHT, RGB_MODE_RAINBOW, RGB_MODE_BREATHE, RGB_MODE_PLAIN, RGB_TOG, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SAD)
};
