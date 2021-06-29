/* Copyright 2015-2017 Jack Humbert
 * Copyright 2020 Pat Collins
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

/*
 * This is an adaptation of the default layout with some small mods for my
 * typical keyboard layout. ~@patcoll
 */

#include QMK_KEYBOARD_H
#include "muse.h"



/* enum preonic_layers { */
/*   _QWERTY, */
/*   _COLEMAK, */
/*   _DVORAK, */
/*   _LOWER, */
/*   _RAISE, */
/*   _ADJUST, */
/*   _MEDIA, */
/*   _CUSTOM, */
/*   _MOUSE */
/* }; */
/*  */
/* enum preonic_keycodes { */
/*   QWERTY = SAFE_RANGE, */
/*   COLEMAK, */
/*   DVORAK, */
/*   LOWER, */
/*   RAISE, */
/*   BACKLIT */
/* }; */



#define X_NP KC_NO // key is not present
#define X_NA KC_NO // present but not available for use
#define X_NU KC_NO // available but not used

enum layers { BASE, MBO, MEDR, NAVR, MOUR, NSSL, NSL, FUNL };



/* #define CTL_ESC LCTL_T(KC_ESC) */
/* #define TAB_FN LT(_CUSTOM,KC_TAB) */
/* #define GRV_FN LT(_MOUSE,KC_GRV) */
/* #define FN LT(_MEDIA,KC_ESC) */
/* #define FN_1 LSFT_T(KC_1) */
/* #define FN_2 LALT_T(KC_2) */
/* #define FN_3 LGUI_T(KC_3) */
/* #define FN_E LGUI_T(KC_E) */
/* #define SPCFN_L LT(_LOWER,KC_SPC) */
/* #define SPCFN_R1 LT(_MEDIA,KC_SPC) */
/* #define SPCFN_R2 LT(_RAISE,KC_SPC) */
/* #define SFT_ENT RSFT_T(KC_ENT) */

/* #define SFT_L RSFT_T(KC_ENT) */
/* #define SFT_R RSFT_T(KC_ENT) */
/* #define SFT_U RSFT_T(KC_ENT) */
/* #define SFT_D RSFT_T(KC_ENT) */
/* #define SFT_HOM RSFT_T(KC_ENT) */
/* #define SFT_END RSFT_T(KC_ENT) */

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
        case LSFT_T(KC_N):
            return TAPPING_TERM + 50;
        case LSFT_T(KC_G):
        case LSFT_T(KC_H):
            return TAPPING_TERM - 20;
        case LT(MEDR, KC_ESC):
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_preonic_grid(
  KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             X_NU,             X_NU,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,
  KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             X_NU,             X_NU,             KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,
  LGUI_T(KC_A),     LGUI_T(KC_S),     LALT_T(KC_D),     LCTL_T(KC_F),     LSFT_T(KC_G),     X_NU,             X_NU,             LSFT_T(KC_H),     LCTL_T(KC_J),     LALT_T(KC_K),     LGUI_T(KC_L),     LGUI_T(KC_SCLN),
  KC_Z,             KC_X,             KC_C,             KC_V,             LSFT_T(KC_B),     X_NU,             X_NU,             LSFT_T(KC_N),     KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,
  X_NU,             X_NU,             X_NU,             LT(MEDR, KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_TAB), LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LT(FUNL, KC_DEL), X_NU,             X_NU,             X_NU
),

[NAVR] = LAYOUT_preonic_grid(
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  RESET,            X_NA,             X_NA,             X_NA,             X_NA,             _______,          _______,          KC_AGIN,          KC_UNDO,          KC_CUT,           KC_COPY,          KC_PSTE,
  KC_LGUI,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          _______,          _______,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_CAPS,
  X_NA,             X_NA,             X_NA,             X_NA,             KC_LSFT,          _______,          _______,          KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           KC_INS,
  X_NU,             X_NU,             X_NA,             X_NA,             X_NA,             X_NU,             X_NU,             KC_ENT,           KC_BSPC,          KC_DEL,           X_NU,             X_NU
),

[MOUR] = LAYOUT_preonic_grid(
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  RESET,            X_NA,             X_NA,             X_NA,             X_NA,             _______,          _______,          X_NU,             X_NU,             X_NU,             X_NU,             X_NU,
  KC_LGUI,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          _______,          _______,          KC_MS_L,          KC_MS_D,          KC_MS_U,          KC_MS_R,          X_NU,
  X_NA,             X_NA,             X_NA,             X_NA,             KC_LSFT,          _______,          _______,          KC_WH_L,          KC_WH_D,          KC_WH_U,          KC_WH_R,          X_NU,
  X_NU,             X_NU,             X_NA,             X_NA,             X_NA,             X_NU,             KC_BTN1,          KC_BTN3,          KC_BTN2,          X_NU,             X_NU,             X_NU
),

[MEDR] = LAYOUT_preonic_grid(
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  RESET,            X_NA,             X_NA,             X_NA,             X_NA,             _______,          _______,          RGB_TOG,          RGB_MOD,          RGB_HUI,          RGB_SAI,          RGB_VAI,
  KC_LGUI,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          _______,          _______,          KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT,          X_NU,
  X_NA,             X_NA,             X_NA,             X_NA,             KC_LSFT,          _______,          _______,          X_NU,             X_NU,             X_NU,             X_NU,             X_NU,
  X_NU,             X_NU,             X_NA,             X_NA,             X_NA,             X_NU,             KC_MSTP,          KC_MPLY,          KC_MUTE,          X_NU,             X_NU,             X_NU
),

[MBO] = LAYOUT_preonic_grid(
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  _______,          _______,          _______,          _______,          _______,          _______,          KC_BTN1,          KC_BTN3,          KC_BTN2,          _______,          _______,          _______
),

[FUNL] = LAYOUT_preonic_grid(
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  KC_F12,           KC_F7,            KC_F8,            KC_F9,            KC_PSCR,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  KC_F11,           KC_F4,            KC_F5,            KC_F6,            KC_SLCK,          _______,          _______,          KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          KC_LGUI,
  KC_F10,           KC_F1,            KC_F2,            KC_F3,            KC_PAUS,          _______,          _______,          KC_LSFT,          _______,          _______,          _______,          _______,
  _______,          _______,          _______,          KC_APP,           KC_SPC,           KC_TAB,           _______,          _______,          _______,          _______,          _______,          _______
),

[NSL] = LAYOUT_preonic_grid(
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  KC_LBRC,          KC_7,             KC_8,             KC_9,             KC_RBRC,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  KC_QUOT,          KC_4,             KC_5,             KC_6,             KC_EQL,           _______,          _______,          KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          KC_LGUI,
  KC_GRV,           KC_1,             KC_2,             KC_3,             KC_BSLS,          _______,          _______,          KC_LSFT,          _______,          _______,          _______,          _______,
  _______,          _______,          _______,          KC_DOT,           KC_0,             KC_MINS,          _______,          _______,          _______,          _______,          _______,          _______
),

[NSSL] = LAYOUT_preonic_grid(
  _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  KC_LCBR,          KC_AMPR,          KC_ASTR,          KC_LPRN,          KC_RCBR,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
  KC_DQUO,          KC_DLR,           KC_PERC,          KC_CIRC,          KC_PLUS,          _______,          _______,          KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          KC_LGUI,
  KC_TILD,          KC_EXLM,          KC_AT,            KC_HASH,          KC_PIPE,          _______,          _______,          KC_LSFT,          _______,          _______,          _______,          _______,
  _______,          _______,          _______,          KC_LPRN,          KC_RPRN,          KC_UNDS,          _______,          _______,          _______,          _______,          _______,          _______
),

/* [_LOWER] = LAYOUT_preonic_grid( */
/*   RGB_MOD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, */
/*   _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, */
/*   RGB_TOG, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, */
/*   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______, */
/*   RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ), */
/*  */
/* [_RAISE] = LAYOUT_preonic_grid( */
/*   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
/*   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, */
/*   KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, */
/*   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ), */
/*  */
/* [_ADJUST] = LAYOUT_preonic_grid( */
/*   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, */
/*   _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL, */
/*   _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, */
/*   _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ), */
/*  */
/* [_MEDIA] = LAYOUT_preonic_grid( */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET */
/* ), */
/*  */
/* [_CUSTOM] = LAYOUT_preonic_grid( */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_MUTE, */
/*   _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/* ), */
/*  */
/* [_MOUSE] = LAYOUT_preonic_grid( */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, KC_MUTE, */
/*   _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*   _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R */
/* ) */
/*  */
};

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*         case QWERTY: */
/*           if (record->event.pressed) { */
/*             set_single_persistent_default_layer(_QWERTY); */
/*           } */
/*           return false; */
/*           break; */
/*         case COLEMAK: */
/*           if (record->event.pressed) { */
/*             set_single_persistent_default_layer(_COLEMAK); */
/*           } */
/*           return false; */
/*           break; */
/*         case DVORAK: */
/*           if (record->event.pressed) { */
/*             set_single_persistent_default_layer(_DVORAK); */
/*           } */
/*           return false; */
/*           break; */
/*         case LOWER: */
/*           if (record->event.pressed) { */
/*             layer_on(_LOWER); */
/*             update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*           } else { */
/*             layer_off(_LOWER); */
/*             update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*           } */
/*           return false; */
/*           break; */
/*         case RAISE: */
/*           if (record->event.pressed) { */
/*             layer_on(_RAISE); */
/*             update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*           } else { */
/*             layer_off(_RAISE); */
/*             update_tri_layer(_LOWER, _RAISE, _ADJUST); */
/*           } */
/*           return false; */
/*           break; */
/*         case BACKLIT: */
/*           if (record->event.pressed) { */
/*             register_code(KC_RSFT); */
/*             #ifdef BACKLIGHT_ENABLE */
/*               backlight_step(); */
/*             #endif */
/*             #ifdef __AVR__ */
/*             writePinLow(E6); */
/*             #endif */
/*           } else { */
/*             unregister_code(KC_RSFT); */
/*             #ifdef __AVR__ */
/*             writePinHigh(E6); */
/*             #endif */
/*           } */
/*           return false; */
/*           break; */
/*       } */
/*     return true; */
/* }; */

/* bool muse_mode = false; */
/* uint8_t last_muse_note = 0; */
/* uint16_t muse_counter = 0; */
/* uint8_t muse_offset = 70; */
/* uint16_t muse_tempo = 50; */
/*  */
/* void encoder_update_user(uint8_t index, bool clockwise) { */
/*   if (muse_mode) { */
/*     if (IS_LAYER_ON(_RAISE)) { */
/*       if (clockwise) { */
/*         muse_offset++; */
/*       } else { */
/*         muse_offset--; */
/*       } */
/*     } else { */
/*       if (clockwise) { */
/*         muse_tempo+=1; */
/*       } else { */
/*         muse_tempo-=1; */
/*       } */
/*     } */
/*   } else { */
/*     if (clockwise) { */
/*       register_code(KC_PGDN); */
/*       unregister_code(KC_PGDN); */
/*     } else { */
/*       register_code(KC_PGUP); */
/*       unregister_code(KC_PGUP); */
/*     } */
/*   } */
/* } */
/*  */
/* void dip_switch_update_user(uint8_t index, bool active) { */
/*     switch (index) { */
/*         case 0: */
/*             if (active) { */
/*                 layer_on(_ADJUST); */
/*             } else { */
/*                 layer_off(_ADJUST); */
/*             } */
/*             break; */
/*         case 1: */
/*             if (active) { */
/*                 muse_mode = true; */
/*             } else { */
/*                 muse_mode = false; */
/*             } */
/*     } */
/* } */
/*  */
/*  */
/* void matrix_scan_user(void) { */
/* #ifdef AUDIO_ENABLE */
/*     if (muse_mode) { */
/*         if (muse_counter == 0) { */
/*             uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()]; */
/*             if (muse_note != last_muse_note) { */
/*                 stop_note(compute_freq_for_midi_note(last_muse_note)); */
/*                 play_note(compute_freq_for_midi_note(muse_note), 0xF); */
/*                 last_muse_note = muse_note; */
/*             } */
/*         } */
/*         muse_counter = (muse_counter + 1) % muse_tempo; */
/*     } else { */
/*         if (muse_counter) { */
/*             stop_all_notes(); */
/*             muse_counter = 0; */
/*         } */
/*     } */
/* #endif */
/* } */
/*  */
/* bool music_mask_user(uint16_t keycode) { */
/*   switch (keycode) { */
/*     case RAISE: */
/*     case LOWER: */
/*       return false; */
/*     default: */
/*       return true; */
/*   } */
/* } */
