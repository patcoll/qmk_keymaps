#include "patcoll.h"

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_SPC:
    /* case SFT_ENT: */
    /* case SFT_A: */
    /* case SFT_V: */
      return TAPPING_TERM - 12;
    case SFT_Z:
    case SFT_DOT:
    case SFT_SLSH:
      return TAPPING_TERM - 20;
    case CTL_A:
    case CTL_L:
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
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Shift
    case SFT_Z:
    /* case SFT_A: */
    /* case SFT_V: */
    case SFT_SPC:
    /* case SFT_ENT: */
    /* case SFT_SCLN: */
    case SFT_QUOT:
    case SFT_SLSH:
    case SFT_DOT:
    /* case SFT_M: */
    /* case CS_P: */
      return true;
    default:
      return false;
  }
}
#endif
