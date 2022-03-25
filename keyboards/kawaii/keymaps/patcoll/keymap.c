#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________, _________QWERTY_R2_FOUR________,
  _________________QWERTY_L3_________________, _________QWERTY_R3_FOUR________,
  _______, KC_LGUI, KC_LALT, SFT_SPC,          RSE_ENT, KC_LCTL, KC_HYPR, _______
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, __________________NAV_R1___________________,
  __________________NAV_L2___________________, _____________NAV_R2_FOUR__________,
  __________________NAV_L3___________________, _____________NAV_R3_FOUR__________,
  _______, _______, _______, ALT_TAB,          ALT_TAB, _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  __________________OSK_L1___________________, __________________OSK_R1___________________,
  __________________OSK_L2___________________, _____________OSK_R2_FOUR__________,
  __________________OSK_L3___________________, _____________OSK_R3_FOUR__________,
  _______, _______, _______, _______,          _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________, __________LOWER_R2_FOUR___________,
  _________________LOWER_L3__________________, __________LOWER_R3_FOUR___________,
  _______, _______, _______, _______,          _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________, __________RAISE_R2_FOUR___________,
  _________________RAISE_L3__________________, __________RAISE_R3_FOUR___________,
  _______, _______, _______, _______,          _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________, __________MEDIA_R2_FOUR___________,
  _________________MEDIA_L3__________________, __________MEDIA_R3_FOUR___________,
  _______, _______, _______, _______,          _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________, __________MOUSE_R2_FOUR___________,
  _________________MOUSE_L3__________________, __________MOUSE_R3_FOUR___________,
  _______, _______, _______, KC_BTN1,          KC_BTN1, KC_BTN2, _______, _______
),

[_BLANK1] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),

[_BLANK2] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),

[_BLANK3] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),

[_BLANK4] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),

[_BLANK5] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ ),

[_BLANK6] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______,\
      _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______,          _______, _______, _______, _______ )

};

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*     #<{(| Base |)}># */
/*     [_DEFAULT] = LAYOUT( */
/*       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \ */
/*       KC_ACT,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    \ */
/*       KC_ZSFT, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOSF, \ */
/*       KC_ESCT, KC_LGUI, KC_MHAL, KC_SPLO,          KC_RA,   KC_HNCT, KC_BSPC, KC_ENAL ), */
/*     [_RAISE] = LAYOUT( */
/*       KC_DEL,  KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_MENU, KC_HOME, KC_UP,   KC_END,  KC_BSPC, \ */
/*       KC_F5,   KC_F6,   KC_F7,   KC_F8,   A(KC_ENT),A(KC_UP), KC_LEFT, KC_RGHT, KC_ENT, \ */
/*       KC_F9SF, KC_F10,  KC_F11,  KC_F12,  KC_FWD,  KC_BCK,  KC_DOWN, KC_PGUP, KC_PGDN, \ */
/*       _______, _______, _______, KC_ENT,           _______, _______, _______, _______ ), */
/*     [_LOWER] = LAYOUT( */
/*       S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), KC_BSPC, \ */
/*       KC_LSFT, KC_NM  , JP_PLUS, JP_ASTR, JP_AT,   KC_RO,   JP_MINS, JP_SCLN, JP_COLN, \ */
/*       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, JP_YEN,  JP_CIRC, KC_SLSH, JP_LBRC, JP_RBRC, \ */
/*       _______, _______, _______, KC_TAB,          KC_TAB,  _______, _______, _______ ), */
/*     [_NUMBER] = LAYOUT( */
/*       KC_1   , KC_2   , KC_3   , KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_BSPC, \ */
/*       KC_LCTL, XXXXXXX, JP_PLUS, JP_ASTR, JP_MINS, JP_UNDS, KC_4,    KC_5,    KC_6, \ */
/*       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_1,    KC_2,    KC_3, \ */
/*       _______, _______, _______, _______,          KC_0,    KC_0,    KC_DOT,  _______ ), */
/*     [_CLIPSTUDIO] = LAYOUT( */
/*       KC_ESC,     KC_W,         KC_E,       KC_R,        KC_T,    LCTL(KC_Y), LCTL(KC_R), LCTL(KC_0), KC_O, KC_P, \ */
/*       KC_ACT,     LCTL(KC_S),   LCTL(KC_D), LCTL(KC_E),  KC_G,    KC_H,       LCTL(KC_J), KC_K,       KC_L, \ */
/*       LCTL(KC_Z), KC_X,         LCTL(KC_C), LCTL(KC_V),  KC_B,    LCTL(KC_T), KC_M,       KC_LBRC,    KC_RBRC, \ */
/*       _______,    LCTL(KC_LALT), KC_LALT,     KC_SPC,      KC_LSFT, KC_ENT,     KC_LCTL,    LCTL(KC_LSFT) ), */
/*     [5] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______,\ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______,          _______, _______, _______, _______ ), */
/*     [6] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______,\ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______,          _______, _______, _______, _______ ), */
/*     [7] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______,\ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______,          _______, _______, _______, _______ ), */
/*     [8] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______,          _______, _______, _______, _______ ), */
/*     [9] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______,          _______, _______, _______, _______ ), */
/*     [10] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______,          _______, _______, _______, _______ ), */
/*     [11] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*       _______, _______, _______, _______,          _______, _______, _______, _______ ) */
/* }; */
