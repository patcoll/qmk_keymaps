#include "embrace.h"
void matrix_init_kb(void) {
  matrix_init_user();
}
void matrix_scan_kb(void) {
  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  /* led_set_user(usb_led); */
}

bool led_update_kb(led_t led_state) {
  return false;

  bool res = led_update_user(led_state);

  /* if (res) { */
  /* } */

  return res;
}
