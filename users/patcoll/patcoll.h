#pragma once
#include QMK_KEYBOARD_H

void oled_render_layer_state(void);

enum userspace_layers {
  _QWERTY,
  _NUMBERS,
  _NAV,
  _MOUSE,
  _GLOWER,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#ifdef OLED_DRIVER_ENABLE
#define L_QWERTY 0
#define L_QWERTY_MODS 2
#define L_COLEMAK 4
#define L_COLEMAK_MODS 8
#define L_HANDSDOWN 16
#define L_HANDSDOWN_MODS 32
#define L_GAMER 64
#define L_GAMER2 128
#define L_TOUHOU 256
#define L_NUMBERS 512
#define L_NAV 1024
#define L_GLOWER 2048
#define L_LOWER 4096
#define L_RAISE 8192
#define L_ADJUST 16384
#endif // OLED_DRIVER_ENABLE

#define CTL_ESC    MT(MOD_LCTL, KC_ESC)
#define CTL_ENT    MT(MOD_LCTL, KC_ENT)
#define CTL_Q      MT(MOD_LCTL, KC_Q)
#define CTL_1      MT(MOD_LCTL, KC_1)


#define LT1_W LT(1, KC_W)
#define LT1_Z LT(1, KC_Z)

#define LT2_3   LT(2, KC_3)
#define LT2_4   LT(2, KC_4)

#define LWR_SPC    LT(_LOWER, KC_SPC)
#define RSE_ENT    LT(_RAISE, KC_ENT)
#define RSE_BSPC   LT(_RAISE, KC_BSPC)

// #define NAV_Z      LT(_NAV, KC_Z)
// #define MOUSE_X    LT(_MOUSE, KC_X)
#define SFT_ESC    MT(MOD_LSFT, KC_ESC)
#define SFT_TAB    MT(MOD_LSFT, KC_TAB)
#define SFT_SLSH   MT(MOD_LSFT, KC_SLSH)

// #define NAV_TAB    LT(_NAV, KC_TAB)
// #define MOUSE_Q    LT(_MOUSE, KC_Q)
