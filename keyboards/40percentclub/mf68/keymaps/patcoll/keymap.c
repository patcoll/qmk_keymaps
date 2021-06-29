#include QMK_KEYBOARD_H

#define CTL_ESC RCTL_T(KC_ESC)
#define TAB_FN LT(1,KC_TAB)
#define SPC_FN LT(1,KC_SPC)
#define SPC_MET LALT_T(KC_SPC)
#define BSLS_FN LT(1,KC_BSLS)
#define ESC_FN LT(2,KC_ESC)
#define GRV_FN LT(2,KC_GRV)
#define Q_FN LT(2,KC_Q)
#define BR_BACK LALT(KC_LBRC)
#define BR_FWD LALT(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
	[0] = LAYOUT_68_ansi(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, KC_PGUP,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END, KC_PGDN,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(1), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	[1] = LAYOUT_68_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_VOLU, KC_HOME,
        _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, BL_STEP, _______, KC_VOLD, KC_END,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MUTE, _______, _______, _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),
	[2] = LAYOUT_68_ansi(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC, KC_VOLU, KC_HOME,
        _______, _______, _______, KC_UP, _______, _______, _______, KC_7, KC_8, KC_9, _______, _______, _______, _______, KC_VOLD, KC_END,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_4, KC_5, KC_6, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_0, KC_1, KC_2, KC_3, _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    )
    */





  [0] = LAYOUT_68_ansi(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MPLY, KC_PGUP,
    TAB_FN,  Q_FN,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, BSLS_FN,          KC_DEL,  KC_PGDN,
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,          KC_UP,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_LALT, KC_LGUI,   KC_LCTL,          KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [1] = LAYOUT_68_ansi(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, KC_VOLU,
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, BR_BACK, BR_FWD,  KC_PSCR,          _______, KC_VOLD,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,                   _______,          KC_MUTE,
    _______, _______, _______,                            _______,                            _______, _______, _______,          KC_MPRV, KC_MPLY, KC_MNXT
  ),
  [2] = LAYOUT_68_ansi(
    _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU,
    _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLD,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,                   KC_BTN1,          KC_MS_U,
    _______, _______, _______,                            KC_BTN1,                            _______, _______, KC_BTN1,          KC_MS_L, KC_MS_D, KC_MS_R
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case SFT_T(KC_SPC): */
        /*     return TAPPING_TERM + 1250; */
        /* case LT(1, KC_GRV): */
        /*     return 130; */
        case SPC_MET:
            /* return 130; */
            return TAPPING_TERM + 1250;
        default:
            return TAPPING_TERM;
    }
}
