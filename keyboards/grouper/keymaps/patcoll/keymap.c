#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT_southpaw(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _______, _______, _______, _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
  _______, _______, _______, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
  _______, _______, _______, _________________QWERTY_L3_________________, _________QWERTY_R3_FOUR________,
  _______, _______, _______, KC_LGUI, KC_LALT, SFT_SPC, SFT_SPC, RSE_ENT, KC_HYPR, KC_MEH
),

[_GAMING] = LAYOUT_wrapper(
  _______, _______, _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________,
  _______, _______, _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________,
  _______, _______, _______, _________________GAMING_L3_________________, _________GAMING_R3_FOUR________,
  _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  KC_ENT,  _______, _______
),

[_NAV] = LAYOUT_wrapper(
  _______, _______, _______, __________________NAV_L1___________________, __________________NAV_R1___________________,
  _______, _______, _______, __________________NAV_L2___________________, __________________NAV_R2___________________,
  _______, _______, _______, __________________NAV_L3___________________, _____________NAV_R3_FOUR__________,
  _______, _______, _______, _______, _______, ALT_TAB, ALT_TAB, _______, _______, _______
),

[_OSK] = LAYOUT_wrapper(
  _______, _______, _______, __________________OSK_L1___________________, __________________OSK_R1___________________,
  _______, _______, _______, __________________OSK_L2___________________, __________________OSK_R2___________________,
  _______, _______, _______, __________________OSK_L3___________________, _____________OSK_R3_FOUR__________,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _______, _______, _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________,
  _______, _______, _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________,
  _______, _______, _______, _________________RAISE_L3__________________, __________RAISE_R3_FOUR___________,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _______, _______, _______, _________________MEDIA_L1__________________, _________________MEDIA_R1__________________,
  _______, _______, _______, _________________MEDIA_L2__________________, _________________MEDIA_R2__________________,
  _______, _______, _______, _________________MEDIA_L3__________________, __________MEDIA_R3_FOUR___________,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _______, _______, _______, _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
  _______, _______, _______, _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
  _______, _______, _______, _________________MOUSE_L3__________________, __________MOUSE_R3_FOUR___________,
  _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, KC_BTN1, KC_BTN2, _______
),
};

/* #include QMK_KEYBOARD_H */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/*  */
/* [0] = LAYOUT( \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* ), */
/* [1] = LAYOUT( \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* ), */
/* [2] = LAYOUT( \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* ), */
/* [3] = LAYOUT( \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* ), */
/* [4] = LAYOUT( \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \ */
/*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS */
/* ) */
/*  */
/* }; */
/*  */
/* void keyboard_post_init_user(void) { */
/*   setPinOutput(LED0_PIN); */
/*   setPinOutput(LED1_PIN); */
/*   setPinOutput(LED2_PIN); */
/*  */
/*   writePin(LED0_PIN, 1); */
/* } */
/*  */
/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     switch (get_highest_layer(state)) { */
/*     case 1: */
/*         writePin(LED2_PIN, 1); */
/*         writePin(LED1_PIN, 0); */
/*         break; */
/*     case 2: */
/*         writePin(LED2_PIN, 0); */
/*         writePin(LED1_PIN, 1); */
/*         break; */
/*     case 3: */
/*         writePin(LED2_PIN, 1); */
/*         writePin(LED1_PIN, 1); */
/*         break; */
/*     default: //  for any other layers, or the default layer */
/*         writePin(LED2_PIN, 0); */
/*         writePin(LED1_PIN, 0); */
/*         break; */
/*     } */
/*   return state; */
/* } */
