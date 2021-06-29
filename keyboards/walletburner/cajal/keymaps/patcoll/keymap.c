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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_stagger(
        LT(4, KC_TAB), LT(5, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_BSPC, RGB_TOG,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_LSFT, KC_SLSH), KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, LT(2, KC_SPC), LT(1, KC_ENT), LCTL_T(KC_ENT), MO(3), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT_stagger(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_BSPC, _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_LSFT, KC_PGUP,
        RESET,   _______, _______, _______, _______,  _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

    [2] = LAYOUT_stagger(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_BSPC, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, RGB_SAD, RGB_SAI, _______, KC_PGUP,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
    ),

    [3] = LAYOUT_stagger(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, S(C(KC_C)), S(C(KC_V)), _______, _______, _______, RGB_SAD, RGB_SAI, _______, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_VAD, RGB_HUI
    ),

    [4] = LAYOUT_stagger(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
    ),

    [5] = LAYOUT_stagger(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, KC_MS_U,
        _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R
    )
};

void matrix_init_user(void) {
    // set  LED 1 to output and low
    setPinOutput(B5);
    writePinHigh(B5);
    // set LED 2 to output and low
    setPinOutput(B6);
    writePinHigh(B6);
    // set LED 3 to output and low
    setPinOutput(B7);
    writePinHigh(B7);
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

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

