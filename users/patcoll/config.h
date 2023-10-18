#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 174
#define TAPPING_TOGGLE 2
#define TAPPING_TERM_PER_KEY
// #define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Mouse key speed and acceleration.
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      5
#define MOUSEKEY_TIME_TO_MAX    64

// Combos
#ifdef COMBO_ENABLE
#define COMBO_TERM 33
#define EXTRA_SHORT_COMBOS
#define COMBO_TERM_PER_COMBO
#endif // COMBO_ENABLE

#ifdef AUTO_SHIFT_ENABLE
#define AUTO_SHIFT_TIMEOUT 175
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_ALPHA
#endif

// Only define combos for alpha keyboard. This def will be found there.
#undef PATCOLL_ALPHA_COMBOS

// Only define combos for big bar keyboards. This def will be found in big bar keymaps.
#undef PATCOLL_BIG_BAR_COMBOS

// Ricing
// #define USB_POLLING_INTERVAL_MS 2
// #define QMK_KEYS_PER_SCAN 10
// #define FORCE_NKRO

// RGBLight
#ifdef RGBLIGHT_ENABLE
#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 1
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 2
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 5

#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE
#endif

// RGB Matrix
// RGB_Matrix settings
#ifdef RGB_MATRIX_ENABLE
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  // #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
  #undef RGB_DISABLE_WHEN_USB_SUSPENDED
  #define RGB_DISABLE_WHEN_USB_SUSPENDED true // turn off effects when suspended
  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
  #undef RGB_MATRIX_HUE_STEP
  #define RGB_MATRIX_HUE_STEP 1
  #undef RGB_MATRIX_SAT_STEP
  #define RGB_MATRIX_SAT_STEP 1
  #undef RGB_MATRIX_VAL_STEP
  #define RGB_MATRIX_VAL_STEP 1
  #undef RGB_MATRIX_SPD_STEP
  #define RGB_MATRIX_SPD_STEP 10

  #define ENABLE_RGB_MATRIX_SOLID_COLOR

  // #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
  /* Disable the animations you don't want/need.  You will need to disable a good number of these
    because they take up a lot of space.  Disable until you can successfully compile your firmware. */

  // #define DISABLE_RGB_MATRIX_ALPHAS_MODS
  // #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  // #define DISABLE_RGB_MATRIX_BREATHING
  // #define DISABLE_RGB_MATRIX_CYCLE_ALL
  // #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  // #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
  // #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
  // #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  // #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  // #define DISABLE_RGB_MATRIX_DUAL_BEACON
  // #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
  // #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  // // #define DISABLE_RGB_MATRIX_RAINDROPS
  // #define DISABLE_RGB_MATRIX_JELLYBEN_RAINDROPS
  // #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
  // #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
  // // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  // // #define DISABLE_RGB_MATRIX_SPLASH
  // #define DISABLE_RGB_MATRIX_MULTISPLASH
  // #define DISABLE_RGB_MATRIX_SOLID_SPLASH
  // #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif //RGB_MATRIX_ENABLE

#undef TAP_CODE_DELAY
#define TAP_CODE_DELAY 5

#ifdef SPLIT_KEYBOARD
#  define OLED_UPDATE_INTERVAL 60
#else
#  define OLED_UPDATE_INTERVAL 15
#endif

#ifdef LOCKING_SUPPORT_ENABLE
#  undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#  undef LOCKING_RESYNC_ENABLE
#endif

// Hex size reduction options
#ifndef NO_DEBUG
  #define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
  #define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_ONESHOT

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
