/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
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

/* #include QMK_KEYBOARD_H */
/*  */
/* // Each layer gets a name for readability, which is then used in the keymap matrix below. */
/* // The underscores don't mean anything - you can have a layer called STUFF or any other name. */
/* // Layer names don't all need to be of the same length, obviously, and you can also skip them */
/* // entirely and just use numbers. */
/*  */
/* enum layer_number { */
/*     _QWERTY = 0, */
/*     _RAISE, */
/*     _LOWER, */
/* }; */
/*  */
/* #define KC_L_SPC LT(_LOWER, KC_SPC)  // lower */
/* #define KC_R_ENT LT(_RAISE, KC_ENT)  // raise */
/* #define KC_G_JA LGUI_T(KC_LANG1)     // cmd or win */
/* #define KC_G_EN LGUI_T(KC_LANG2)     // cmd or win */
/* #define KC_C_BS LCTL_T(KC_BSPC)      // ctrl */
/* #define KC_A_DEL ALT_T(KC_DEL)       // alt */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     [_QWERTY] = LAYOUT( \ */
/*     //,--------+--------+---------+--------+---------+--------.   ,--------+---------+--------+---------+--------+--------. */
/*        KC_TAB , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,     KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_BSPC, */
/*     //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------| */
/*        LCTL_T(KC_ESC) , KC_A   , KC_S    , KC_D   , KC_F    , KC_G   ,     KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_QUOT, */
/*     //|--------+--------+---------+--------+---------+--------|   |--------+---------+--------+---------+--------+--------| */
/*        KC_LSFT, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,     KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, KC_RSFT, */
/*     //`--------+--------+---------+--------+---------+--------/   \--------+---------+--------+---------+--------+--------' */
/*                          KC_A_DEL, KC_G_EN, KC_L_SPC, KC_C_BS,     KC_C_BS, KC_R_ENT, KC_G_JA, KC_A_DEL */
/*     //                 `----------+--------+---------+--------'   `--------+---------+--------+---------' */
/*     ), */
/*  */
/*     [_RAISE] = LAYOUT( \ */
/*     //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------. */
/*        _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,     KC_AT  , KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS, */
/*     //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------| */
/*        KC_LPRN, KC_HASH, KC_DLR , KC_DQT , KC_QUOT, KC_TILD,     KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_GRV , KC_RPRN, */
/*     //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------| */
/*        _______, _______, _______, _______, KC_LCBR, KC_LBRC,     KC_RBRC, KC_RCBR, _______, _______, _______, _______, */
/*     //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------' */
/*                          _______, _______, _______, _______,     _______, _______, _______, RESET */
/*     //                  `--------+--------+--------+--------'   `--------+--------+--------+--------' */
/*     ), */
/*  */
/*     [_LOWER] = LAYOUT( \ */
/*     //,--------+--------+--------+--------+--------+--------.   ,--------+--------+--------+--------+--------+--------. */
/*        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     _______, KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS, */
/*     //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------| */
/*        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, */
/*     //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------| */
/*        KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,     _______, _______, KC_COMM, KC_DOT , KC_SLSH, _______, */
/*     //`--------+--------+--------+--------+--------+--------/   \--------+--------+--------+--------+--------+--------' */
/*                          RESET  , _______, _______, _______,     _______, _______, _______, _______ */
/*     //                  `--------+--------+--------+--------'   `--------+--------+--------+--------' */
/*     ), */
/* }; */

#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

#define X_NP KC_NO // key is not present
#define X_NA KC_NO // present but not available for use
#define X_NU KC_NO // available but not used

/* enum layers { BASE, MBO, MEDR, NAVR, MOUR, NSSL, NSL, FUNL }; */
enum layers { BASE, MEDR, NAVR, MOUR, NSSL, NSL, FUNL };

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case LGUI_T(KC_A): */
        /* #<{(|     return TAPPING_TERM - 50; |)}># */
        /* case LGUI_T(KC_S): */
        /* case LGUI_T(KC_L): */
        /* case LGUI_T(KC_SCLN): */
        /* case LSFT_T(KC_B): */
        /* case LSFT_T(KC_N): */
        /*     return TAPPING_TERM + 100; */

        case LSFT_T(KC_F):
        case LSFT_T(KC_G):
            return 145;
        case LSFT_T(KC_H):
        case LSFT_T(KC_J):
            return 145;
        case LSFT_T(KC_ENT):
            return 145;

        /* case LT(NAVR, KC_SPC): */
        /* case LT(MOUR, KC_SPC): */
        /* case LT(MEDR, KC_ESC): */
        /*     return TAPPING_TERM + 45; */

        /* case LT(NSSL, KC_ENT): */
            /* return TAPPING_TERM - 40; */

        /* case LT(NSL, KC_BSPC): */
            /* return TAPPING_TERM - 30; */

        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case LSFT_T(KC_F):
        case LSFT_T(KC_J):
        /* case LSFT_T(KC_B): */
        /* case LSFT_T(KC_N): */
            return true;
        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
        case LGUI_T(KC_A): // same
        case LALT_T(KC_S):
        case LCTL_T(KC_D):
        case LSFT_T(KC_F):
        /* case LSFT_T(KC_G): */
        case LSFT_T(KC_J):
        case LCTL_T(KC_K):
        case LALT_T(KC_L):
        /* case LGUI_T(KC_L): */
        case LGUI_T(KC_SCLN): // same

        /* case LSFT_T(KC_B): */
        /* case LSFT_T(KC_N): */
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT(
  KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,                                                 KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_BSPC,
  LCTL_T(KC_ESC),   LGUI_T(KC_A),     LGUI_T(KC_S),     LALT_T(KC_D),     LCTL_T(KC_F),     LSFT_T(KC_G),                                         LSFT_T(KC_H),     LCTL_T(KC_J),     LALT_T(KC_K),     LGUI_T(KC_L),     LGUI_T(KC_SCLN),  KC_QUOT,
  KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,                                         KC_N,     KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          LSFT_T(KC_ENT),
                                                        X_NU,             LT(MEDR, KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_SPC), LT(NSSL, KC_ENT), LT(NSL, KC_ENT), LT(FUNL, KC_BSPC), KC_DEL
),

[NAVR] = LAYOUT(
  _______,          RESET,            X_NA,             X_NA,             X_NA,             X_NA,                                                 KC_AGIN,          KC_UNDO,          KC_CUT,           KC_COPY,          KC_PSTE,          _______,
  _______,          KC_LGUI,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,                                              KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_CAPS,          _______,
  _______,          X_NA,             X_NA,             X_NA,             X_NA,             X_NA,                                                 KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           KC_INS,           _______,
                                                        X_NU,             X_NA,             X_NA,             X_NA,             KC_ENT,           KC_ENT,           KC_BSPC,          KC_DEL
),

[MOUR] = LAYOUT(
  _______,          RESET,            X_NA,             X_NA,             X_NA,             X_NA,                                                 X_NU,             X_NU,             X_NU,             X_NU,             X_NU,             _______,
  _______,          KC_LGUI,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,                                              KC_MS_L,          KC_MS_D,          KC_MS_U,          KC_MS_R,          X_NU,             _______,
  _______,          X_NA,             X_NA,             X_NA,             X_NA,             X_NA,                                                 KC_WH_L,          KC_WH_D,          KC_WH_U,          KC_WH_R,          X_NU,             _______,
                                                        X_NU,             X_NA,             X_NA,             X_NA,             KC_BTN1,          KC_BTN1,          KC_BTN2,          X_NU
),

[MEDR] = LAYOUT(
  _______,          RESET,            X_NA,             X_NA,             X_NA,             X_NA,                                                 RGB_TOG,          RGB_MOD,          RGB_HUI,          RGB_SAI,          RGB_VAI,          _______,
  _______,          KC_LGUI,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,                                              KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT,          X_NU,             _______,
  _______,          X_NA,             X_NA,             X_NA,             X_NA,             X_NA,                                                 X_NU,             X_NU,             X_NU,             X_NU,             X_NU,             _______,
                                                        X_NU,             X_NA,             X_NA,             X_NA,             KC_MSTP,          KC_MPLY,          KC_MUTE,          X_NU
),

/* [MBO] = LAYOUT( */
/*   _______,          _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______, */
/*   _______,          _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______, */
/*   _______,          _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______, */
/*                                                         _______,          _______,          _______,          _______,          KC_BTN1,          KC_BTN3,          KC_BTN2,          _______ */
/* ), */

[FUNL] = LAYOUT(
  _______,          KC_F12,           KC_F7,            KC_F8,            KC_F9,            KC_PSCR,                                              _______,          _______,          _______,          _______,          RESET,            _______,
  _______,          KC_F11,           KC_F4,            KC_F5,            KC_F6,            KC_SLCK,                                              KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          KC_LGUI,          _______,
  _______,          KC_F10,           KC_F1,            KC_F2,            KC_F3,            KC_PAUS,                                              _______,          _______,          _______,          _______,          _______,          _______,
                                                        _______,          KC_APP,           KC_SPC,           KC_TAB,           _______,          _______,          _______,          _______
),

[NSL] = LAYOUT(
  _______,          KC_LBRC,          KC_7,             KC_8,             KC_9,             KC_RBRC,                                              _______,          _______,          _______,          _______,          RESET,            _______,
  _______,          KC_QUOT,          KC_4,             KC_5,             KC_6,             KC_EQL,                                               KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          KC_LGUI,          _______,
  _______,          KC_GRV,           KC_1,             KC_2,             KC_3,             KC_BSLS,                                              _______,          _______,          _______,          _______,          _______,          _______,
                                                        _______,          KC_DOT,           KC_0,             KC_MINS,          _______,          _______,          _______,          _______
),

[NSSL] = LAYOUT(
  _______,          KC_LCBR,          KC_AMPR,          KC_ASTR,          KC_LPRN,          KC_RCBR,                                              _______,          _______,          _______,          _______,          RESET,            _______,
  _______,          KC_DQUO,          KC_DLR,           KC_PERC,          KC_CIRC,          KC_PLUS,                                              KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          KC_LGUI,          _______,
  _______,          KC_TILD,          KC_EXLM,          KC_AT,            KC_HASH,          KC_PIPE,                                              _______,          _______,          _______,          _______,          _______,          _______,
                                                        _______,          KC_LPRN,          KC_RPRN,          KC_UNDS,          _______,          _______,          _______,          _______
),
};
