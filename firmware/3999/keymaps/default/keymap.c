#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_SYM,
  _FN
};

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
};


#define KC_SZ LSFT_T(KC_Z)
#define KC_SL RSFT_T(KC_SLASH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,             KC_Y,             KC_U,           KC_I,    KC_O,    KC_P,      KC_DEL,
    KC_A,     KC_S,     KC_D,    KC_F,    KC_G,             KC_H,             LT(2, KC_J),    KC_K,    KC_L,    KC_ENTER,  KC_PGUP,
    KC_SZ,    KC_X,     KC_C,    KC_V,    KC_B,             KC_N,             KC_M,           KC_NO,   KC_SL,   KC_UP,     KC_PGDN,
    KC_LCTL,  KC_LGUI,  KC_LALT, KC_BSPC, LT(1, KC_SPACE),  LT(1, KC_SPACE),  KC_NO,          KC_NO,   KC_LEFT, KC_DOWN,   KC_RIGHT     
  ),

  [_NUM_SYM] = LAYOUT(
    KC_1,     KC_2,     KC_3,      KC_4,      KC_5,     KC_6,     KC_7,     KC_8,      KC_9,     KC_0,     KC_HOME,
    KC_MINS,  KC_EQL,   KC_LBRC,   KC_RBRC,   KC_BSLS,  KC_SCLN,  KC_QUOT,  KC_GRV,    KC_COMM, KC_DOT,   KC_END,
    RGB_TOG,  RGB_MOD,  RGB_RMOD,  RGB_HUI,   RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,   RGB_VAD,  KC_NO,    KC_NO, 
    KC_CAPS,  KC_NO,    KC_NO,     KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO
  ),

  [_FN] = LAYOUT(
    KC_F1,  KC_F2, KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_NO,  KC_NO, KC_UP,  KC_NO,  RESET,
    KC_F7,  KC_F8, KC_F9,  KC_F10, KC_F11, KC_F12, KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, 
    KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO 
  ),
};

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

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),

}; 


#    define KEYLOG_LEN 11
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      add_keylog(keycode);
    }
    return true;
  }
#endif
