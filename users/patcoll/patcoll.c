#include "patcoll.h"
#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

bool mac_mode = false;
bool game_mode = false;

bool is_alt_tab_active = false;
int alt_tab_slight_delay_ms = 120;

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) {
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) void pointing_device_init_keymap(void) {}

void keyboard_post_init_user(void) {
  keyboard_post_init_keymap();
}

void matrix_scan_user(void) {
  // End fancy nav switching if the NAV layer has been deactivated.
  if (is_alt_tab_active && !IS_LAYER_ON(_NAV)) {
    unregister_code(KC_LALT);
    is_alt_tab_active = false;
  }

  matrix_scan_keymap();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (keycode == GAME_TG) {
      // TODO: toggle layer
      if (game_mode == false) {
        layer_on(_GAMING);
        game_mode = true;
      } else {
        layer_off(_GAMING);
        game_mode = false;
      }
      return false;
    }

    if (keycode == MAC_TG) {
      mac_mode = !mac_mode;
      return false;
    }

    if (keycode == C_CUT) {
      mac_mode == true ? tap_code16(A(KC_X)) : tap_code16(C(KC_X));
      return false;
    }

    if (keycode == C_COPY) {
      mac_mode == true ? tap_code16(A(KC_C)) : tap_code16(C(KC_C));
      return false;
    }

    if (keycode == C_PASTE) {
      mac_mode == true ? tap_code16(A(KC_V)) : tap_code16(C(KC_V));
      return false;
    }

    if (keycode == CLS_WIN) {
      mac_mode == true ? tap_code16(C(KC_W)) : tap_code16(A(KC_F4));
      return false;
    }

    if (keycode == CEN_WIN) {
      mac_mode == true ? tap_code16(G(A(KC_C))) : tap_code16(S(C(A(KC_C))));
      return false;
    }

    if (keycode == GO_BACK) {
      mac_mode == true ? tap_code16(A(KC_LBRC)) : tap_code16(A(KC_LEFT));
      return false;
    }

    if (keycode == GO_FWD) {
      mac_mode == true ? tap_code16(A(KC_RBRC)) : tap_code16(A(KC_RGHT));
      return false;
    }

    if (keycode == WIN_HIDE) {
      mac_mode == true ? tap_code16(A(KC_H)) : tap_code16(G(KC_PGDN));
      return false;
    }

    if (keycode == WIN_MAX) {
      mac_mode == true ? tap_code16(G(A(KC_F))) : tap_code16(G(KC_PGUP));
      return false;
    }

    if (keycode == SCR_SHT) {
      mac_mode == true ? tap_code16(S(A(KC_3))) : tap_code16(S(KC_PSCR));
      return false;
    }

    if (keycode == SCR_WIN) {
      mac_mode == true ? tap_code16(S(A(KC_4))) : tap_code16(G(S(KC_PSCR)));
      return false;
    }

    if (keycode == SCR_LCK) {
      mac_mode == true ? tap_code16(C(A(KC_Q))) : tap_code16(C(G(A(S(KC_L)))));
      return false;
    }

    if (keycode >= EX_PIPE && keycode <= EX_SEAR) {
      switch (keycode) {
        case EX_PIPE:
          SEND_STRING("|>");
          break;
        case EX_ARR:
          SEND_STRING("->");
          break;
        case EX_DARR:
          SEND_STRING("=>");
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

    switch (keycode) {
      // Super Alt-Tab
      case ALT_TAB:
      case SALTTAB:
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
          // 2023-03-06: I found that without adding a slight delay, the custom alt-tab behavior would not act as expected for the first invocation.
          wait_ms(alt_tab_slight_delay_ms);
        }
        keycode == ALT_TAB ? tap_code16(KC_TAB) : tap_code16(S(KC_TAB));
        return false;
#ifdef POINTING_DEVICE_ENABLE
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
#endif
    }
  }

  return process_record_keymap(keycode, record);
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (!encoder_update_keymap(index, clockwise)) {
    return false;
  }

  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }

  return true;
}
#endif

#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_user(void) {
  // set default pointing device resolution
  pointing_device_set_cpi(400);

  pointing_device_init_keymap();
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_SPC:
    /* case SFT_M: */
    case SFT_ENT:
    case SFT_A:
    case SFT_V:
      return TAPPING_TERM - 12;
    case SFT_Z:
    case SFT_DOT:
    case SFT_SLSH:
      return TAPPING_TERM - 20;
    /* case CS_P: */
    /*   return TAPPING_TERM + 12; */
    default:
      return TAPPING_TERM;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  // or with combo index, i.e. its name from enum.
  switch (index) {
    case as_combo:
    case ui_combo:
    case io_combo:
    case uo_combo:

#ifdef PATCOLL_BIG_BAR_COMBOS
    case dsspc_combo:
    case ksspc_combo:
    case fsspc_combo:
    case jsspc_combo:
    case lsspc_combo:
    case ssspc_combo:
    case zsspc_combo:
#endif
      return COMBO_TERM - 12;
  }

  return COMBO_TERM;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_Z:
    case SFT_A:
    case SFT_V:
    case SFT_SPC:
    case SFT_ENT:
    case SFT_SCLN:
    case SFT_QUOT:
    case SFT_SLSH:
    case SFT_DOT:
    case SFT_M:
    case CS_P:
      return true;
    default:
      return false;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* case LT(1, KC_BSPC): */
    /*   // Immediately select the hold action when another key is pressed. */
    /*   return true; */
    default:
      // Do not select the hold action when another key is pressed.
      return false;
  }
}
