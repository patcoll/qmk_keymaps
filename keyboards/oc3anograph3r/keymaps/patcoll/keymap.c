/*  #<{(| This program is free software: you can redistribute it and/or modify */
/*   * it under the terms of the GNU General Public License as published by */
/*   * the Free Software Foundation, either version 2 of the License, or */
/*   * (at your option) any later version. */
/*   * */
/*   * This program is distributed in the hope that it will be useful, */
/*   * but WITHOUT ANY WARRANTY; without even the implied warranty of */
/*   * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/*   * GNU General Public License for more details. */
/*   * */
/*   * You should have received a copy of the GNU General Public License */
/*   * along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/*   |)}># */
/* #include QMK_KEYBOARD_H */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*   [0] = LAYOUT( */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS */
/*   ) */
/* }; */
/*  */
/* #if defined(ENCODER_MAP_ENABLE) */
/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = { */
/*     [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) } */
/* }; */
/* #endif */
/*  */
/* #ifdef OLED_ENABLE */
/* bool oled_task_user(void) { */
/*     // Host Keyboard Layer Status */
/*     oled_write_P(PSTR("Layer: "), false); */
/*  */
/*     switch (get_highest_layer(layer_state)) { */
/*         case 0: */
/*             oled_write_P(PSTR("Default\n"), false); */
/*             break; */
/*         case 1: */
/*             oled_write_P(PSTR("FN\n"), false); */
/*             break; */
/*         case 2: */
/*             oled_write_P(PSTR("ADJ\n"), false); */
/*             break; */
/*         default: */
/*             // Or use the write_ln shortcut over adding '\n' to the end of your string */
/*             oled_write_ln_P(PSTR("Undefined"), false); */
/*     } */
/*  */
/*     // Host Keyboard LED Status */
/*     led_t led_state = host_keyboard_led_state(); */
/*     oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false); */
/*     oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false); */
/*     oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false); */
/*      */
/*     return false; */
/* } */
/* #endif */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
/*  */
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_UP,   KC_MUTE,
  KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, SFT_SPC,          RSE_ENT, RSE_ENT, KC_LCTL, __QWERTY_R4_ARROW_KEYS__
),

[_GAMING] = LAYOUT_wrapper(
  _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______,
  _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________, _______,
  _______, _________________GAMING_L3_________________, _________________GAMING_R3_________________, _______, _______,
  _______, _______, _______, KC_SPC,   KC_SPC,          KC_ENT,  KC_ENT,  _______, __GAMING_R4_ARROW_KEYS__
),

[_NAV] = LAYOUT_wrapper(
  _______, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______, _______,
  _______, _______, _______, ALT_TAB, ALT_TAB,          ALT_TAB, ALT_TAB, _______, __NAV_R4_ARROW_KEYS___
),

[_OSK] = LAYOUT_wrapper(
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, _______, __OSK_R4_ARROW_KEYS___
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, _______, __RAISE_R3_ARROW_KEYS__
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, _______, __MEDIA_R3_ARROW_KEYS__
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______, _______,
  _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN1,          KC_BTN1, KC_BTN1, KC_BTN2, __MOUSE_R3_ARROW_KEYS__
),
};
