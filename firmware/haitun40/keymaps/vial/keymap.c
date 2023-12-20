#include QMK_KEYBOARD_H

#include "quantum.h"

#include "dynamic_keymap.h"
#include "uart.h"
#include "outputselect.h"

#include "hal_pal.h"
#include "actionuart.h"
#include "powermstop.h"


enum layers {
    CAP_KEY_LED_INDEX = 7,
    _FL
};


enum keyboard_keycodes {
    SHOW_LED_IND,              // delete current ble bound
    BLE_CLR,              // delete all ble bound
    NEW_SAFE_RANGE  // Important!
};


#define VIAL_RESET     KC_F16 
#define BL_SW_1     KC_F23  // 开启蓝牙通道1（需要打开蓝牙的条件下才行）
#define BL_SW_2     KC_F19  // 开启蓝牙通道2（需要打开蓝牙的条件下才行）
#define BL_SW_3     KC_F20  // BLE3
#define RADIO      KC_F18  // RADIO
#define BLE_RESET     KC_F24
#define BLE_DEL     KC_F22  // 删除当前蓝牙绑定
#define BL_DFU     KC_F21  //
#define BAU_TOG     KC_F17  // 蓝牙和USB之间切换
#define ADC_RGB_SHOW     KC_F14  // Show BAT Power

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  { \
       { KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,      KC_LBRC,   KC_RBRC}, \
       {KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,   KC_QUOT,   KC_ENT}, \
       {KC_LSFT,  KC_BSLS,   KC_Z, KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,   KC_SLSH,   KC_RSFT}, \
       {KC_NO,  KC_LGUI, KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,   MO(1),   KC_RCTL,   KC_NO} \
 },
  { \
       { BAU_TOG,  BLE_DEL,   BLE_RESET,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET}, \
       { KC_NO,    BL_SW_1,   BL_SW_2,     BL_SW_3,   RADIO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO}, \
       { HPT_ON,   KC_NO,     KC_NO,       KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   VIAL_RESET}, \
       { ADC_RGB_SHOW,  ADC_RGB_SHOW,     KC_NO,       KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO} \
 }
};


void Stm32_Rest2(void) {


    __set_FAULTMASK(1);
    NVIC_SystemReset();
}






#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        { 0,  1,     2,  3,      4,  5,      6,      7,      8,      9,  10,  11,   12,      13 },
        { 14, 15,    16, 17,     18, 19,     20,     21,     22,     23, 24,  25,   26,      27 },
        { 28 ,29,    30, 31,     32, 33,     34,     35,     36,     37, 38,  39,   NO_LED,  40 },
        { 41, 42,    43, 44,     45, 46,     47,     48,     49,     50, 51,  52,   53,      54 },
        { 55, 56,    57, 58,  NO_LED,NO_LED, NO_LED, NO_LED, NO_LED, 59, 60,  61,   62,      63 }
    }, {
        { 216,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 }, { 144,   0 }, { 128,   0 }, { 112,   0 }, {  96,   0 }, {  80,   0 }, {  64,   0 }, {  48,   0 }, {  32,   0 }, {  16,   0 }, {   0,   0 },
        { 220,  16 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 }, {   4,  16 },
        { 214,  32 }, { 188,  32 }, { 172,  32 }, { 156,  32 }, { 140,  32 }, { 124,  32 }, { 108,  32 }, {  92,  32 }, {  76,  32 }, {  60,  32 }, {  44,  32 }, {  28,  32 },               {   6,  32 },
        { 224,  48 }, { 218,  48 }, { 192,  48 }, { 176,  48 }, { 160,  48 }, { 144,  48 }, { 128,  48 }, { 112,  48 }, {  96,  48 },{80, 48},  {  64,  48 }, {  48,  48 }, {  32,  48 }, {   8,  48 },
        { 224,  64 }, { 208,  64 }, { 192,  64 },                                           { 176,  64 },                             { 160,  64 }, { 102,  64 }, {  42,  64 }, {  22,  64 }, {   2,  64 }
    }, {
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 1, 1,          1,       1, 1, 1, 1, 1
    }
};


#endif
