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
            return TAPPING_TERM - 72;
        case LSFT_T(KC_J):
            return TAPPING_TERM - 67;
        case LSFT_T(KC_ENT):
            return TAPPING_TERM - 70;

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
  KC_GRV,           KC_1,             KC_2,             KC_3,             KC_4,             KC_5,                                                 KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_BSPC,
  KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,                                                 KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_BSPC,
  LCTL_T(KC_ESC),   LGUI_T(KC_A),     LALT_T(KC_S),     LCTL_T(KC_D),     LSFT_T(KC_F),     KC_G,                                         KC_H,     LSFT_T(KC_J),     LCTL_T(KC_K),     LALT_T(KC_L),     LGUI_T(KC_SCLN),  KC_QUOT,
  KC_LSFT,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,     KC_LBRC,          KC_RBRC,          KC_N,     KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          LSFT_T(KC_ENT),
                                                        X_NU,             LT(MEDR, KC_ESC), LT(NAVR, KC_SPC), LT(MOUR, KC_SPC), LT(NSSL, KC_ENT), LT(NSL, KC_BSPC), LT(FUNL, KC_DEL), X_NU
),

[NAVR] = LAYOUT(
  RESET,            _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______,
  _______,          RESET,            X_NA,             X_NA,             X_NA,             X_NA,                                                 KC_AGIN,          KC_UNDO,          KC_CUT,           KC_COPY,          KC_PSTE,          _______,
  _______,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          X_NA,                                                 KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_CAPS,          _______,
  _______,          X_NA,             X_NA,             X_NA,             X_NA,             X_NA,             _______,          _______,          KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           KC_INS,           _______,
                                                        X_NU,             X_NA,             X_NA,             X_NA,             KC_ENT,           KC_BSPC,          KC_DEL,           X_NU
),

[MOUR] = LAYOUT(
  RESET,            _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______,
  _______,          RESET,            X_NA,             X_NA,             X_NA,             X_NA,                                                 X_NU,             X_NU,             X_NU,             X_NU,             X_NU,             _______,
  _______,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          X_NA,                                                 KC_MS_L,          KC_MS_D,          KC_MS_U,          KC_MS_R,          X_NU,             _______,
  _______,          X_NA,             X_NA,             X_NA,             X_NA,             X_NA,             _______,          _______,          KC_WH_L,          KC_WH_D,          KC_WH_U,          KC_WH_R,          X_NU,             _______,
                                                        X_NU,             X_NA,             X_NA,             X_NA,             KC_BTN1,          KC_BTN3,          KC_BTN2,          X_NU
),

[MEDR] = LAYOUT(
  RESET,            _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______,
  _______,          RESET,            X_NA,             X_NA,             X_NA,             X_NA,                                                 RGB_TOG,          RGB_MOD,          RGB_HUI,          RGB_SAI,          RGB_VAI,          _______,
  _______,          KC_LGUI,          KC_LALT,          KC_LCTL,          KC_LSFT,          X_NA,                                                 KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT,          X_NU,             _______,
  _______,          X_NA,             X_NA,             X_NA,             X_NA,             X_NA,             _______,          _______,          X_NU,             X_NU,             X_NU,             X_NU,             X_NU,             _______,
                                                        X_NU,             X_NA,             X_NA,             X_NA,             KC_MSTP,          KC_MPLY,          KC_MUTE,          X_NU
),

/* [MBO] = LAYOUT( */
/*   _______,          _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______, */
/*   _______,          _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______, */
/*   _______,          _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          _______, */
/*   _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______, */
/*                                                         _______,          _______,          _______,          _______,          KC_BTN1,          KC_BTN3,          KC_BTN2,          _______ */
/* ), */

[FUNL] = LAYOUT(
  RESET,            _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          RESET,
  _______,          KC_F12,           KC_F7,            KC_F8,            KC_F9,            KC_PSCR,                                              _______,          _______,          _______,          _______,          RESET,            _______,
  _______,          KC_F11,           KC_F4,            KC_F5,            KC_F6,            KC_SLCK,                                              _______,          KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          _______,
  _______,          KC_F10,           KC_F1,            KC_F2,            KC_F3,            KC_PAUS,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
                                                        _______,          KC_APP,           KC_SPC,           KC_TAB,           _______,          _______,          _______,          _______
),

[NSL] = LAYOUT(
  RESET,            _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          RESET,
  _______,          KC_LBRC,          KC_7,             KC_8,             KC_9,             KC_RBRC,                                              _______,          _______,          _______,          _______,          RESET,            _______,
  _______,          KC_QUOT,          KC_4,             KC_5,             KC_6,             KC_EQL,                                               _______,          KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          _______,
  _______,          KC_GRV,           KC_1,             KC_2,             KC_3,             KC_BSLS,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
                                                        _______,          KC_DOT,           KC_0,             KC_MINS,          _______,          _______,          _______,          _______
),

[NSSL] = LAYOUT(
  RESET,            _______,          _______,          _______,          _______,          _______,                                              _______,          _______,          _______,          _______,          _______,          RESET,
  _______,          KC_LCBR,          KC_AMPR,          KC_ASTR,          KC_LPRN,          KC_RCBR,                                              _______,          _______,          _______,          _______,          RESET,            _______,
  _______,          KC_DQUO,          KC_DLR,           KC_PERC,          KC_CIRC,          KC_PLUS,                                              _______,          KC_LSFT,          KC_LCTL,          KC_LALT,          KC_LGUI,          _______,
  _______,          KC_TILD,          KC_EXLM,          KC_AT,            KC_HASH,          KC_PIPE,          _______,          _______,          _______,          _______,          _______,          _______,          _______,          _______,
                                                        _______,          KC_LPRN,          KC_RPRN,          KC_UNDS,          _______,          _______,          _______,          _______
),
};

/* //SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk */
/* #ifdef OLED_DRIVER_ENABLE */
/*  */
/* oled_rotation_t oled_init_user(oled_rotation_t rotation) { */
/*   if (!is_keyboard_master()) */
/*     return OLED_ROTATION_180;  // flips the display 180 degrees if offhand */
/*   return rotation; */
/* } */
/*  */
/* // When you add source files to SRC in rules.mk, you can use functions. */
/* const char *read_layer_state(void); */
/* const char *read_logo(void); */
/* void set_keylog(uint16_t keycode, keyrecord_t *record); */
/* const char *read_keylog(void); */
/* const char *read_keylogs(void); */
/*  */
/* // const char *read_mode_icon(bool swap); */
/* // const char *read_host_led_state(void); */
/* // void set_timelog(void); */
/* // const char *read_timelog(void); */
/*  */
/* void oled_task_user(void) { */
/*   if (is_keyboard_master()) { */
/*     // If you want to change the display of OLED, you need to change here */
/*     oled_write_ln(read_layer_state(), false); */
/*     oled_write_ln(read_keylog(), false); */
/*     oled_write_ln(read_keylogs(), false); */
/*     //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false); */
/*     //oled_write_ln(read_host_led_state(), false); */
/*     //oled_write_ln(read_timelog(), false); */
/*   } else { */
/*     oled_write(read_logo(), false); */
/*   } */
/* } */
/* #endif // OLED_DRIVER_ENABLE */
/*  */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   if (record->event.pressed) { */
/* #ifdef OLED_DRIVER_ENABLE */
/*     set_keylog(keycode, record); */
/* #endif */
/*     // set_timelog(); */
/*   } */
/*   return true; */
/* } */
