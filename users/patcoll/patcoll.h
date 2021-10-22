#pragma once
#include QMK_KEYBOARD_H

void oled_render_layer_state(void);

enum userspace_layers {
  _QWERTY = 0,
  _NUMBERS,
  _NAV,
  _MEDIA,
  _MOUSE,
  _GLOWER,
  _LOWER,
  _RAISE,
  _ADJUST,
  _BLANK1,
  _BLANK2,
  _BLANK3,
  _BLANK4,
  _BLANK5,
  _BLANK6,
};

enum userspace_custom_keycodes {
  // TG_CLMK = SAFE_RANGE,
  // TG_HNDS,
  // TG_QWER,
  // GAMEOVR,
  // HR_MODS,
  ALT_TAB = SAFE_RANGE,
  SALTTAB,
  NXT_TAB,
  PRV_TAB,
  EX_PIPE,
  EX_INSP,
  EX_SEAR,
  // WNDW_1,
  // WNDW_2,
  // WNDW_3,
  // WNDW_4,
  // WNDW_5,
  // WNDW_6,
  // WNDW_7,
  // WNDW_8,
  // WNDW_9,
  // WNDW_0,
# ifdef QUICK_SWITCH
  QCK_TAB,
  QCKSTAB,
  QCK_SEL,
# endif
  NEW_SAFE_RANGE
};

#define CTL_ESC    MT(MOD_LCTL, KC_ESC)
#define CTL_ENT    MT(MOD_LCTL, KC_ENT)
#define CTL_Q      MT(MOD_LCTL, KC_Q)
#define CTL_1      MT(MOD_LCTL, KC_1)


#define NAV_W LT(_NAV, KC_W)
#define NAV_Z LT(_NAV, KC_Z)
// #define ATAB_C LT(_ATAB, KC_C)

#define MO_NAV MO(_NAV)

#define CTL_V LCTL_T(KC_V)

#define LT1_W LT(1, KC_W)
#define LT1_Z LT(1, KC_Z)

#define MOUSE_3   LT(_MOUSE, KC_3)
#define MOUSE_4   LT(_MOUSE, KC_4)

#define LT2_3   LT(2, KC_3)
#define LT2_4   LT(2, KC_4)
#define LT3_4   LT(3, KC_4)

#define SFT_3   MT(MOD_LSFT, KC_3)
#define CS_3   MT(MOD_LCTL | MOD_LSFT, KC_3)
#define CS_4   MT(MOD_LCTL | MOD_LSFT, KC_4)
#define CS_BSPC   MT(MOD_LCTL | MOD_LSFT, KC_BSPC)
#define CS_0   MT(MOD_LCTL | MOD_LSFT, KC_0)

#define MO_LWR     MO(_LOWER)
#define MO_RSE     MO(_RAISE)
#define MO_MED     MO(_MEDIA)

#define LWR_SPC    LT(_LOWER, KC_SPC)
#define RSE_ENT    LT(_RAISE, KC_ENT)
#define RSE_BSPC   LT(_RAISE, KC_BSPC)

// #define NAV_Z      LT(_NAV, KC_Z)
// #define MOUSE_X    LT(_MOUSE, KC_X)
#define SFT_ESC    MT(MOD_LSFT, KC_ESC)
#define SFT_TAB    MT(MOD_LSFT, KC_TAB)
#define SFT_SCLN   MT(MOD_LSFT, KC_SCLN)
#define SFT_QUOT   MT(MOD_LSFT, KC_QUOT)
#define SFT_SLSH   MT(MOD_LSFT, KC_SLSH)
#define SFT_SPC    MT(MOD_LSFT, KC_SPC)
#define SFT_ENT    MT(MOD_LSFT, KC_ENT)

#define CTL_SCLN   MT(MOD_LCTL, KC_SCLN)
#define CTL_SLSH   MT(MOD_LCTL, KC_SLSH)


// #define NAV_TAB    LT(_NAV, KC_TAB)
// #define MOUSE_Q    LT(_MOUSE, KC_Q)

#define _________________QWERTY_L1_________________       CTL_Q,   NAV_W,   KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define         _________QWERTY_L3_FOUR________           NAV_Z,   KC_X,    KC_C,  CTL_V
#define _________________QWERTY_L3_________________       _________QWERTY_L3_FOUR________,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define         _________QWERTY_R2_FOUR________           KC_H,    KC_J,    KC_K,    KC_L
#define _________________QWERTY_R2_________________       _________QWERTY_R2_FOUR________,    CTL_SCLN
#define _________QWERTY_R3_FOUR________                   KC_N,    KC_M,    KC_COMM, KC_DOT
#define _________________QWERTY_R3_________________       _________QWERTY_R3_FOUR________,    SFT_SLSH
#define _________________QWERTY_R3_ARROWS__________       _________QWERTY_R3_FOUR________,    KC_UP
#define                __QWERTY_R3_ARROW_KEYS__                                      KC_LEFT, KC_DOWN, KC_RGHT

// Numbers and stuff
#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _______________SYMBOLS_LEFT________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _______________SYMBOLS_RIGHT_______________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

// Nav stuff
#define __________________NAV_L1___________________       CTL_1,   KC_2,    SFT_3,   MOUSE_4, KC_5
#define __________________NAV_L2___________________       _______, _______, MO_MED,  MO_RSE,  MO_LWR
#define ___________NAV_L3_FOUR____________                KC_LCTL, KC_LGUI, KC_LALT, TO(_QWERTY)
#define __________________NAV_L3___________________       ___________NAV_L3_FOUR____________, _______

#define __________________NAV_R1___________________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define      _____________NAV_R2_FOUR__________           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
#define __________________NAV_R2___________________       _____________NAV_R2_FOUR__________, ALT_TAB
#define _____________NAV_R3_FOUR__________                KC_HOME, KC_PGDN, KC_PGUP, KC_END
#define __________________NAV_R3___________________       _____________NAV_R3_FOUR__________, _______
#define __________________NAV_R3_ARROWS____________       _____________NAV_R3_FOUR__________, _______
#define                 __NAV_R4_ARROW_KEYS___                                       _______, _______, _______

// Lower
#define _________________LOWER_L1__________________       _______________SYMBOLS_LEFT________________
#define _________________LOWER_L2__________________       _________________FUNC_LEFT_________________
#define __________LOWER_L3_FOUR___________                RESET,   _______, _______, TO(_QWERTY)
#define _________________LOWER_L3__________________       __________LOWER_L3_FOUR___________, _______

#define _________________LOWER_R1__________________       _______________SYMBOLS_RIGHT_______________
#define __________LOWER_R2_FOUR___________                KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R2__________________       _______, __________LOWER_R2_FOUR___________
#define __LOWER_R3_TWO__                                  KC_TILD, KC_PIPE
#define __________LOWER_R3_FOUR___________                __LOWER_R3_TWO__, _______, _______
#define _________________LOWER_R3__________________       __________LOWER_R3_FOUR___________, KC_PIPE
#define _________________LOWER_R3_ARROWS___________       __________LOWER_R3_FOUR___________, KC_PIPE
#define                __LOWER_R4_ARROW_KEYS__                                       _______, _______, _______

// Raise
#define _________________RAISE_L1__________________       ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________       _________________FUNC_LEFT_________________
#define __________RAISE_L3_FOUR___________                RESET,   _______, _______, TO(_QWERTY)
#define _________________RAISE_L3__________________       __________RAISE_L3_FOUR___________, _______

#define _________________RAISE_R1__________________       ________________NUMBER_RIGHT_______________
#define __________RAISE_R2_FOUR___________                KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R2__________________       _______, __________RAISE_R2_FOUR___________
#define __RAISE_R3_TWO__                                  KC_GRV,  KC_BSLS
#define __________RAISE_R3_FOUR___________                __RAISE_R3_TWO__, _______, _______
#define _________________RAISE_R3__________________       __________RAISE_R3_FOUR___________, KC_BSLS
#define _________________RAISE_R3_ARROWS___________       __________RAISE_R3_FOUR___________, KC_BSLS
#define                __RAISE_R3_ARROW_KEYS__                                       _______, _______, _______

// Numbers
#define __________________NUM_L1___________________       _______, KC_7,    KC_8,    KC_9,    _______
#define __________________NUM_L2___________________       _______, KC_4,    KC_5,    KC_6,    _______
#define __________________NUM_L3___________________       _______, KC_1,    KC_2,    KC_3,    _______

#define __________________NUM_R1___________________       _______, _______, _______, _______, _______
#define __________________NUM_R2___________________       _______, _______, _______, _______, _______
#define __________________NUM_R3___________________       _______, _______, _______, _______, _______

// Media
#define _________________MEDIA_L1__________________       _______, _______, _______, _______, _______
#define _________________MEDIA_L2__________________       _______, _______, _______, S(KC_PSCR), G(S(KC_PSCR))
#define __________MEDIA_L3_FOUR___________                RESET,   _______, _______, TO(_QWERTY)
#define _________________MEDIA_L3__________________       __________MEDIA_L3_FOUR___________, _______

#define _________________MEDIA_R1__________________       RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
#define __________MEDIA_R2_FOUR___________                KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
#define _________________MEDIA_R2__________________       __________MEDIA_R2_FOUR___________, _______
#define __________MEDIA_R3_FOUR___________                _______, _______, _______, _______
#define _________________MEDIA_R3__________________       __________MEDIA_R3_FOUR___________, _______
#define _________________MEDIA_R3_ARROWS___________       __________MEDIA_R3_FOUR___________, KC_VOLU
#define                __MEDIA_R3_ARROW_KEYS__                                       KC_MNXT, KC_VOLD, KC_MPLY

// Mouse
#define _________________MOUSE_L1__________________       KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO
#define _________________MOUSE_L2__________________       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
#define __________MOUSE_L3_FOUR___________                RESET,   KC_BTN2, KC_BTN1, TO(_QWERTY)
#define _________________MOUSE_L3__________________       __________MOUSE_L3_FOUR___________, KC_NO

#define _________________MOUSE_R1__________________       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO
#define __________MOUSE_R2_FOUR___________                KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
#define _________________MOUSE_R2__________________       __________MOUSE_R2_FOUR___________, KC_NO
#define __________MOUSE_R3_FOUR___________                KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R
#define _________________MOUSE_R3__________________       __________MOUSE_R3_FOUR___________, KC_NO
#define _________________MOUSE_R3_ARROWS___________       KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_MS_U
#define                __MOUSE_R3_ARROW_KEYS__                                       KC_MS_L, KC_MS_D, KC_MS_R

#define ___________________BLANK___________________       _______, _______, _______, _______, _______
