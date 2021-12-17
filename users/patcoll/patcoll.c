#include "patcoll.h"
#include "g/keymap_combo.h"

bool is_win_switch_active = false;
bool is_alt_tab_active = false;
bool is_tab_switch_active = false;
/* #ifdef QUICK_SWITCH */
/* bool is_quick_tab_active = false; */
/* uint16_t quick_tab_timer = 0; */
/* #endif */
#ifdef ENCODER_ENABLE
bool is_alt_tab_enc_active = false;
uint16_t alt_tab_enc_timer = 0;
#endif

typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_TAP,
  TD_DOUBLE_HOLD,
  TD_DOUBLE_SINGLE_TAP, // Send two single taps
  TD_TRIPLE_TAP,
  TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} td_tap_t;

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
/* void x_finished(qk_tap_dance_state_t *state, void *user_data); */
/* void x_reset(qk_tap_dance_state_t *state, void *user_data); */

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
/* td_state_t cur_dance(qk_tap_dance_state_t *state) { */
/*   if (state->count == 1) { */
/*     if (state->interrupted || !state->pressed) return TD_SINGLE_TAP; */
/*     // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'. */
/*     else return TD_SINGLE_HOLD; */
/*   } */
/*   #<{(| else if (state->count >= 2) { |)}># */
/*   #<{(|   // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap |)}># */
/*   #<{(|   // action when hitting 'pp'. Suggested use case for this return value is when you want to send two |)}># */
/*   #<{(|   // keystrokes of the key, and not the 'double tap' action/macro. |)}># */
/*   #<{(|   #<{(| if (state->interrupted) return TD_DOUBLE_SINGLE_TAP; |)}># |)}># */
/*   #<{(|   #<{(| else if (state->pressed) return TD_DOUBLE_HOLD; |)}># |)}># */
/*   #<{(|   #<{(| else return TD_DOUBLE_TAP; |)}># |)}># */
/*   #<{(|   #<{(| if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP; |)}># |)}># */
/*   #<{(|   #<{(| else return TD_TRIPLE_HOLD; |)}># |)}># */
/*   #<{(|   return TD_DOUBLE_TAP; |)}># */
/*   #<{(| } |)}># */
/*  */
/*   return TD_DOUBLE_TAP; */
/*  */
/*   // Assumes no one is trying to type the same letter three times (at least not quickly). */
/*   // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add */
/*   // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP' */
/*   #<{(| if (state->count == 3) { |)}># */
/*   #<{(|   if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP; |)}># */
/*   #<{(|   else return TD_TRIPLE_HOLD; |)}># */
/*   #<{(| } else return TD_UNKNOWN; |)}># */
/* } */

// Create an instance of 'td_tap_t' for the 'xfn_ent' tap dance.
/* static td_tap_t xfn_ent_tap_state = { */
/*   .is_press_action = true, */
/*   .state = TD_NONE */
/* }; */
/*  */
/* static td_tap_t xgui_x_tap_state = { */
/*   .is_press_action = true, */
/*   .state = TD_NONE */
/* }; */
/*  */
/* static td_tap_t xalt_c_tap_state = { */
/*   .is_press_action = true, */
/*   .state = TD_NONE */
/* }; */
/*  */
/* void xfn_ent_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   xfn_ent_tap_state.state = cur_dance(state); */
/*   switch (xfn_ent_tap_state.state) { */
/*     case TD_SINGLE_TAP: register_code(KC_ENT); break; */
/*     case TD_SINGLE_HOLD: layer_on(_RAISE); break; */
/*     case TD_DOUBLE_TAP: layer_on(_LOWER); break; */
/*     #<{(| case TD_DOUBLE_HOLD: layer_on(_LOWER); break; |)}># */
/*     // Last case is for fast typing. Assuming your key is `f`: */
/*     // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`. */
/*     // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms. */
/*     #<{(| case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); |)}># */
/*     default: break; */
/*   } */
/* } */
/*  */
/* void xfn_ent_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (xfn_ent_tap_state.state) { */
/*     case TD_SINGLE_TAP: unregister_code(KC_ENT); break; */
/*     case TD_SINGLE_HOLD: layer_off(_RAISE); break; */
/*     case TD_DOUBLE_TAP: layer_off(_LOWER); break; */
/*     #<{(| case TD_DOUBLE_HOLD: layer_off(_LOWER); |)}># */
/*     #<{(| case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); |)}># */
/*     default: break; */
/*   } */
/*   xfn_ent_tap_state.state = TD_NONE; */
/* } */
/*  */
/* void xgui_x_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   xgui_x_tap_state.state = cur_dance(state); */
/*  */
/*   if (xgui_x_tap_state.state != TD_SINGLE_TAP) { */
/*     register_code(KC_LGUI); */
/*     layer_on(_NAV); */
/*   } else { */
/*     register_code(KC_X); */
/*   } */
/*   #<{(| switch (xgui_x_tap_state.state) { |)}># */
/*   #<{(|   case TD_SINGLE_TAP: register_code(KC_X); break; |)}># */
/*   #<{(|   default: register_code(KC_LGUI); layer_on(_NAV); break; |)}># */
/*   #<{(| } |)}># */
/* } */
/*  */
/* void xgui_x_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   #<{(| switch (xgui_x_tap_state.state) { |)}># */
/*   #<{(|   case TD_SINGLE_TAP: unregister_code(KC_X); break; |)}># */
/*   #<{(|   default: unregister_code(KC_LGUI); layer_off(_NAV); break; |)}># */
/*   #<{(| } |)}># */
/*   if (xgui_x_tap_state.state != TD_SINGLE_TAP) { */
/*     unregister_code(KC_LGUI); */
/*     layer_off(_NAV); */
/*   } else { */
/*     unregister_code(KC_X); */
/*   } */
/*   xgui_x_tap_state.state = TD_NONE; */
/* } */
/*  */
/* void xalt_c_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   xalt_c_tap_state.state = cur_dance(state); */
/*  */
/*   if (xalt_c_tap_state.state != TD_SINGLE_TAP) { */
/*     register_code(KC_LALT); */
/*     layer_on(_NAV); */
/*   } else { */
/*     register_code(KC_C); */
/*   } */
/*   #<{(| switch (xalt_c_tap_state.state) { |)}># */
/*   #<{(|   case TD_SINGLE_TAP: register_code(KC_C); break; |)}># */
/*   #<{(|   default: register_code(KC_LALT); layer_on(_NAV); break; |)}># */
/*   #<{(| } |)}># */
/* } */
/*  */
/* void xalt_c_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   #<{(| switch (xalt_c_tap_state.state) { |)}># */
/*   #<{(|   case TD_SINGLE_TAP: unregister_code(KC_C); break; |)}># */
/*   #<{(|   default: unregister_code(KC_LALT); layer_off(_NAV); break; |)}># */
/*   #<{(| } |)}># */
/*   if (xalt_c_tap_state.state != TD_SINGLE_TAP) { */
/*     unregister_code(KC_LALT); */
/*     layer_off(_NAV); */
/*   } else { */
/*     unregister_code(KC_C); */
/*   } */
/*   xalt_c_tap_state.state = TD_NONE; */
/* } */

qk_tap_dance_action_t tap_dance_actions[] = {
  /* [XFN_ENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xfn_ent_finished, xfn_ent_reset), */
  /* [XGUI_X] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xgui_x_finished, xgui_x_reset), */
  /* [XALT_C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, xalt_c_finished, xalt_c_reset) */
};

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
/* # ifdef QUICK_SWITCH */
/*   if (is_quick_tab_active && timer_elapsed(quick_tab_timer) > 1000) { */
/*     unregister_code(KC_LALT); */
/*     is_quick_tab_active = false; */
/*   } */
/* # endif */
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
        case EX_ARR:
          SEND_STRING("->");
          break;
        case EX_PAR:
          SEND_STRING("()");
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
      /* case NXT_TAB: */
      /* case PRV_TAB: */
      /*   if (is_win_switch_active) { */
      /*     is_win_switch_active = false; */
      /*     unregister_code(KC_LGUI); */
      /*   } */
      /*   if (is_alt_tab_active) { */
      /*     is_alt_tab_active = false; */
      /*     unregister_code(KC_LALT); */
      /*   } */
      /*   if (!is_tab_switch_active) { */
      /*     is_tab_switch_active = true; */
      /*     register_code(KC_LCTL); */
      /*   } */
      /*   keycode == NXT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB)); */
      /*   return false; */
/* #     ifdef QUICK_SWITCH */
/*       // Quickly toggle between windows with three fancy keys */
/*       case QCK_TAB: */
/*       case QCKSTAB: */
/*         if (!is_quick_tab_active) { */
/*           is_quick_tab_active = true; */
/*           register_code(KC_LALT); */
/*         } */
/*         keycode == QCK_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB)); */
/*         quick_tab_timer = timer_read(); */
/*         return false; */
/*       case QCK_SEL: */
/*         if (is_quick_tab_active) { */
/*           is_quick_tab_active = false; */
/*           unregister_code(KC_LALT); */
/*         } */
/*         return false; */
/* #     endif */
    }
  }

  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_SPC:
    case SFT_ENT:
    case SFT_A:
    /* case SFT_E: */
    case SFT_V:
    /* case SFT_SCLN: */
    /* case SFT_QUOT: */
      return TAPPING_TERM - 12;
    case SFT_Z:
    case SFT_DOT:
    case SFT_M:
    case SFT_SLSH:
    case TD(XFN_ENT):
      return TAPPING_TERM - 20;
    /* case TD(XFN_ENT): */
    /*   return TAPPING_TERM - 30; */
    default:
      return TAPPING_TERM;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_Z:
    case SFT_A:
    /* case SFT_E: */
    case SFT_V:
    case SFT_SPC:
    case SFT_ENT:
    case SFT_SCLN:
    case SFT_QUOT:
    case SFT_SLSH:
    case SFT_DOT:
    case SFT_M:
    case TD(XFN_ENT):
      return true;
    default:
      return false;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(1, KC_BSPC):
    case TD(XFN_ENT):
    /*   // Immediately select the hold action when another key is pressed. */
    /*   return true; */
    default:
      // Do not select the hold action when another key is pressed.
      return false;
  }
}

/* #ifdef COMBO_ENABLE */
/* enum combos { */
/*   #<{(| FJ_ZER, |)}># */
/*   #<{(| SCDN_ZER, |)}># */
/*  */
/*   OP_COMBO = 0, */
/*   PBSP_COMBO, */
/*   PBSCMB_COMBO, */
/*   NT_COMBO, */
/*   LPRP_COMBO, */
/*  */
/*   QW_COMBO, */
/*   AS_COMBO, */
/*   #<{(| F1F2_COMBO, |)}># */
/*   SD_COMBO, */
/*  */
/*   #<{(| YU_COMBO |)}># */
/*   #<{(| SS_COMBO |)}># */
/*  */
/*   SF_COMBO, */
/*   DF_COMBO, */
/*  */
/*   DG_COMBO, */
/*   FG_COMBO, */
/*  */
/*   DFDOT_COMBO, */
/*   SDFDOT_COMBO, */
/*   DFI_COMBO, */
/*   DFO_COMBO, */
/*   DFP_COMBO, */
/*  */
/*   DFM_COMBO, */
/*  */
/*   GH_COMBO, */
/*  */
/*   #<{(| UI_COMBO, |)}># */
/*  */
/*   #<{(| SE_COMBO, |)}># */
/*   #<{(| FSE_COMBO, |)}># */
/*   #<{(| MWDU_COMBO, |)}># */
/*  */
/*   JK_COMBO, */
/*   DU_COMBO, */
/*   RBBS_COMBO, */
/*   MUMD_COMBO, */
/*  */
/*   JL_COMBO, */
/*  */
/*   #<{(| UR_COMBO, |)}># */
/*  */
/*   HJ_COMBO, */
/*   #<{(| LD_COMBO, |)}># */
/*   #<{(| BR_COMBO, |)}># */
/*   #<{(| MLD_COMBO, |)}># */
/*  */
/*   #<{(| JI_COMBO, |)}># */
/*   #<{(| DE_COMBO, |)}># */
/*   #<{(| RBF8_COMBO, |)}># */
/*   #<{(| MDWU_COMBO, |)}># */
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
/*   CS_COMBO, */
/*  */
/*   MC_COMBO, */
/*   #<{(| CD_COMBO, |)}># */
/*   MD_COMBO, */
/*  */
/*   COMBO_LENGTH, */
/* }; */
/*  */
/* uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead! */
/*  */
/* #<{(| const uint16_t PROGMEM fj_zero[] = {KC_F, KC_J, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM scdn_zero[] = {KC_SCLN, KC_DOWN, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM pbsp_combo[] = {KC_P, KC_BSPC, COMBO_END}; */
/* const uint16_t PROGMEM pbscmb_combo[] = {KC_P, CS_BSPC, COMBO_END}; */
/* const uint16_t PROGMEM nt_combo[] = {KC_9, KC_0, COMBO_END}; */
/* const uint16_t PROGMEM lprp_combo[] = {KC_LPRN, KC_RPRN, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END}; */
/* #<{(| const uint16_t PROGMEM f1f2_combo[] = {KC_F1, KC_F2, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM ss_combo[] = {KC_6, KC_7, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM sf_combo[] = {KC_S, KC_F, COMBO_END}; */
/* const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM dg_combo[] = {KC_D, KC_G, COMBO_END}; */
/* const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END}; */
/*  */
/* // TODO the alpha equivalent to this should be f and m */
/* const uint16_t PROGMEM dfdot_combo[] = {KC_D, KC_F, KC_DOT, COMBO_END}; */
/* const uint16_t PROGMEM sdfdot_combo[] = {KC_S, KC_D, KC_F, KC_DOT, COMBO_END}; */
/* const uint16_t PROGMEM dfi_combo[] = {KC_D, KC_F, KC_I, COMBO_END}; */
/* const uint16_t PROGMEM dfo_combo[] = {KC_D, KC_F, KC_O, COMBO_END}; */
/* const uint16_t PROGMEM dfp_combo[] = {KC_D, KC_F, KC_P, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM dfm_combo[] = {KC_D, KC_F, KC_M, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END}; |)}># */
/*  */
/* #<{(| const uint16_t PROGMEM se_combo[] = {KC_7, KC_8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM fse_combo[] = {KC_F7, KC_F8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM mwdu_combo[] = {KC_WH_D, KC_WH_U, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP, COMBO_END}; */
/* const uint16_t PROGMEM rbbs_combo[] = {KC_RBRC, KC_BSLS, COMBO_END}; */
/* const uint16_t PROGMEM mumd_combo[] = {KC_MS_U, KC_MS_D, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM ur_combo[] = {KC_UP, KC_RGHT, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END}; */
/* #<{(| const uint16_t PROGMEM ld_combo[] = {KC_LEFT, KC_DOWN, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM br_combo[] = {KC_LBRC, KC_RBRC, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM mld_combo[] = {KC_MS_L, KC_MS_D, COMBO_END}; |)}># */
/*  */
/* #<{(| const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM de_combo[] = {KC_DOWN, KC_8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM rbf8_combo[] = {KC_RBRC, KC_F8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM mdwu_combo[] = {KC_MS_D, KC_WH_U, COMBO_END}; |)}># */
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
/* const uint16_t PROGMEM mc_combo[] = {KC_M, KC_COMM, COMBO_END}; */
/* const uint16_t PROGMEM md_combo[] = {KC_M, KC_DOT, COMBO_END}; */
/*  */
/* combo_t key_combos[] = { */
/*   [OP_COMBO] = COMBO(op_combo, KC_BSPC), */
/*   [PBSP_COMBO] = COMBO(pbsp_combo, KC_BSPC), */
/*   [PBSCMB_COMBO] = COMBO(pbscmb_combo, KC_BSPC), */
/*   [NT_COMBO] = COMBO(nt_combo, KC_BSPC), */
/*   [LPRP_COMBO] = COMBO(lprp_combo, KC_BSPC), */
/*  */
/*   [QW_COMBO] = COMBO(qw_combo, KC_TAB), */
/*  */
/*   [AS_COMBO] = COMBO(as_combo, KC_TAB), */
/*   #<{(| [F1F2_COMBO] = COMBO(f1f2_combo, A(KC_TAB)), |)}># */
/*  */
/*   [SD_COMBO] = COMBO(sd_combo, KC_ESC), */
/*  */
/*   #<{(| [YU_COMBO] = COMBO(yu_combo, KC_ESC), |)}># */
/*   #<{(| [SS_COMBO] = COMBO(ss_combo, KC_ESC), |)}># */
/*  */
/*   [SF_COMBO] = COMBO(sf_combo, KC_COLN), */
/*   [DF_COMBO] = COMBO(df_combo, KC_SCLN), */
/*  */
/*   [DG_COMBO] = COMBO(dg_combo, KC_UNDS), */
/*   [FG_COMBO] = COMBO(fg_combo, KC_MINS), */
/*  */
/*   [DFDOT_COMBO] = COMBO(dfdot_combo, EX_PIPE), */
/*   [SDFDOT_COMBO] = COMBO(sdfdot_combo, EX_ARR), */
/*   [DFI_COMBO] = COMBO(dfi_combo, EX_INSP), */
/*   [DFO_COMBO] = COMBO(dfo_combo, EX_PAR), */
/*   [DFP_COMBO] = COMBO(dfp_combo, EX_SEAR), */
/*  */
/* #ifdef PATCOLL_ALPHA_COMBOS */
/*   [DFM_COMBO] = COMBO(dfm_combo, EX_PIPE), */
/* #endif */
/*  */
/*   [GH_COMBO] = COMBO(gh_combo, KC_EQL), */
/*  */
/*   #<{(| [UI_COMBO] = COMBO(ui_combo, TO(_RAISE)), |)}># */
/*  */
/*   #<{(| [SE_COMBO] = COMBO(se_combo, KC_ESC), |)}># */
/*   #<{(| [FSE_COMBO] = COMBO(fse_combo, KC_ESC), |)}># */
/*   #<{(| [MWDU_COMBO] = COMBO(mwdu_combo, KC_ESC), |)}># */
/*  */
/*   [JK_COMBO] = COMBO(jk_combo, KC_ESC), */
/*   [DU_COMBO] = COMBO(du_combo, KC_ESC), */
/*   [RBBS_COMBO] = COMBO(rbbs_combo, KC_ESC), */
/*   [MUMD_COMBO] = COMBO(mumd_combo, KC_ESC), */
/*  */
/*   [JL_COMBO] = COMBO(jl_combo, KC_DQUO), */
/*  */
/*   #<{(| [UR_COMBO] = COMBO(ur_combo, TO(_MOUSE)), |)}># */
/*  */
/*   #<{(| [HJ_COMBO] = COMBO(hj_combo, TO(_RAISE)), |)}># */
/*  */
/*   #<{(| [LD_COMBO] = COMBO(ld_combo, KC_ENT), |)}># */
/*   #<{(| [BR_COMBO] = COMBO(br_combo, KC_ENT), |)}># */
/*   #<{(| [MLD_COMBO] = COMBO(mld_combo, KC_ENT), |)}># */
/*  */
/*   #<{(| [JI_COMBO] = COMBO(ji_combo, KC_ENT), |)}># */
/*   #<{(| [DE_COMBO] = COMBO(de_combo, KC_ENT), |)}># */
/*   #<{(| [RBF8_COMBO] = COMBO(rbf8_combo, KC_ENT), |)}># */
/*   #<{(| [MDWU_COMBO] = COMBO(mdwu_combo, KC_ENT), |)}># */
/*  */
/* #ifdef PATCOLL_ALPHA_COMBOS */
/*   [BK_COMBO] = COMBO(bk_combo, KC_ENT), */
/*   [CU_COMBO] = COMBO(cu_combo, KC_ENT), */
/*   [CB_COMBO] = COMBO(cb_combo, KC_ENT), */
/*   [MPU_COMBO] = COMBO(mpu_combo, KC_ENT), */
/* #endif */
/*  */
/*   [MK_COMBO] = COMBO(mk_combo, KC_ENT), */
/*   [UL_COMBO] = COMBO(ul_combo, KC_ENT), */
/*  */
/*   #<{(| [JKL_COMBO] = COMBO(jkl_combo, KC_SCLN), |)}># */
/*   [KL_COMBO] = COMBO(kl_combo, KC_QUOT), */
/*  */
/* #ifdef PATCOLL_ALPHA_COMBOS */
/*   [BN_COMBO] = COMBO(bn_combo, KC_COMM), */
/*   [CD_COMBO] = COMBO(cd_combo, KC_COMM), */
/*  */
/*   [NM_COMBO] = COMBO(nm_combo, KC_DOT), */
/*   [DS_COMBO] = COMBO(ds_combo, KC_DOT), */
/*  */
/*   [BM_COMBO] = COMBO(bm_combo, KC_SLSH), */
/*   [CS_COMBO] = COMBO(cs_combo, KC_SLSH), */
/* #else */
/*   // standard layout */
/*   [MC_COMBO] = COMBO(mc_combo, KC_COMM), */
/*   [CD_COMBO] = COMBO(cd_combo, KC_DOT), */
/*   [MD_COMBO] = COMBO(md_combo, KC_SLSH), */
/* #endif */
/* }; */
/* #endif // COMBO_ENABLE */
