#pragma once

#include "quantum.h"

void keyboard_post_init_keymap(void);
bool led_update_keymap(led_t led_state);
void matrix_scan_keymap(void);
void pointing_device_init_keymap(void);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
uint32_t startup_detect_os(uint32_t trigger_time, void *cb_arg);

