#include "patcoll.h"
#include "callbacks.h"
#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
#endif
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

bool mac_mode = false;
bool game_mode = false;

bool is_alt_tab_active = false;
int alt_tab_slight_delay_ms = 120;

static uint32_t key_timer = 0;
static bool key_trigger = false;

/* extern keymap_config_t keymap_config; */

#if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
os_variant_t os_type;

uint32_t startup_detect_os(uint32_t trigger_time, void *cb_arg) {
  if (is_keyboard_master()) {
    os_type = detected_host_os();

    if (os_type) {
      bool is_mac = (os_type == OS_MACOS) || (os_type == OS_IOS);

      set_mac_mode(is_mac);
    }
  }

  return os_type ? 0 : 500;
}
#endif

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
  debug_enable = true;
  /* debug_matrix = true; */
  /* debug_keyboard = true; */
#endif

#if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
  defer_exec(100, startup_detect_os, NULL);
#endif

  keyboard_post_init_keymap();
}

void matrix_scan_user(void) {
  // End fancy nav switching if the NAV layer has been deactivated.
  if (is_alt_tab_active && !IS_LAYER_ON(_NAV)) {
    if (mac_mode) {
      unregister_code(KC_LGUI);
    } else {
      unregister_code(KC_LALT);
    }
    is_alt_tab_active = false;
  }

  // trigger kc_no after timer if option is on
  if (timer_elapsed32(key_timer) > 30000) { // 30 seconds
    key_timer = timer_read32();  // resets timer
    if (key_trigger) tap_code(KC_NO); // tap if enabled
  }

  matrix_scan_keymap();
}

void set_mac_mode(bool is_mac_mode) {
  mac_mode = is_mac_mode;

  keymap_config.raw = eeconfig_read_keymap();
  keymap_config.swap_lalt_lgui = keymap_config.swap_ralt_rgui = mac_mode;
  eeconfig_update_keymap(keymap_config.raw);

#ifdef CONSOLE_ENABLE
  xprintf("mac_mode: %d\n", mac_mode);
#endif
}

void set_game_mode(bool is_game_mode) {
  game_mode = is_game_mode;

  if (game_mode) {
    layer_on(_GAMING);
    /* default_layer_set(1 << _GAMING); */
  } else {
    layer_off(_GAMING);
    /* default_layer_set(1 << _QWERTY); */
  }

#ifdef CONSOLE_ENABLE
  xprintf("game_mode: %d\n", game_mode);
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (keycode == KEY_TIMER) {
      key_trigger = !key_trigger;
      return false;
    }

    if (keycode == GAME_TG) {
      set_game_mode(!game_mode);
      return false;
    }

    if (keycode == MAC_TG) {
      set_mac_mode(!mac_mode);
      return false;
    }

    if (keycode == C_CUT) {
      mac_mode == true ? tap_code16(G(KC_X)) : tap_code16(C(KC_X));
      return false;
    }

    if (keycode == C_COPY) {
      mac_mode == true ? tap_code16(G(KC_C)) : tap_code16(C(KC_C));
      return false;
    }

    if (keycode == C_PASTE) {
      mac_mode == true ? tap_code16(G(KC_V)) : tap_code16(C(KC_V));
      return false;
    }

    if (keycode == OS_MENU) {
      mac_mode == true ? tap_code16(G(KC_SPC)) : tap_code16(A(KC_SPC));
      return false;
    }

    if (keycode == CLS_WIN) {
      mac_mode == true ? tap_code16(G(KC_W)) : tap_code16(A(KC_F4));
      return false;
    }

    if (keycode == CEN_WIN) {
      mac_mode == true ? tap_code16(G(A(KC_C))) : tap_code16(S(C(A(KC_C))));
      return false;
    }

    if (keycode == GO_BACK) {
      mac_mode == true ? tap_code16(G(KC_LBRC)) : tap_code16(A(KC_LEFT));
      return false;
    }

    if (keycode == GO_FWD) {
      mac_mode == true ? tap_code16(G(KC_RBRC)) : tap_code16(A(KC_RGHT));
      return false;
    }

    if (keycode == WIN_HIDE) {
      mac_mode == true ? tap_code16(G(KC_H)) : tap_code16(G(KC_PGDN));
      return false;
    }

    if (keycode == WIN_MAX) {
      mac_mode == true ? tap_code16(S(C(G(A(KC_F))))) : tap_code16(G(KC_PGUP));
      return false;
    }

    if (keycode == SCR_SHT) {
      mac_mode == true ? tap_code16(S(G(KC_3))) : tap_code16(S(KC_PSCR));
      return false;
    }

    if (keycode == SCR_WIN) {
      mac_mode == true ? tap_code16(S(G(KC_4))) : tap_code16(G(S(KC_PSCR)));
      return false;
    }

    if (keycode == SCR_LCK) {
      mac_mode == true ? tap_code16(C(G(KC_Q))) : tap_code16(C(G(A(S(KC_L)))));
      return false;
    }

    if (keycode >= EX_PIPE && keycode <= EX_SEAR) {
      switch (keycode) {
        case EX_PIPE:
          SEND_STRING("|>");
          break;
        case EX_BARR:
          SEND_STRING("<-");
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
          if (mac_mode) {
            register_code(KC_LGUI);
          } else {
            register_code(KC_LALT);
          }
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
