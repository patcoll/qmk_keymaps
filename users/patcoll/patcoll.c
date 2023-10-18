#include "patcoll.h"
#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
#endif
#include "print.h"

bool mac_mode = false;
bool game_mode = false;

bool is_alt_tab_active = false;
int alt_tab_slight_delay_ms = 120;

static uint32_t key_timer = 0;
static bool key_trigger = false;

/* extern keymap_config_t keymap_config; */

// KEY OVERRIDES

#ifdef KEY_OVERRIDE_ENABLE
// clang-format off

#define ko_make_with_layers_negmods_and_enabled(trigger_mods_, trigger_key, replacement_key, layer_mask, negative_mask, enabled_) \
    ((const key_override_t){                                                                \
        .trigger_mods                           = (trigger_mods_),                          \
        .layers                                 = (layer_mask),                             \
        .suppressed_mods                        = (trigger_mods_),                          \
        .options                                = ko_options_default,                       \
        .negative_mod_mask                      = (negative_mask),                          \
        .custom_action                          = NULL,                                     \
        .context                                = NULL,                                     \
        .trigger                                = (trigger_key),                            \
        .replacement                            = (replacement_key),                        \
        .enabled                                = (enabled_)                                \
    })

#define ko_make_with_options(trigger_mods_, trigger_key, replacement_key, options_)         \
    ((const key_override_t){                                                                \
        .trigger_mods                           = (trigger_mods_),                          \
        .layers                                 = ~0,                                       \
        .suppressed_mods                        = (trigger_mods_),                          \
        .options                                = (options_),                               \
        .negative_mod_mask                      = 0,                                        \
        .custom_action                          = NULL,                                     \
        .context                                = NULL,                                     \
        .trigger                                = (trigger_key),                            \
        .replacement                            = (replacement_key),                        \
        .enabled                                = NULL                                      \
    })

// clang-format on

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);

const key_override_t word_move_ov_left = ko_make_with_layers_negmods_and_enabled(MOD_MASK_CTRL, KC_LEFT, LALT(KC_LEFT), (1 << _MAC), MOD_MASK_SG, NULL);
const key_override_t word_move_ov_down = ko_make_with_layers_negmods_and_enabled(MOD_MASK_CTRL, KC_DOWN, LALT(KC_DOWN), (1 << _MAC), MOD_MASK_SG, NULL);
const key_override_t word_move_ov_up = ko_make_with_layers_negmods_and_enabled(MOD_MASK_CTRL, KC_UP, LALT(KC_UP), (1 << _MAC), MOD_MASK_SG, NULL);
const key_override_t word_move_ov_right = ko_make_with_layers_negmods_and_enabled(MOD_MASK_CTRL, KC_RGHT, LALT(KC_RGHT), (1 << _MAC), MOD_MASK_SG, NULL);

// This is called when the override activates and deactivates. Enable the fn
// layer on activation and disable on deactivation
/* bool momentary_alt(bool key_down, void *nothing) { */
/*   if (key_down) { */
/*     #<{(| layer_on((uint8_t)(uintptr_t)layer); |)}># */
/*     register_code(KC_LALT); */
/*   } else { */
/*     #<{(| layer_off((uint8_t)(uintptr_t)layer); |)}># */
/*     unregister_code(KC_LALT); */
/*   } */
/*  */
/*   return false; */
/* } */
/* const key_override_t word_move_override = { */
/*   .trigger_mods      = MOD_BIT(KC_LCTL), */
/*   .layers            = ~(1 << _NAV), */
/*   .suppressed_mods   = MOD_BIT(KC_LCTL), */
/*   .options           = ko_option_activation_required_mod_down | ko_option_no_unregister_on_other_key_down, */
/*   .negative_mod_mask = ~MOD_BIT(KC_LCTL), */
/*   .custom_action     = momentary_alt, */
/*   #<{(| .context           = NULL, |)}># */
/*   .trigger           = KC_NO, */
/*   #<{(| .replacement       = MOD_BIT(KC_LALT), |)}># */
/*   .replacement       = KC_NO, */
/*   .enabled           = NULL */
/* }; */

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
  &delete_key_override,
  &word_move_ov_left,
  &word_move_ov_up,
  &word_move_ov_down,
  &word_move_ov_right,
  NULL // Null terminate the array of overrides!
};
#endif

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) bool led_update_keymap(led_t led_state) {
    return true;
}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) {
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) void pointing_device_init_keymap(void) {}

#if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
uint32_t startup_exec(uint32_t trigger_time, void *cb_arg);
#endif

#if defined(OS_DETECTION_ENABLE) && defined(DEFERRED_EXEC_ENABLE)
os_variant_t os_type;

uint32_t startup_exec(uint32_t trigger_time, void *cb_arg) {
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

#ifdef DEFERRED_EXEC_ENABLE
  defer_exec(100, startup_exec, NULL);
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
      mac_mode == true ? tap_code16(G(A(KC_F))) : tap_code16(G(KC_PGUP));
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

bool led_update_user(led_t led_state) {
  if (!led_update_keymap(led_state)) {
    return false;
  }

  return true;
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
    /* case SFT_SPC: */
    case SFT_ENT:
    case SFT_A:
    case SFT_V:
      return TAPPING_TERM - 12;
    case SFT_Z:
    case SFT_DOT:
    case SFT_SLSH:
      return TAPPING_TERM - 20;
    case CTL_A:
    case CS_NO:
    case CA_OSK:
      return TAPPING_TERM + 150;
    case GUI_X:
    case ALT_C:
      return TAPPING_TERM + 220;
    default:
      return TAPPING_TERM;
  }
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
      /* return true; */
    default:
      // Do not select the hold action when another key is pressed.
      return false;
  }
}
