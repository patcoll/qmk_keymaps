#include "patcoll.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#if defined(COMBO_ENABLE) && defined(COMBO_TERM_PER_COMBO)
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  // or with combo index, i.e. its name from enum.
  switch (index) {
    // Make these combos slightly easier to trigger.
    //
    // Do this for any combo letter combinations that may NOT be more prevalent
    // in everyday typing.
    case jk_combo:
      return COMBO_TERM + 8;

    case mk_combo:
      return COMBO_TERM + 3;

    // Make these combos slightly harder to trigger. In other words, you must
    // trigger all keys together more quickly.
    //
    // Do this for any combo letter combinations that may be more prevalent in
    // everyday typing.
    case as_combo:
    case ui_combo:
    case io_combo:
    case uo_combo:

    case dv_combo:
    case db_combo:

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

    // Make this much harder to trigger, since it's a common letter combo.
    case af_combo:
    case av_combo:
      return COMBO_TERM - 17;

  }

  return COMBO_TERM;
}
#endif

#if defined(COMBO_ENABLE) && defined(COMBO_SHOULD_TRIGGER)
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  // turn off all combos except the one to turn off gaming layer.
  if (layer_state_is(_GAMING)) {
    switch (combo_index) {
      // game mode
      case qpfj_combo:
      case cqpfj_combo:
      // click
      case dc_combo:
      case dv_combo:
      case fv_combo:
      case fb_combo:
      case db_combo:
        return true;
      default:
        return false;
    }
  }

  return true;
}
#endif
