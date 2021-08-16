#pragma once
#include QMK_KEYBOARD_H

#define CTL_ESC    LCTL_T(KC_ESC)
#define CTL_ENT    LCTL_T(KC_ENT)
#define NAV_Z      LT(_NAV, KC_Z)
#define MOUSE_X    LT(_MOUSE, KC_X)
#define SFT_ESC    MT(MOD_LSFT, KC_ESC)
#define SFT_SLS    MT(MOD_LSFT, KC_SLSH)
#define RSE_ENT    LT(_RAISE, KC_ENT)
#define RSE_BSPC   LT(_RAISE, KC_BSPC)
#define LWR_SPC    LT(_LOWER, KC_SPC)
#define NAV_TAB    LT(_NAV, KC_TAB)
#define MOUSE_Q    LT(_MOUSE, KC_Q)
