 /*
 Copyright 2020 Alec Penland
 Copyright 2020 Garret Gartner

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "patcoll.h"

/* enum layers { */
/*   _QWERTY, */
/*   _LOWER, */
/*   _RAISE, */
/*   _NAV, */
/*   _MOUSE */
/* }; */

/* #define CTL_ESC    LCTL_T(KC_ESC) */
/* #define CTL_ENT    LCTL_T(KC_ENT) */
/* #define NAV_Z      LT(_NAV, KC_Z) */
/* #define MOUSE_X    LT(_MOUSE, KC_X) */
/* #define SFT_ESC    MT(MOD_LSFT, KC_ESC) */
/* #define SFT_SLS    MT(MOD_LSFT, KC_SLSH) */
/* #define RSE_ENT    LT(_RAISE, KC_ENT) */
/* #define RSE_BSPC   LT(_RAISE, KC_BSPC) */
/* #define LWR_SPC    LT(_LOWER, KC_SPC) */
/* #define NAV_TAB    LT(_NAV, KC_TAB) */
/* #define MOUSE_Q    LT(_MOUSE, KC_Q) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_split_space(
     /* _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
        SFT_TAB, CTL_Q,   LT1_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, KC_BSPC, RGB_TOG,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, _______,
        KC_LSFT, LT1_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_SLS, KC_UP,   _______,
        KC_LCTL, KC_LGUI, KC_LALT, LWR_SPC, RSE_ENT, CTL_ENT, MO(3),                              KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOWER] = LAYOUT_split_space(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_BSPC, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, RGB_SAD, RGB_SAI, _______, KC_PGUP, _______,
        RESET,   _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_END
    ),

    [_RAISE] = LAYOUT_split_space(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC_BSPC, _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LSFT, KC_PGUP, _______,
        RESET,   _______, _______, _______, _______, _______, _______,                            KC_HOME, KC_PGDN, KC_END
    ),

    [_NAV] = LAYOUT_split_space(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY
    ),

    [_MOUSE] = LAYOUT_split_space(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, KC_MS_U, _______,
        _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R
    ),
};






//function for layer indicator LED
layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(D0, layer_state_cmp(state, 0));
    writePin(D1, layer_state_cmp(state, 1));
    writePin(D2, layer_state_cmp(state, 2));
    return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
