#include "patcoll.h"
#include "callbacks.h"

bool led_update_user(led_t led_state) {
  if (!led_update_keymap(led_state)) {
    return false;
  }

  return true;
}
