#include "embrace.h"
#include "patcoll.h"


/* enum custom_keycodes { */
/*   M_IME = SAFE_RANGE */
/* }; */
/*  */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   if (record->event.pressed) { */
/*     switch(keycode) { */
/*       case M_IME: */
/*         SEND_STRING(SS_DOWN(X_LSHIFT)SS_DOWN(X_LALT)); */
/*         return false; */
/*     } */
/*   } */
/*   else { */
/*     switch(keycode) { */
/*       case M_IME: */
/*         SEND_STRING(SS_UP(X_LSHIFT)SS_UP(X_LALT)); */
/*         return false; */
/*     } */
/*   } */
/*   return true; */
/* }; */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*   [0] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_MUTE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LT(1, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(1, KC_QUOT), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(2, KC_ENT), KC_LCTL, MO(2), KC_LGUI, KC_ENT, KC_SPC, KC_RALT, KC_RSFT, KC_RCTL, TG(3)), */
/*   [1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_TRNS, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_DOWN, KC_UP, KC_LEFT, KC_RIGHT, KC_TRNS, KC_TRNS, KC_ESC, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET), */
/*   [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_ESC, KC_PIPE, KC_DQT, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_4, KC_5, KC_6, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS), */
/*   [3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_SPC, KC_C, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS) */
/* }; */


#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_MUTE,
  SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, CS_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_ARROWS__________, SFT_SLSH,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC,                   RSE_ENT, KC_LCTL, __QWERTY_R4_ARROW_KEYS__
),

[_GAMING] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______,
  _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________, _______,
  _______, _________________GAMING_L3_________________, _________________GAMING_R3_ARROWS__________, KC_LSFT,
  _______, _______, _______, KC_SPC,                    KC_ENT,  _______, __GAMING_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
  _______, _______, _______, ALT_TAB,                   ALT_TAB,  _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______,
  _______, _______, _______, _______,                   _______,  _______, __OSK_R4_ARROW_KEYS___
),

[_LOWER] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
  _______, _______, _______, _______,                   _______, _______, __LOWER_R4_ARROW_KEYS__
),

[_RAISE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
  _______, _______, _______, _______,                   _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
  _______, _______, _______, _______,                   _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______, _______,
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
  _______, KC_BTN1, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, __MOUSE_R3_ARROW_KEYS__
),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
  return false;
}
