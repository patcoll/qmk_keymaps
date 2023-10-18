#include "patcoll.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#if defined(COMBO_ENABLE) && defined(COMBO_TERM_PER_COMBO)
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
#endif
