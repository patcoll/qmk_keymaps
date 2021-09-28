#include "patcoll.h"

bool is_win_switch_active = false;
bool is_alt_tab_active = false;
bool is_tab_switch_active = false;
#ifdef QUICK_SWITCH
bool is_quick_tab_active = false;
uint16_t quick_tab_timer = 0;
#endif
#ifdef ENCODER_ENABLE
bool is_alt_tab_enc_active = false;
uint16_t alt_tab_enc_timer = 0;
#endif

void matrix_scan_user(void) {
  // End fancy nav switching if the NAV layer has been deactivated.
  if (is_win_switch_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LGUI);
    is_win_switch_active = false;
  }
  if (is_alt_tab_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LALT);
    is_alt_tab_active = false;
  }
  if (is_tab_switch_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LCTL);
    is_tab_switch_active = false;
  }
# ifdef QUICK_SWITCH
  if (is_quick_tab_active && timer_elapsed(quick_tab_timer) > 1000) {
    unregister_code(KC_LALT);
    is_quick_tab_active = false;
  }
# endif
# ifdef ENCODER_ENABLE
  if (is_alt_tab_enc_active) {
    if (timer_elapsed(alt_tab_enc_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_enc_active = false;
    }
  }
# endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (keycode >= EX_PIPE && keycode <= EX_SEAR) {
      switch (keycode) {
        case EX_PIPE:
          SEND_STRING("|>");
          break;
        case EX_INSP:
          SEND_STRING("IO.inspect(");
          break;
        case EX_SEAR:
          SEND_STRING("elixir phoenix ");
          break;
      }
      return false;
    }

    // Window switching macro, only available when NAV layer is active.
    /* if (keycode >= WNDW_1 && keycode <= WNDW_0) { */
    /*   if (is_alt_tab_active) { */
    /*     is_alt_tab_active = false; */
    /*     unregister_code(KC_LALT); */
    /*   } */
    /*   if (is_tab_switch_active) { */
    /*       is_tab_switch_active = false; */
    /*       unregister_code(KC_LCTL); */
    /*   } */
    /*   if (!is_win_switch_active) { */
    /*     is_win_switch_active = true; */
    /*     register_code(KC_LGUI); */
    /*   } */
    /*   switch (keycode) { */
    /*     case WNDW_0: */
    /*       tap_code16(KC_0); */
    /*       break; */
    /*     case WNDW_1: */
    /*       tap_code16(KC_1); */
    /*       break; */
    /*     case WNDW_2: */
    /*       tap_code16(KC_2); */
    /*       break; */
    /*     case WNDW_3: */
    /*       tap_code16(KC_3); */
    /*       break; */
    /*     case WNDW_4: */
    /*       tap_code16(KC_4); */
    /*       break; */
    /*     case WNDW_5: */
    /*       tap_code16(KC_5); */
    /*       break; */
    /*     case WNDW_6: */
    /*       tap_code16(KC_6); */
    /*       break; */
    /*     case WNDW_7: */
    /*       tap_code16(KC_7); */
    /*       break; */
    /*     case WNDW_8: */
    /*       tap_code16(KC_8); */
    /*       break; */
    /*     case WNDW_9: */
    /*       tap_code16(KC_9); */
    /*       break; */
    /*   } */
    /*   return false; */
    /* } */
    switch (keycode) {
      // Super Alt-Tab
      case ALT_TAB:
      case SALTTAB:
        if (is_win_switch_active) {
          is_win_switch_active = false;
          unregister_code(KC_LGUI);
        }
        if (is_tab_switch_active) {
          is_tab_switch_active = false;
          unregister_code(KC_LCTL);
        }
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        keycode == ALT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        return false;
      // Super tab switching
      case NXT_TAB:
      case PRV_TAB:
        if (is_win_switch_active) {
          is_win_switch_active = false;
          unregister_code(KC_LGUI);
        }
        if (is_alt_tab_active) {
          is_alt_tab_active = false;
          unregister_code(KC_LALT);
        }
        if (!is_tab_switch_active) {
          is_tab_switch_active = true;
          register_code(KC_LCTL);
        }
        keycode == NXT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        return false;
#     ifdef QUICK_SWITCH
      // Quickly toggle between windows with three fancy keys
      case QCK_TAB:
      case QCKSTAB:
        if (!is_quick_tab_active) {
          is_quick_tab_active = true;
          register_code(KC_LALT);
        }
        keycode == QCK_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        quick_tab_timer = timer_read();
        return false;
      case QCK_SEL:
        if (is_quick_tab_active) {
          is_quick_tab_active = false;
          unregister_code(KC_LALT);
        }
        return false;
#     endif
    }
  }

  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_SPC:
    case SFT_ENT:
    /* case SFT_SCLN: */
    /* case SFT_QUOT: */
      return TAPPING_TERM - 12;
    case SFT_SLSH:
      return TAPPING_TERM - 20;
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_SPC:
    case SFT_ENT:
    case SFT_SCLN:
    case SFT_QUOT:
    case SFT_SLSH:
      return true;
    default:
      return false;
  }
}

#ifdef COMBO_ENABLE
enum combos {
  /* FJ_ZER, */
  /* SCDN_ZER, */

  OP_COMBO = 0,
  PBSP_COMBO,
  NT_COMBO,
  LPRP_COMBO,

  QW_COMBO,
  AS_COMBO,
  /* F1F2_COMBO, */
  SD_COMBO,

  /* YU_COMBO */
  /* SS_COMBO */

  SF_COMBO,
  DF_COMBO,

  DG_COMBO,
  FG_COMBO,

  DFDOT_COMBO,
  DFI_COMBO,
  DFP_COMBO,

  GH_COMBO,

  /* UI_COMBO, */

  /* SE_COMBO, */
  /* FSE_COMBO, */
  /* MWDU_COMBO, */

  JK_COMBO,
  DU_COMBO,
  RBBS_COMBO,
  MUMD_COMBO,

  JL_COMBO,

  UR_COMBO,

  HJ_COMBO,
  /* LD_COMBO, */
  /* BR_COMBO, */
  /* MLD_COMBO, */

  /* JI_COMBO, */
  /* DE_COMBO, */
  /* RBF8_COMBO, */
  /* MDWU_COMBO, */

  BK_COMBO,
  CU_COMBO,
  CB_COMBO,
  MPU_COMBO,

  MK_COMBO,
  UL_COMBO,

  /* JKL_COMBO, */
  KL_COMBO,

  SB_COMBO,
  BN_COMBO,
  CD_COMBO,

  /* BNM_COMBO, */

  NM_COMBO,
  DS_COMBO,

  BM_COMBO,
  CS_COMBO,

  MC_COMBO,
  /* CD_COMBO, */
  MD_COMBO,

  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

/* const uint16_t PROGMEM fj_zero[] = {KC_F, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM scdn_zero[] = {KC_SCLN, KC_DOWN, COMBO_END}; */

const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM pbsp_combo[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM nt_combo[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM lprp_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
/* const uint16_t PROGMEM f1f2_combo[] = {KC_F1, KC_F2, COMBO_END}; */

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};

/* const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END}; */
/* const uint16_t PROGMEM ss_combo[] = {KC_6, KC_7, COMBO_END}; */

const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM dg_combo[] = {KC_D, KC_G, COMBO_END};
const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};

// TODO the alpha equivalent to this should be f and m
const uint16_t PROGMEM dfdot_combo[] = {KC_D, KC_F, KC_DOT, COMBO_END};
const uint16_t PROGMEM dfi_combo[] = {KC_D, KC_F, KC_I, COMBO_END};
const uint16_t PROGMEM dfp_combo[] = {KC_D, KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};

/* const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END}; */

/* const uint16_t PROGMEM se_combo[] = {KC_7, KC_8, COMBO_END}; */
/* const uint16_t PROGMEM fse_combo[] = {KC_F7, KC_F8, COMBO_END}; */
/* const uint16_t PROGMEM mwdu_combo[] = {KC_WH_D, KC_WH_U, COMBO_END}; */

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM rbbs_combo[] = {KC_RBRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM mumd_combo[] = {KC_MS_U, KC_MS_D, COMBO_END};

const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM ur_combo[] = {KC_UP, KC_RGHT, COMBO_END};

const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
/* const uint16_t PROGMEM ld_combo[] = {KC_LEFT, KC_DOWN, COMBO_END}; */
/* const uint16_t PROGMEM br_combo[] = {KC_LBRC, KC_RBRC, COMBO_END}; */
/* const uint16_t PROGMEM mld_combo[] = {KC_MS_L, KC_MS_D, COMBO_END}; */

/* const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END}; */
/* const uint16_t PROGMEM de_combo[] = {KC_DOWN, KC_8, COMBO_END}; */
/* const uint16_t PROGMEM rbf8_combo[] = {KC_RBRC, KC_F8, COMBO_END}; */
/* const uint16_t PROGMEM mdwu_combo[] = {KC_MS_D, KC_WH_U, COMBO_END}; */

const uint16_t PROGMEM bk_combo[] = {KC_B, KC_K, COMBO_END};
const uint16_t PROGMEM cu_combo[] = {KC_COMM, KC_UP, COMBO_END};
const uint16_t PROGMEM cb_combo[] = {KC_COMM, KC_BSLS, COMBO_END};
const uint16_t PROGMEM mpu_combo[] = {KC_MPLY, KC_MS_U, COMBO_END};

const uint16_t PROGMEM mk_combo[] = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM ul_combo[] = {KC_UP, KC_LBRC, COMBO_END};

/* const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END}; */
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

/* const uint16_t PROGMEM sb_combo[] = {KC_SPC, KC_B, COMBO_END}; */
const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};

/* const uint16_t PROGMEM bnm_combo[] = {KC_B, KC_N, KC_M, COMBO_END}; */

const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM cs_combo[] = {KC_COMM, KC_SLSH, COMBO_END};

const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM md_combo[] = {KC_M, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [OP_COMBO] = COMBO(op_combo, KC_BSPC),
  [PBSP_COMBO] = COMBO(pbsp_combo, KC_BSPC),
  [NT_COMBO] = COMBO(nt_combo, KC_BSPC),
  [LPRP_COMBO] = COMBO(lprp_combo, KC_BSPC),

  [QW_COMBO] = COMBO(qw_combo, KC_TAB),

  [AS_COMBO] = COMBO(as_combo, KC_TAB),
  /* [F1F2_COMBO] = COMBO(f1f2_combo, A(KC_TAB)), */

  [SD_COMBO] = COMBO(sd_combo, KC_ESC),

  /* [YU_COMBO] = COMBO(yu_combo, KC_ESC), */
  /* [SS_COMBO] = COMBO(ss_combo, KC_ESC), */

  [SF_COMBO] = COMBO(sf_combo, KC_COLN),
  [DF_COMBO] = COMBO(df_combo, KC_SCLN),

  [DG_COMBO] = COMBO(dg_combo, KC_UNDS),
  [FG_COMBO] = COMBO(fg_combo, KC_MINS),

  [DFDOT_COMBO] = COMBO(dfdot_combo, EX_PIPE),
  [DFI_COMBO] = COMBO(dfi_combo, EX_INSP),
  [DFP_COMBO] = COMBO(dfp_combo, EX_SEAR),

  [GH_COMBO] = COMBO(gh_combo, KC_EQL),

  /* [UI_COMBO] = COMBO(ui_combo, TO(_RAISE)), */

  /* [SE_COMBO] = COMBO(se_combo, KC_ESC), */
  /* [FSE_COMBO] = COMBO(fse_combo, KC_ESC), */
  /* [MWDU_COMBO] = COMBO(mwdu_combo, KC_ESC), */

  [JK_COMBO] = COMBO(jk_combo, KC_ESC),
  [DU_COMBO] = COMBO(du_combo, KC_ESC),
  [RBBS_COMBO] = COMBO(rbbs_combo, KC_ESC),
  [MUMD_COMBO] = COMBO(mumd_combo, KC_ESC),

  [JL_COMBO] = COMBO(jl_combo, KC_DQUO),

  [UR_COMBO] = COMBO(ur_combo, TO(_MOUSE)),

  /* [HJ_COMBO] = COMBO(hj_combo, TO(_RAISE)), */

  /* [LD_COMBO] = COMBO(ld_combo, KC_ENT), */
  /* [BR_COMBO] = COMBO(br_combo, KC_ENT), */
  /* [MLD_COMBO] = COMBO(mld_combo, KC_ENT), */

  /* [JI_COMBO] = COMBO(ji_combo, KC_ENT), */
  /* [DE_COMBO] = COMBO(de_combo, KC_ENT), */
  /* [RBF8_COMBO] = COMBO(rbf8_combo, KC_ENT), */
  /* [MDWU_COMBO] = COMBO(mdwu_combo, KC_ENT), */

#ifdef PATCOLL_ALPHA_COMBOS
  [BK_COMBO] = COMBO(bk_combo, KC_ENT),
  [CU_COMBO] = COMBO(cu_combo, KC_ENT),
  [CB_COMBO] = COMBO(cb_combo, KC_ENT),
  [MPU_COMBO] = COMBO(mpu_combo, KC_ENT),
#endif

  [MK_COMBO] = COMBO(mk_combo, KC_ENT),
  [UL_COMBO] = COMBO(ul_combo, KC_ENT),

  /* [JKL_COMBO] = COMBO(jkl_combo, KC_SCLN), */
  [KL_COMBO] = COMBO(kl_combo, KC_QUOT),

#ifdef PATCOLL_ALPHA_COMBOS
  [BN_COMBO] = COMBO(bn_combo, KC_COMM),
  [CD_COMBO] = COMBO(cd_combo, KC_COMM),

  [NM_COMBO] = COMBO(nm_combo, KC_DOT),
  [DS_COMBO] = COMBO(ds_combo, KC_DOT),

  [BM_COMBO] = COMBO(bm_combo, KC_SLSH),
  [CS_COMBO] = COMBO(cs_combo, KC_SLSH),
#else
  // standard layout
  [MC_COMBO] = COMBO(mc_combo, KC_COMM),
  [CD_COMBO] = COMBO(cd_combo, KC_DOT),
  [MD_COMBO] = COMBO(md_combo, KC_SLSH),
#endif
};
#endif // COMBO_ENABLE
