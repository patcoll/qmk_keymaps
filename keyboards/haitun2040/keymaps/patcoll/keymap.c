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
/* bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { */
/*   if (rgb_matrix_is_enabled()){ */
/*     HSV hsv = {0, 255, 0}; */
/*     if (!host_keyboard_led_state().caps_lock) { */
/*         switch (get_highest_layer(layer_state|default_layer_state)) { */
/*             case 1: */
/*                 hsv.h = 0; */
/*                 hsv.v = 255; */
/*                 break; */
/*             case 2: */
/*                 hsv.h = 85; */
/*                 hsv.v = 255; */
/*                 break; */
/*             case 3: */
/*                 hsv.h = 171; */
/*                 hsv.v = 255; */
/*                 break; */
/*             case 4: */
/*                 hsv.h = 43; */
/*                 hsv.v = 255; */
/*                 break; */
/*             case 5: */
/*                 hsv.h = 128; */
/*                 hsv.v = 255; */
/*                 break; */
/*             case 6: */
/*                 hsv.h = 213; */
/*                 hsv.v = 255; */
/*                 break; */
/*             default: //  for any other layers, or the default layer */
/*                 hsv.h = 0; */
/*                 hsv.v = 0; */
/*                 break; */
/*             }; */
/*     } */
/*     if (host_keyboard_led_state().caps_lock) { */
/*         hsv.s = 0; */
/*         hsv.v = 255; */
/*     }; */
/*     if (hsv.v > rgb_matrix_get_val()) { */
/*         hsv.v = rgb_matrix_get_val(); */
/*     } */
/*     RGB rgb = hsv_to_rgb(hsv); */
/*     rgb_matrix_set_color(0, rgb.r, rgb.g, rgb.b); */
/*   } */
/* 	return true; */
/* } */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*   [0] = LAYOUT( */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*              KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS  */
/*   ) */
/* }; */
/*  */
/* #if defined(ENCODER_MAP_ENABLE) */
/* const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = { */
/*     [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) } */
/* }; */
/* #endif */

#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, KC_BSPC,
  CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,
  KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, SFT_SLSH,
                    KC_LGUI, KC_LALT, SFT_SPC,                   RSE_ENT, RSE_ENT, KC_LCTL, KC_HYPR
),

[_GAMING] = LAYOUT_wrapper(
  _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______, _______,
  _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________, _______,
  _______, _________________GAMING_L3_________________, _________________GAMING_R3_________________, _______,
                    _______, _______, KC_SPC,                    KC_ENT,  _______, _______, _______
),

[_NAV] = LAYOUT_wrapper(
  KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC, CS_BSPC,
  KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
  KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, _______,
                    _______, _______, ALT_TAB,                   ALT_TAB,  _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  _______, __________________OSK_L1___________________, __________________OSK_R1___________________, _______, _______,
  _______, __________________OSK_L2___________________, __________________OSK_R2___________________, _______,
  _______, __________________OSK_L3___________________, __________________OSK_R3___________________, _______,
                    _______, _______, _______,                   _______,  _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  KC_TILDE,_________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______,
  _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
  _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
                    _______, _______, _______,                   _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______,
  _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
  _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
                    _______, _______, _______,                   _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______,
  _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
  _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
                    _______, _______, _______,                   _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR, _______,
  _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
  _______, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
                    KC_BTN1, KC_BTN1, KC_BTN1,                   KC_BTN1, KC_BTN2, _______, _______
),
};
