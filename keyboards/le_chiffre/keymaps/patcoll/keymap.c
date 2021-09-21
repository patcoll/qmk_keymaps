#include QMK_KEYBOARD_H
#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  _________________QWERTY_L1_________________, _______, _________________QWERTY_R1_________________,
  _________________QWERTY_L2_________________,          _________________QWERTY_R2_________________,
  _________________QWERTY_L3_________________,          _________________QWERTY_R3_________________,
  KC_LCTL, SFT_SPC, RSE_ENT, KC_LALT
),

[_NAV] = LAYOUT_wrapper(
  __________________NAV_L1___________________, _______, __________________NAV_R1___________________,
  __________________NAV_L2___________________,          __________________NAV_R2___________________,
  __________________NAV_L3___________________,          __________________NAV_R3___________________,
  _______, _______, _______, _______
),

[_LOWER] = LAYOUT_wrapper(
  _________________LOWER_L1__________________, _______, _________________LOWER_R1__________________,
  _________________LOWER_L2__________________,          _________________LOWER_R2__________________,
  _________________LOWER_L3__________________,          _________________LOWER_R3__________________,
  _______, _______, _______, _______
),

[_RAISE] = LAYOUT_wrapper(
  _________________RAISE_L1__________________, _______, _________________RAISE_R1__________________,
  _________________RAISE_L2__________________,          _________________RAISE_R2__________________,
  _________________RAISE_L3__________________,          _________________RAISE_R3__________________,
  _______, _______, _______, _______
),

[_MEDIA] = LAYOUT_wrapper(
  _________________MEDIA_L1__________________, _______, _________________MEDIA_R1__________________,
  _________________MEDIA_L2__________________,          _________________MEDIA_R2__________________,
  _________________MEDIA_L3__________________,          _________________MEDIA_R3__________________,
  _______, _______, _______, _______
),

[_MOUSE] = LAYOUT_wrapper(
  _________________MOUSE_L1__________________, _______, _________________MOUSE_R1__________________,
  _________________MOUSE_L2__________________,          _________________MOUSE_R2__________________,
  _________________MOUSE_L3__________________,          _________________MOUSE_R3__________________,
  KC_NO,   KC_BTN1, KC_BTN1, KC_BTN2
),
};

/* #define HOME 0 */
/* #define MODS 1 */
/* #define MODS2 2 */
/* #define OTHER 3 */
/* #define NAV 4 */
/*  */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* 	[HOME] = LAYOUT( */
/* 		LCTL_T(KC_Q), LT(1, KC_W), KC_E, KC_R, KC_T, KC_MPLY, KC_Y, KC_U, KC_I, KC_O, KC_P, */
/* 		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TO(1), */
/* 		LT(1, KC_Z), LT(2, KC_X), KC_C, LCTL_T(KC_V), KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LALT_T(KC_SLSH), */
/*     KC_LCTL, MT(MOD_LSFT, KC_SPC), MT(MOD_LSFT, KC_ENT), KC_LCTL */
/*   ), */
/*  */
/* 	[MODS] = LAYOUT( */
/* 		LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, */
/* 		LSFT_T(KC_BSPC), KC_ESC, KC_TAB, KC_SCLN, KC_QUOT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TO(2), */
/* 		KC_LCTL, KC_LGUI, KC_LALT, TO(0), KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_LALT, */
/*     KC_LCTL, MT(MOD_LSFT, KC_SPC), MT(MOD_LSFT, KC_ENT), KC_LCTL */
/*   ), */
/*  */
/* 	[MODS2] = LAYOUT( */
/* 		LCTL_T(KC_F1), KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, */
/* 		KC_LSFT, KC_F11, KC_F12, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, TO(3), */
/* 		RGB_VAI, RGB_VAD, RGB_HUI, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, */
/*     KC_LCTL, MT(MOD_LSFT, KC_SPC), MT(MOD_LSFT, KC_ENT), KC_LCTL */
/*   ), */
/*  */
/* 	[OTHER] = LAYOUT( */
/* 		KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, */
/* 		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, */
/* 		RESET, KC_NO, KC_NO, TO(0), KC_MPLY, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_LALT, */
/*     KC_NO, KC_BTN1, KC_BTN1, KC_NO */
/*   ), */
/* }; */
/*  */
/* bool encoder_update_user(uint8_t index, bool clockwise) { */
/*     if (index == 0) { */
/*         if (clockwise) { */
/*             tap_code(KC_VOLU); */
/*         } else { */
/*             tap_code(KC_VOLD); */
/*         } */
/*     } */
/*     return true; */
/* } */
/*  */
/* #ifdef COMBO_ENABLE */
/* enum combos { */
/*   #<{(| FJ_ZER, |)}># */
/*   #<{(| SCDN_ZER, |)}># */
/*  */
/*   OP_COMBO, */
/*  */
/*   QW_COMBO, */
/*   AS_COMBO, */
/*  */
/*   #<{(| YU_COMBO |)}># */
/*   #<{(| SS_COMBO |)}># */
/*  */
/*   DF_COMBO, */
/*  */
/*   FG_COMBO, */
/*  */
/*   GH_COMBO, */
/*  */
/*   #<{(| UI_COMBO, |)}># */
/*   #<{(| SE_COMBO, |)}># */
/*   #<{(| FSE_COMBO, |)}># */
/*   #<{(| MWDU_COMBO, |)}># */
/*  */
/*   JK_COMBO, */
/*   DU_COMBO, */
/*   RBBS_COMBO, */
/*   MUMD_COMBO, */
/*  */
/*   HJ_COMBO, */
/*   LD_COMBO, */
/*   BR_COMBO, */
/*   MLD_COMBO, */
/*  */
/*   JI_COMBO, */
/*   DE_COMBO, */
/*   RBF8_COMBO, */
/*   MDWU_COMBO, */
/*  */
/*   BK_COMBO, */
/*   CU_COMBO, */
/*   CB_COMBO, */
/*   MPU_COMBO, */
/*  */
/*   MK_COMBO, */
/*   UL_COMBO, */
/*  */
/*   #<{(| JKL_COMBO, |)}># */
/*   KL_COMBO, */
/*  */
/*   SB_COMBO, */
/*   BN_COMBO, */
/*   CD_COMBO, */
/*  */
/*   #<{(| BNM_COMBO, |)}># */
/*  */
/*   NM_COMBO, */
/*   DS_COMBO, */
/*  */
/*   BM_COMBO, */
/*   CS_COMBO */
/* }; */
/*  */
/* #<{(| const uint16_t PROGMEM fj_zero[] = {KC_F, KC_J, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM scdn_zero[] = {KC_SCLN, KC_DOWN, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END}; */
/* const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM ss_combo[] = {KC_6, KC_7, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM se_combo[] = {KC_7, KC_8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM fse_combo[] = {KC_F7, KC_F8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM mwdu_combo[] = {KC_WH_D, KC_WH_U, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP, COMBO_END}; */
/* const uint16_t PROGMEM rbbs_combo[] = {KC_RBRC, KC_BSLS, COMBO_END}; */
/* const uint16_t PROGMEM mumd_combo[] = {KC_MS_U, KC_MS_D, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM ld_combo[] = {KC_LEFT, KC_DOWN, COMBO_END}; */
/* const uint16_t PROGMEM br_combo[] = {KC_LBRC, KC_RBRC, COMBO_END}; */
/* const uint16_t PROGMEM mld_combo[] = {KC_MS_L, KC_MS_D, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END}; */
/* const uint16_t PROGMEM de_combo[] = {KC_DOWN, KC_8, COMBO_END}; */
/* const uint16_t PROGMEM rbf8_combo[] = {KC_RBRC, KC_F8, COMBO_END}; */
/* const uint16_t PROGMEM mdwu_combo[] = {KC_MS_D, KC_WH_U, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM bk_combo[] = {KC_B, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM cu_combo[] = {KC_COMM, KC_UP, COMBO_END}; */
/* const uint16_t PROGMEM cb_combo[] = {KC_COMM, KC_BSLS, COMBO_END}; */
/* const uint16_t PROGMEM mpu_combo[] = {KC_MPLY, KC_MS_U, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM mk_combo[] = {KC_M, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM ul_combo[] = {KC_UP, KC_LBRC, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END}; |)}># */
/* const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM sb_combo[] = {KC_SPC, KC_B, COMBO_END}; |)}># */
/* const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END}; */
/* const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM bnm_combo[] = {KC_B, KC_N, KC_M, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END}; */
/* const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END}; */
/* const uint16_t PROGMEM cs_combo[] = {KC_COMM, KC_SLSH, COMBO_END}; */
/*  */
/* combo_t key_combos[COMBO_COUNT] = { */
/*   [OP_COMBO] = COMBO(op_combo, KC_BSPC), */
/*  */
/*   [QW_COMBO] = COMBO(qw_combo, KC_TAB), */
/*  */
/*   [AS_COMBO] = COMBO(as_combo, KC_TAB), */
/*  */
/*   #<{(| [YU_COMBO] = COMBO(yu_combo, KC_ESC), |)}># */
/*   #<{(| [SS_COMBO] = COMBO(ss_combo, KC_ESC), |)}># */
/*  */
/*   [DF_COMBO] = COMBO(df_combo, KC_SCLN), */
/*  */
/*   [FG_COMBO] = COMBO(fg_combo, KC_MINS), */
/*  */
/*   [GH_COMBO] = COMBO(gh_combo, KC_EQL), */
/*  */
/*   #<{(| [UI_COMBO] = COMBO(ui_combo, KC_ESC), |)}># */
/*   #<{(| [SE_COMBO] = COMBO(se_combo, KC_ESC), |)}># */
/*   #<{(| [FSE_COMBO] = COMBO(fse_combo, KC_ESC), |)}># */
/*   #<{(| [MWDU_COMBO] = COMBO(mwdu_combo, KC_ESC), |)}># */
/*  */
/*   [JK_COMBO] = COMBO(jk_combo, KC_ESC), */
/*   [DU_COMBO] = COMBO(du_combo, KC_ESC), */
/*   [RBBS_COMBO] = COMBO(rbbs_combo, KC_ESC), */
/*   [MUMD_COMBO] = COMBO(mumd_combo, KC_ESC), */
/*  */
/*   [HJ_COMBO] = COMBO(hj_combo, KC_ENT), */
/*   [LD_COMBO] = COMBO(ld_combo, KC_ENT), */
/*   [BR_COMBO] = COMBO(br_combo, KC_ENT), */
/*   [MLD_COMBO] = COMBO(mld_combo, KC_ENT), */
/*  */
/*   [JI_COMBO] = COMBO(ji_combo, KC_ENT), */
/*   [DE_COMBO] = COMBO(de_combo, KC_ENT), */
/*   [RBF8_COMBO] = COMBO(rbf8_combo, KC_ENT), */
/*   [MDWU_COMBO] = COMBO(mdwu_combo, KC_ENT), */
/*  */
/*   [BK_COMBO] = COMBO(bk_combo, KC_ENT), */
/*   [CU_COMBO] = COMBO(cu_combo, KC_ENT), */
/*   [CB_COMBO] = COMBO(cb_combo, KC_ENT), */
/*   [MPU_COMBO] = COMBO(mpu_combo, KC_ENT), */
/*  */
/*   [MK_COMBO] = COMBO(mk_combo, KC_ENT), */
/*   [UL_COMBO] = COMBO(ul_combo, KC_ENT), */
/*  */
/*   #<{(| [JKL_COMBO] = COMBO(jkl_combo, KC_SCLN), |)}># */
/*   [KL_COMBO] = COMBO(kl_combo, KC_QUOT), */
/*  */
/*   [BN_COMBO] = COMBO(bn_combo, KC_COMM), */
/*   [CD_COMBO] = COMBO(cd_combo, KC_COMM), */
/*  */
/*   [NM_COMBO] = COMBO(nm_combo, KC_DOT), */
/*   [DS_COMBO] = COMBO(ds_combo, KC_DOT), */
/*  */
/*   [BM_COMBO] = COMBO(bm_combo, KC_SLSH), */
/*   [CS_COMBO] = COMBO(cs_combo, KC_SLSH) */
/* }; */
/* #endif // COMBO_ENABLE */
/*  */
/* // copied from alpha keymap. */
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     // Shift */
/*     case MT(MOD_LSFT, KC_SPC): */
/*     case MT(MOD_LSFT, KC_ENT): */
/*     case MT(MOD_LSFT, KC_Z): */
/*     case MT(MOD_LSFT, KC_SLSH): */
/*       return TAPPING_TERM - 25; */
/*     default: */
/*       return TAPPING_TERM; */
/*   } */
/* } */
/*  */
/* // copied from alpha keymap. */
/* #<{(| bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { |)}># */
/* #<{(|   switch (keycode) { |)}># */
/* #<{(|     // Shift |)}># */
/* #<{(|     case MT(MOD_LSFT, KC_SPC): |)}># */
/* #<{(|     case MT(MOD_LSFT, KC_ENT): |)}># */
/* #<{(|       return true; |)}># */
/* #<{(|     default: |)}># */
/* #<{(|       return false; |)}># */
/* #<{(|   } |)}># */
/* #<{(| } |)}># */
/*  */
/* #ifdef OLED_DRIVER_ENABLE  //Special thanks to Sickbabies for this great OLED widget! */
/* oled_rotation_t oled_init_user(oled_rotation_t rotation) { */
/*     return OLED_ROTATION_90;  // rotates for proper orientation */
/* } */
/*  */
/* void render_lechiffre_logo(void) { */
/*     static const char PROGMEM lechiffre_logo[] = { */
/* 	// 'lechiffre_logo', 32x20px */
/*    0x00, 0x3e, 0x20, 0x20, 0x00, 0x18, 0x2c, 0xa8, 0x80, 0x00, 0x1c, 0x22, 0x22, 0x00, 0x3e, 0x08, */
/* 0x30, 0x00, 0x34, 0x00, 0x3c, 0x0a, 0x00, 0xbc, 0x8a, 0x00, 0x38, 0x08, 0x00, 0x18, 0x2c, 0x28, */
/* 0x00, 0xb6, 0xb6, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, */
/* 0x00, 0xdb, 0xdb, 0x00, 0xdb, 0xdb, 0x00, 0x6d, 0x6d, 0x00, 0xdb, 0xdb, 0x00, 0xb6, 0xb6, 0x00, */
/* 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, */
/* 0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x00, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00 */
/* }; */
/*  */
/*   oled_write_raw_P(lechiffre_logo, sizeof(lechiffre_logo)); */
/* } */
/*  */
/* static void render_layer_status(void) { */
/*     oled_write_P(PSTR("-----"), false); */
/*     switch (get_highest_layer(layer_state)) { */
/*         case _BASE: */
/*             oled_write_ln_P(PSTR("BASE"), false); */
/*             break; */
/*         case _NUM_SYM: */
/*             oled_write_ln_P(PSTR(" SYM"), false); */
/*             break; */
/*         case _NAV: */
/*             oled_write_ln_P(PSTR(" NAV"), false); */
/*             break; */
/*         default: */
/*             oled_write_ln_P(PSTR("?????"), false); */
/*     } */
/* } */
/*  */
/* #    define KEYLOG_LEN 11 */
/* char     keylog_str[KEYLOG_LEN] = {}; */
/* uint8_t  keylogs_str_idx        = 0; */
/* uint16_t log_timer              = 0; */
/*  */
/* const char code_to_name[60] = { */
/*     ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', */
/*     'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', */
/*     'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', */
/*     '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', */
/*     'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', */
/*     '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '}; */
/*  */
/* void add_keylog(uint16_t keycode) { */
/*     if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { */
/*         keycode = keycode & 0xFF; */
/*     } */
/*  */
/*     for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) { */
/*         keylog_str[i] = keylog_str[i - 1]; */
/*     } */
/*     if (keycode < 60) { */
/*         keylog_str[0] = code_to_name[keycode]; */
/*     } */
/*     keylog_str[KEYLOG_LEN - 1] = 0; */
/*  */
/*     log_timer = timer_read(); */
/* } */
/*  */
/* void update_log(void) { */
/*     if (timer_elapsed(log_timer) > 750) { */
/*         add_keylog(0); */
/*     } */
/* } */
/*  */
/* //Text only renders */
/* void render_keylogger_status(void) { */
/*     oled_write_P(PSTR("-----"), false); */
/*     oled_write(keylog_str, false); */
/* } */
/*  */
/* void render_keylock_status(led_t led_state) { */
/*     oled_write_P(PSTR("-----"), false); */
/*     oled_write_P(PSTR("C"), led_state.caps_lock); */
/* 	oled_write_P(PSTR(" "), false); */
/*     oled_write_P(PSTR("N"), led_state.num_lock); */
/* 	oled_write_P(PSTR(" "), false); */
/*     oled_write_P(PSTR("S"), led_state.scroll_lock); */
/*     //oled_write_ln_P(PSTR(" "), false); */
/* } */
/*  */
/* void render_mod_status(uint8_t modifiers) { */
/*        oled_write_P(PSTR("-----"), false); */
/*     oled_write_ln_P(PSTR("SHFT"), (modifiers & MOD_MASK_SHIFT)); */
/*     oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT)); */
/*     oled_write_ln_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL)); */
/*     oled_write_ln_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI)); */
/* } */
/*  */
/* void oled_task_user(void) { */
/*     render_lechiffre_logo(); */
/*     oled_set_cursor(0,3); */
/*     render_layer_status();	// Renders the current keyboard state (layer, lock, caps, scroll, etc) */
/* 	render_mod_status(get_mods()|get_oneshot_mods()); */
/* 	render_keylock_status(host_keyboard_led_state()); */
/* 	render_keylogger_status(); */
/* } */
/*  */
/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     if (record->event.pressed) { */
/*       add_keylog(keycode); */
/*     } */
/*     return true; */
/*   } */
/* #endif */
