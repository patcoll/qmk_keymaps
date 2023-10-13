#include "patcoll.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_wrapper(
  QK_BOOT, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______
),
};
