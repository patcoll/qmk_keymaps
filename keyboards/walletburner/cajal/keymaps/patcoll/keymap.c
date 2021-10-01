/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_stagger(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_wrapper(
        SFT_TAB, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, CS_BSPC, KC_MPLY,
        CTL_ESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, SFT_QUOT,
        KC_LSFT, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, SFT_SPC, RSE_ENT, CTL_ENT, KC_HYPR,                            KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_NAV] = LAYOUT_wrapper(
        KC_LSFT, __________________NAV_L1___________________, __________________NAV_R1___________________, CS_BSPC, _______, _______,
        KC_LCTL, __________________NAV_L2___________________, __________________NAV_R2___________________, KC_BSLS,
        KC_LSFT, __________________NAV_L3___________________, __________________NAV_R3___________________, KC_PGUP,
        _______, _______, _______, _______, ALT_TAB, KC_LCTL, _______,                            KC_HOME, KC_PGDN, KC_END
    ),

    [_LOWER] = LAYOUT_wrapper(
        KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______, _______, _______,
        KC_LCTL, _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
        KC_LSFT, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
        _______, _______, _______, _______, _______, KC_LCTL, _______,                            _______, _______, _______
    ),

    [_RAISE] = LAYOUT_wrapper(
        KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______, _______, _______,
        KC_LCTL, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
        KC_LSFT, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
        _______, _______, _______, _______, _______, KC_LCTL, _______,                            _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________, _______, _______, _______,
        _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________, _______,
        _______, _________________MEDIA_L3__________________, _________________MEDIA_R3__________________, _______,
        _______, _______, _______, _______, _______, KC_LCTL, _______,                            _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_wrapper(
        KC_LSFT, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________, KC_PSCR, _______, _______,
        KC_LCTL, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________, _______,
        KC_LSFT, _________________MOUSE_L3__________________, _________________MOUSE_R3__________________, _______,
        _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN2,                            _______, _______, _______
    )
};

void matrix_init_user(void) {
    // set  LED 1 to output and low
    setPinOutput(B5);
    writePinLow(B5);
    // set LED 2 to output and low
    setPinOutput(B6);
    writePinLow(B6);
    // set LED 3 to output and low
    setPinOutput(B7);
    writePinLow(B7);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    /* switch (get_highest_layer(state)) { */
    /* case 1: */
    /*     writePinHigh(B7); */
    /*     writePinLow(B6); */
    /*     break; */
    /* case 2: */
    /*     writePinLow(B7); */
    /*     writePinHigh(B6); */
    /*     break; */
    /* case 3: */
    /*     writePinHigh(B7); */
    /*     writePinHigh(B6); */
    /*     break; */
    /* default: */
    /*     writePinLow(B7); */
    /*     writePinLow(B6); */
    /*     break; */
    /* } */
    return state;
}

bool led_update_user(led_t led_state) {
    /* writePin(B5, led_state.caps_lock); */
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }

    return true;
}

