#include QMK_KEYBOARD_H

#define HOME 0
#define MODS 1
#define MODS2 2
#define OTHER 3

enum custom_keycodes {
	MACRO1 = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			case MACRO1:
				SEND_STRING("I'm so sorry... -PyroL");
				return false;
		}
	}
	return true;
};

#ifdef COMBO_ENABLE
enum combos {
  /* FJ_ZER, */
  /* SCDN_ZER, */

  OP_BSPC,

  ZX_TAB,

  JK_ESC,
  DU_ESC,
  RBBS_ESC,
  MUMD_ESC,

  JKL_SCLN,
  KL_QUOT,

  SB_ENT,
  BN_ENT,
  CD_ENT,
  DS_ENT
};

/* const uint16_t PROGMEM fj_zero[] = {KC_F, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM scdn_zero[] = {KC_SCLN, KC_DOWN, COMBO_END}; */

const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM rbbs_combo[] = {KC_RBRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM mumd_combo[] = {KC_MS_U, KC_MS_D, COMBO_END};

const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM sb_combo[] = {KC_SPC, KC_B, COMBO_END};
const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [OP_BSPC] = COMBO(op_combo, KC_BSPC),

  [ZX_TAB] = COMBO(zx_combo, KC_TAB),

  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [DU_ESC] = COMBO(du_combo, KC_ESC),
  [RBBS_ESC] = COMBO(rbbs_combo, KC_ESC),
  [MUMD_ESC] = COMBO(mumd_combo, KC_ESC),

  [JKL_SCLN] = COMBO(jkl_combo, KC_SCLN),
  [KL_QUOT] = COMBO(kl_combo, KC_QUOT),

  [SB_ENT] = COMBO(sb_combo, KC_ENT),
  [BN_ENT] = COMBO(bn_combo, KC_ENT),
  [CD_ENT] = COMBO(cd_combo, KC_ENT),
  [DS_ENT] = COMBO(ds_combo, KC_ENT)
};
#endif // COMBO_ENABLE

/* combo_t key_combos[COMBO_COUNT] = { */
/*   [FJ_ZER] = COMBO_ACTION(fj_zero), */
/* }; */

/* void process_combo_event(uint16_t combo_index, bool pressed) { */
/*   switch(combo_index) { */
/*     case FJ_ZER: */
/*       if (pressed) { */
/*         layer_move(0); */
/*       } */
/*       break; */
/*   } */
/* } */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		LCTL_T(KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TO(1),
		KC_Z, KC_X, KC_C, KC_V, MT(MOD_LSFT, KC_SPC), KC_B, KC_N, KC_M),

	[MODS] = LAYOUT(
		LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		LSFT_T(KC_BSPC), KC_ESC, KC_TAB, KC_SCLN, KC_QUOT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TO(2),
		KC_LCTL, KC_LGUI, KC_LALT, TO(0), MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT, KC_SLSH),

	[MODS2] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_LSFT, KC_F11, KC_F12, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, TO(3),
		RGB_VAI, RGB_VAD, RGB_HUI, TO(0), MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT, KC_SLSH),

	[OTHER] = LAYOUT(
		KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
		RESET, KC_NO, KC_NO, TO(0), KC_BTN1, KC_MPLY, KC_VOLD, KC_VOLU),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
