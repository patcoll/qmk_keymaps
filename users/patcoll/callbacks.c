#include "callbacks.h"

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) bool led_update_keymap(led_t led_state) {
    return true;
}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) void pointing_device_init_keymap(void) {}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) uint32_t startup_detect_os(uint32_t trigger_time, void *cb_arg) {
    return 0;
}
