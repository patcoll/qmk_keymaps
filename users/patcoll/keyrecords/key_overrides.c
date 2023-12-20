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
