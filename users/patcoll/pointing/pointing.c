#include "quantum.h"
#include "callbacks.h"

void pointing_device_init_user(void) {
  // set default pointing device resolution
  pointing_device_set_cpi(400);

  pointing_device_init_keymap();
}
