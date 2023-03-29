/* Copyright 2021 qpockets
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
#include QMK_KEYBOARD_H

bool is_gui_tab_active = false; // ADD this near the begining of keymap.c
uint16_t gui_tab_timer = 0;     // we will be using them soon.
uint16_t gui_tab_delay = 1000;  // amount of time to keep mod "held"

bool scroll_pressed = false;

enum layers{
  _BASE,
  _SYM,
  _NAV,
  _NUM,
  _MOUSE
};

enum my_keycodes {
  PRVAPP = SAFE_RANGE,
  NXTAPP,
  MOUSESCROLL,
  KC_CPI1,
  KC_CPI2,
  KC_CPI3,
  KC_CPI4
};

#ifdef COMBO_ENABLE
    enum combo_events {
    combo_ESC,
    combo_BACK,
    combo_TAB,
    combo_DELETE,
    combo_LPRN,
    combo_RPRN,
    combo_MOUS3,
    };

    const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
    const uint16_t PROGMEM bspc_combo[] = {KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM tab_combo[] = {KC_W, KC_E, COMBO_END};
    const uint16_t PROGMEM del_combo[] = {KC_O, KC_P, COMBO_END};
    const uint16_t PROGMEM lprn_combo[] = {KC_Z, KC_X, COMBO_END};
    const uint16_t PROGMEM rprn_combo[] = {KC_X, KC_C, COMBO_END};
    const uint16_t PROGMEM mous3_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};

    combo_t key_combos[COMBO_COUNT] = {
    [combo_ESC] = COMBO(esc_combo, KC_ESC),
    [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
    [combo_TAB] = COMBO(tab_combo, KC_TAB),
    [combo_DELETE] = COMBO(del_combo, KC_DEL),
    [combo_LPRN] = COMBO(lprn_combo, KC_LPRN),
    [combo_RPRN] = COMBO(rprn_combo, KC_RPRN),
    [combo_MOUS3] = COMBO(mous3_combo, KC_BTN3),
    };
#endif

#define NUM LT(_NUM,KC_ENT)
#define NAV LT(_NAV,KC_SPC)
#define SYM LT(_SYM,KC_BSPC)
#define encSYM LT(_NUM,KC_MUTE)
#define MOUSE LT(_MOUSE,KC_ENT)
#define xxx KC_TRNS
#define CtlA LCTL_T(KC_A)
#define SftF LSFT_T(KC_F)
#define GuiD LGUI_T(KC_D)
#define AltS LALT_T(KC_S)
#define CtlComm RCTL_T(KC_QUOT)
#define SftJ RSFT_T(KC_J)
#define GuiK RGUI_T(KC_K)
#define AltL RALT_T(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_BTN2,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,
    CtlA,   AltS,   GuiD,   SftF,   KC_G,   KC_BTN1,  KC_H,   SftJ,   GuiK,    AltL,   CtlComm,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,             KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,
                encSYM, MOUSESCROLL, NAV,    SYM, NUM,   MOUSE
  ),

 [_SYM] = LAYOUT(
    C(G(KC_Q)),KC_F13,KC_EQL,KC_F5,KC_TILD,RESET,C(G(KC_SPC)),KC_UNDS,KC_EXLM,G(S(KC_A)),KC_PERC,
    KC_AT,KC_MINS,KC_DLR,KC_NO,KC_GRV,KC_GRV,KC_HASH,PRVAPP,NXTAPP,KC_PIPE,KC_SCLN,
    KC_LBRC,KC_ASTR,KC_COLN,KC_CIRC,KC_AMPR,KC_NLCK,KC_F15,C(KC_LEFT), C(KC_RGHT),KC_BSLS,
                  xxx,    KC_LBRC, KC_RBRC,        xxx,      xxx,    xxx
  ),

  [_NAV] = LAYOUT(
    KC_GESC,S(G(KC_LEFT)),S(KC_UP),S(G(KC_RIGHT)),S(G(KC_UP)), KC_BTN2, G(KC_UP),G(KC_LEFT),KC_UP,G(KC_RGHT),xxx,
    G(KC_A),S(A(KC_LEFT)),S(KC_DOWN),S(A(KC_RGHT)),S(G(KC_DOWN)), KC_BTN1, G(KC_DOWN),KC_LEFT,KC_DOWN,KC_RGHT,xxx,
    G(KC_Z),G(KC_X),G(KC_C),G(KC_V), xxx, xxx, xxx, G(A(KC_LEFT)), G(A(KC_RGHT)), xxx,
                     xxx,  xxx,  xxx,          KC_DEL, KC_CAPS, xxx
  ),

  [_NUM] = LAYOUT(
        xxx, KC_P7, KC_P8, KC_P9, KC_ASTR,xxx, xxx, KC_F7, KC_F8, KC_F9, KC_F12,
        xxx, KC_P4, KC_P5, KC_P6, KC_MINS,xxx, xxx, KC_F4, KC_F5, KC_F6, KC_F11,
        xxx, KC_P1, KC_P2, KC_P3, KC_PLUS, xxx, KC_F1, KC_F2, KC_F3, KC_F10,
        xxx, KC_DOT, KC_P0, xxx, xxx, xxx
  ),

  [_MOUSE] = LAYOUT(
        xxx,KC_WH_L,KC_MS_U,KC_WH_R, xxx,KC_BTN5, xxx, xxx, KC_WH_U, xxx, xxx,
        xxx,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_U,KC_BTN4, xxx, KC_WH_L, KC_WH_D, KC_WH_R, xxx,
        KC_CPI1,KC_CPI2,KC_CPI3,KC_CPI4,KC_WH_D, xxx, KC_ACL0, KC_ACL1, KC_ACL2, xxx,
        TG(_MOUSE), KC_BTN3,KC_BTN1,KC_BTN2, xxx, TG(_MOUSE)
  ),
};

#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0) { /* left encoder*/
            switch(get_highest_layer(layer_state)){
                case _SYM:
                    clockwise ? tap_code(KC_MNXT) : tap_code(KC_MPRV);
                    break;
                case _NUM:
                    clockwise ? tap_code16(S(A(KC_RGHT))) : tap_code16(S(A(KC_LEFT)));
                    break;
                default:
                    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
                    break;
        }
        } else if (index == 1) { /* right encoder */
            switch(get_highest_layer(layer_state)){
                case _NAV:
                    clockwise ? tap_code16(A(KC_RGHT)) : tap_code16(A(KC_LEFT));
                    break;
                case _MOUSE:
                    clockwise ? tap_code(KC_WH_R) : tap_code(KC_WH_L);
                    break;
                default:
                    clockwise ? tap_code(KC_WH_D) : tap_code(KC_WH_U);
                    break;
            }
        }
        return true;
    }
#endif

#ifdef RGBLIGHT_ENABLE
    // Light LEDs 1 & 2 in black when keyboard layer 1 is active
    const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 2, HSV_BLACK}
    );
    const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 2, HSV_GOLDENROD}
    );
    // Light LED  2 in purple when keyboard layer 2 is active
    const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 2, HSV_PURPLE}
    );
    // Light LED 1 in red when keyboard layer 3 is active
    const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 1, HSV_RED}
    );
    // Light LED  2 in orange when keyboard layer 4 is active
    const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 2, HSV_ORANGE}
    );
    // Light LED 2 in green when keyboard layer 5 is active
    const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {1, 2, HSV_GREEN}
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_capslock_layer,
        my_layer1_layer,    // Overrides caps lock layer
        my_layer2_layer,    // Overrides other layers
        my_layer3_layer,     // Overrides other layers
        my_layer4_layer,     // Overrides other layers
        my_layer5_layer     // Overrides other layers
    );

    void keyboard_post_init_user(void) {
        // Enable the LED layers
        rgblight_layers = my_rgb_layers;
    }

    bool led_update_user(led_t led_state) {
        rgblight_set_layer_state(1, !led_state.caps_lock);
        return true;
    }

    layer_state_t default_layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
        return state;
    }

    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(2, layer_state_cmp(state, _SYM));
        rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
        rgblight_set_layer_state(4, layer_state_cmp(state, _NUM));
        rgblight_set_layer_state(5, layer_state_cmp(state, _MOUSE));
        return state;
    }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOUSESCROLL:
        if (record->event.pressed) {
            scroll_pressed = true;
            layer_on(_MOUSE);
        } else {
            scroll_pressed = false;
            layer_off(_MOUSE);
        }
        return false;
    case NXTAPP:
        if (record->event.pressed) {
            if (!is_gui_tab_active) {
                is_gui_tab_active = true;
                register_code(KC_LGUI);
            }
            gui_tab_timer = timer_read();
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        return false; // Skip all further processing of this key
    case PRVAPP:
        if (record->event.pressed) {
            if (!is_gui_tab_active) {
                is_gui_tab_active = true;
                register_code(KC_LGUI);
            }
            gui_tab_timer = timer_read();
            register_code(KC_LSFT);
            register_code(KC_GRAVE);
        } else {
            unregister_code(KC_GRAVE);
            unregister_code(KC_LSFT);
        }
        return false; // Skip all further processing of this key
    case KC_CPI1:
        pointing_device_set_cpi(200);
        return false;
    case KC_CPI2:
        pointing_device_set_cpi(400);
        return false;
    case KC_CPI3:
        pointing_device_set_cpi(800);
        return false;
    case KC_CPI4:
        pointing_device_set_cpi(1600);
        return false;
    default:
        return true; // Process all other keycodes normally
  }
}

void matrix_scan_user(void) { // The very important timer.
  if (is_gui_tab_active) {
    if (timer_elapsed(gui_tab_timer) > 2000) {
      unregister_code(KC_LGUI);
      is_gui_tab_active = false;
    }
  }
}

