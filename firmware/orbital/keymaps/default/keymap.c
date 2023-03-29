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

enum layers{
  _BASE,
  _SYM,
  _NAV
};
	
enum combo_events {
 COMBO_BSPC,
 COMBO_ENT,
 COMBO_TAB,
 COMBO_ESC,
 COMBO_CAP,
 COMBO_DEL
};

#define DN_BSPC LT(_NAV, KC_BSPC)
#define UP_SPC LT(_SYM, KC_SPC)
// #define DN_DOT LT(_NAV, KC_DOT)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
//#define KC_GZ LGUI_T(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_DEL,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,
    KC_A,   KC_S,   KC_D,  KC_SF,   KC_G,   KC_LGUI,  KC_H,   KC_SJ,  KC_K,    KC_L,   KC_QUOT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,             KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,
                  KC_MPLY, KC_LCTL, DN_BSPC,    UP_SPC, KC_RALT,   TG(_NAV)
  ),

 [_SYM] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    RESET,  KC_6,     KC_7,     KC_8,    KC_9,     KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_GRV, KC_CIRC,  KC_AMPR,  KC_ASTR, KC_EQUAL, KC_MINS,
    KC_PIPE, KC_BSLS, KC_LPRN, KC_LBRC, KC_SCLN,         KC_COLN,  KC_RBRC,  KC_RPRN, KC_PLUS,  KC_UNDS,
                  KC_TRNS,    KC_TRNS,   KC_TRNS,        KC_TRNS,      KC_TRNS,    KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_CPI_1, KC_HOME, KC_UP,   KC_END,   KC_PGUP, KC_BTN2, KC_BTN3, KC_F1,   KC_F2,   KC_F3,   KC_F4,
    KC_CPI_2, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_BTN1, KC_BTN4, KC_F5,   KC_F6,   KC_F7,   KC_F8,
    KC_CPI_3, KC_BTN3, KC_BTN2, KC_BTN1,  KC_TRNS,          KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,
                     KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* left encoder*/
        switch(get_highest_layer(layer_state)){

			 case _SYM:
                if (clockwise) {
                tap_code16(C(KC_TAB));
                } else {
                tap_code16(C(S(KC_TAB)));
                }
                break;

            default:
                if (clockwise){
                    tap_code(KC_VOLU);
                } else{
                    tap_code(KC_VOLD);
                }
                break;
      }
    } else if (index == 1) { /* right encoder */
        switch(get_highest_layer(layer_state)){

            case _SYM:
                if (clockwise) {
                tap_code(KC_MNXT);
                } else {
                tap_code(KC_MPRV);
                }
                break;

            default:
                if (clockwise){
                    tap_code(KC_WH_D);
                } else{
                    tap_code(KC_WH_U);
                }
                break;
        }
    }
    return true;
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_cap[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_CAP] = COMBO(combo_cap,KC_CAPS),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL)
};
#endif

	
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_BLUE}   

);
// Light LEDs 1 & 2 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_CYAN}
);
// Light LED  2 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, HSV_PURPLE}
);
// Light LED 1 in red when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NAV));
    return state;
}
