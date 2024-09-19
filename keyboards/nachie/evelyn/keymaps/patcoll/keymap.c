#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_NO,
  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________, KC_NO,   _________________QWERTY_R3_________________,
  KC_LCTL, KC_LALT, SFT_SPC, RSE_ENT, KC_LCTL, KC_HYPR
),

[_GAMING] = LAYOUT_wrapper(
  _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______,
  _________________GAMING_L2_________________, _________________GAMING_R2_________________,
  _________________GAMING_L3_________________, _______, _________________GAMING_R3_________________,
  _______, _______, KC_SPC,   KC_ENT, _______, _______
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________, _______,
  __________________NAV_L2___________________, __________________NAV_R2___________________,
  __________________NAV_L3___________________, _______, __________________NAV_R3___________________,
  _______, _______, ALT_TAB, ALT_TAB, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, __________________OSK_R1___________________, _______,
  __________________OSK_L2___________________, __________________OSK_R2___________________,
  __________________OSK_L3___________________, _______, __________________OSK_R3___________________,
  _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  _________________RAISE_L3__________________, _______, _________________RAISE_R3__________________,
  _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________, _______, _________________MEDIA_R3__________________,
  _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, _______,
  _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________, _______, _________________MOUSE_R3__________________,
  _______, _______, KC_BTN1, KC_BTN1, KC_BTN2, _______
),
};
