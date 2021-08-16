#include QMK_KEYBOARD_H

#define HOME 0
#define MODS 1
#define MODS2 2
#define OTHER 3
#define NAV 4

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

combo_t key_combos[COMBO_COUNT] = {
  [OP_COMBO] = COMBO(op_combo, KC_BSPC),

  /* [QW_COMBO] = COMBO(qw_combo, KC_TAB), */
  [AS_COMBO] = COMBO(as_combo, KC_TAB),

  /* [YU_COMBO] = COMBO(yu_combo, KC_ESC), */
  /* [SS_COMBO] = COMBO(ss_combo, KC_ESC), */

  [DF_COMBO] = COMBO(df_combo, KC_SCLN),

  [FG_COMBO] = COMBO(fg_combo, KC_MINS),

  [GH_COMBO] = COMBO(gh_combo, KC_EQL),

  /* [UI_COMBO] = COMBO(ui_combo, KC_ESC), */
  /* [SE_COMBO] = COMBO(se_combo, KC_ESC), */
  /* [FSE_COMBO] = COMBO(fse_combo, KC_ESC), */
  /* [MWDU_COMBO] = COMBO(mwdu_combo, KC_ESC), */

  [JK_COMBO] = COMBO(jk_combo, KC_ESC),
  [DU_COMBO] = COMBO(du_combo, KC_ESC),
  [RBBS_COMBO] = COMBO(rbbs_combo, KC_ESC),
  [MUMD_COMBO] = COMBO(mumd_combo, KC_ESC),

  [HJ_COMBO] = COMBO(hj_combo, KC_ENT),
  [LD_COMBO] = COMBO(ld_combo, KC_ENT),
  [BR_COMBO] = COMBO(br_combo, KC_ENT),
  [MLD_COMBO] = COMBO(mld_combo, KC_ENT),

  [JI_COMBO] = COMBO(ji_combo, KC_ENT),
  [DE_COMBO] = COMBO(de_combo, KC_ENT),
  [RBF8_COMBO] = COMBO(rbf8_combo, KC_ENT),
  [MDWU_COMBO] = COMBO(mdwu_combo, KC_ENT),

  [BK_COMBO] = COMBO(bk_combo, KC_ENT),
  [CU_COMBO] = COMBO(cu_combo, KC_ENT),
  [CB_COMBO] = COMBO(cb_combo, KC_ENT),
  [MPU_COMBO] = COMBO(mpu_combo, KC_ENT),

  /* [JKL_COMBO] = COMBO(jkl_combo, KC_SCLN), */
  [KL_COMBO] = COMBO(kl_combo, KC_QUOT),

  [BN_COMBO] = COMBO(bn_combo, KC_COMM),
  [CD_COMBO] = COMBO(cd_combo, KC_COMM),

  [NM_COMBO] = COMBO(nm_combo, KC_DOT),
  [DS_COMBO] = COMBO(ds_combo, KC_DOT),

  [BM_COMBO] = COMBO(bm_combo, KC_SLSH),
  [CS_COMBO] = COMBO(cs_combo, KC_SLSH)
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Homerow mods
    /* case MT(MOD_LGUI, KC_A): */
    /* case MT(MOD_LALT, KC_S): */
    /* case MT(MOD_LCTL, KC_D): */
    /* case MT(MOD_RCTL, KC_K): */
    /* case MT(MOD_RALT, KC_L): */
    /* case MT(MOD_RGUI, KC_SCLN): */
    /* case MT(MOD_LALT, KC_R): */
    /* case MT(MOD_LCTL, KC_S): */
    /* case MT(MOD_RCTL, KC_E): */
    /* case MT(MOD_RALT, KC_I): */
    /* case MT(MOD_RGUI, KC_O): */
    /* case MT(MOD_LGUI, KC_R): */
    /* case MT(MOD_LCTL, KC_N): */
    /* case MT(MOD_RALT, KC_A): */
    /* case MT(MOD_RGUI, KC_I): */
    /*   return TAPPING_TERM; */
    // Shift
    case MT(MOD_LSFT, KC_SPC):
      return TAPPING_TERM - 15;
    // LT
    /* case MT(MOD_LCTL, KC_TAB): */
    /* case LT(_NUMBERS, KC_BSPC): */
    /* case LT(_NAV, KC_SPC): */
    /* case LT(_LOWER, KC_E): */
    /*   return TAPPING_TERM - 25; */
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case MT(MOD_LSFT, KC_SPC):
      return true;
    default:
      return false;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		LCTL_T(KC_Q), LT(1, KC_W), KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, TO(1),
		LT(1, KC_Z), LT(2, KC_X), KC_C, LCTL_T(KC_V), MT(MOD_LSFT, KC_SPC), KC_B, KC_N, KC_M),

	[MODS] = LAYOUT(
		LCTL_T(KC_1), KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		LSFT_T(KC_BSPC), KC_ESC, KC_TAB, KC_SCLN, KC_QUOT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TO(2),
		KC_LCTL, KC_LGUI, KC_LALT, TO(0), MT(MOD_LSFT, KC_SPC), KC_COMM, KC_DOT, KC_SLSH),

	[MODS2] = LAYOUT(
		LCTL_T(KC_F1), KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_LSFT, KC_F11, KC_F12, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, TO(3),
		RGB_VAI, RGB_VAD, RGB_HUI, TO(0), MT(MOD_LSFT, KC_SPC), MT(MOD_MEH, KC_COMM), MT(MOD_HYPR, KC_DOT), KC_SLSH),

	[OTHER] = LAYOUT(
		KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
		RESET, KC_NO, KC_NO, TO(0), KC_BTN1, KC_MPLY, KC_VOLD, KC_VOLU),
  /*  */
	/* [NAV] = LAYOUT( */
	/* 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, */
	/* 	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, */
	/* 	RESET, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, KC_NO), */
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
