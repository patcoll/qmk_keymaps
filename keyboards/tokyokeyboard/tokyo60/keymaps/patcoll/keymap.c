#include QMK_KEYBOARD_H

/* #define BL 0 */
/* #define FN 1 */
/* #define NV 2 */
/* #define MS 3 */
/* #<{(| */
/*  * Default HHKB Layout */
/*  |)}># */
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* [BL] = LAYOUT_60_hhkb( */
/*         KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL, \ */
/*         LT(NV, KC_TAB), LT(MS, KC_Q), KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,      \ */
/*         LCTL_T(KC_ESC), KC_A,         KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,      \ */
/*         KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(FN), \ */
/*                KC_LALT, KC_LGUI,              KC_SPC,                         KC_RCTL, KC_RALT ), */
/*  */
/* [FN]= LAYOUT_60_hhkb( */
/*        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,  KC_F12,  KC_INS,  KC_DEL, \ */
/*        KC_CAPS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS,   KC_UP,   KC_TRNS, KC_TRNS,  \ */
/*        KC_TRNS, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT,   KC_RGHT,          KC_PENT,       \ */
/*        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN,   KC_DOWN,          KC_TRNS, KC_TRNS, \ */
/*                 KC_TRNS, KC_TRNS,                   KC_TRNS   ,                         KC_TRNS, KC_TRNS ), */
/*  */
/* [NV]= LAYOUT_60_hhkb( */
/*        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \ */
/*        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,       \ */
/*        _______,          _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______,          _______, _______, \ */
/*                 _______, _______,                   _______,                            _______, _______ ), */
/*  */
/* [MS]= LAYOUT_60_hhkb( */
/*        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  \ */
/*        _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,          _______,       \ */
/*        _______,          _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  _______,          _______, _______, \ */
/*                 _______, _______,                   KC_BTN1,                            KC_BTN3, KC_BTN2 ), */
/*  */
/* }; */


#define CTL_ESC LCTL_T(KC_ESC)
#define CTL_ENT LCTL_T(KC_ENT)
#define SFT_ESC MT(MOD_LSFT, KC_ESC)
#define SFT_TAB MT(MOD_LSFT, KC_TAB)
#define SFT_SLSH MT(MOD_LSFT, KC_SLSH)

#define SFT_SPC MT(MOD_LSFT, KC_SPC)

/* #define LT1_ENT LT(_RAISE, KC_ENT) */
#define LT1_W LT(1, KC_W)
#define LT1_Z LT(1, KC_Z)

#define LT1_BSPC LT(_RAISE, KC_BSPC)
#define LT2_SPC LT(_LOWER, KC_SPC)
#define LT3_TAB LT(_NAV, KC_TAB)
#define LT4_Q   LT(_MOUSE, KC_Q)

#define CTL_Q   LCTL_T(KC_Q)
#define ALT_SLS   LALT_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_60_hhkb(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSLS,     KC_DEL,
        SFT_TAB,CTL_Q,  LT1_W,  KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSPC,
        CTL_ESC,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     KC_ENT,
        SFT_ESC,LT1_Z,  KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, ALT_SLS,KC_RSFT,     MO(1),
                KC_LGUI,KC_LALT,                KC_SPC,                         KC_RALT,KC_RCTL
    ),
  [1] = LAYOUT_60_hhkb(
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     _______,
        _______,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,_______,_______,
        _______,KC_VOLD,KC_VOLU,KC_MPLY,_______,_______,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,KC_HOME,KC_PGDN,KC_PGUP,KC_END,_______,_______,     _______,
                RESET,  _______,                _______,                _______,_______
    )
};

#ifdef COMBO_ENABLE
enum combos {
  /* FJ_ZER, */
  /* SCDN_ZER, */

  OP_COMBO,

  QW_COMBO,
  AS_COMBO,

  /* YU_COMBO */
  /* SS_COMBO */

  DF_COMBO,

  FG_COMBO,

  GH_COMBO,

  /* UI_COMBO, */
  /* SE_COMBO, */
  /* FSE_COMBO, */
  /* MWDU_COMBO, */

  JK_COMBO,
  DU_COMBO,
  RBBS_COMBO,
  MUMD_COMBO,

  HJ_COMBO,
  LD_COMBO,
  BR_COMBO,
  MLD_COMBO,

  JI_COMBO,
  DE_COMBO,
  RBF8_COMBO,
  MDWU_COMBO,

  BK_COMBO,
  CU_COMBO,
  CB_COMBO,
  MPU_COMBO,

  MK_COMBO,
  UL_COMBO,

  /* JKL_COMBO, */
  KL_COMBO,

  SB_COMBO,
  BN_COMBO,
  CD_COMBO,

  /* BNM_COMBO, */

  NM_COMBO,
  DS_COMBO,

  BM_COMBO,
  CS_COMBO
};

/* const uint16_t PROGMEM fj_zero[] = {KC_F, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM scdn_zero[] = {KC_SCLN, KC_DOWN, COMBO_END}; */

const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};

/* const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END}; */
/* const uint16_t PROGMEM ss_combo[] = {KC_6, KC_7, COMBO_END}; */

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END};

const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END};

/* const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END}; */
/* const uint16_t PROGMEM se_combo[] = {KC_7, KC_8, COMBO_END}; */
/* const uint16_t PROGMEM fse_combo[] = {KC_F7, KC_F8, COMBO_END}; */
/* const uint16_t PROGMEM mwdu_combo[] = {KC_WH_D, KC_WH_U, COMBO_END}; */

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM rbbs_combo[] = {KC_RBRC, KC_BSLS, COMBO_END};
const uint16_t PROGMEM mumd_combo[] = {KC_MS_U, KC_MS_D, COMBO_END};

const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM ld_combo[] = {KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM br_combo[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM mld_combo[] = {KC_MS_L, KC_MS_D, COMBO_END};

const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM de_combo[] = {KC_DOWN, KC_8, COMBO_END};
const uint16_t PROGMEM rbf8_combo[] = {KC_RBRC, KC_F8, COMBO_END};
const uint16_t PROGMEM mdwu_combo[] = {KC_MS_D, KC_WH_U, COMBO_END};

const uint16_t PROGMEM bk_combo[] = {KC_B, KC_K, COMBO_END};
const uint16_t PROGMEM cu_combo[] = {KC_COMM, KC_UP, COMBO_END};
const uint16_t PROGMEM cb_combo[] = {KC_COMM, KC_BSLS, COMBO_END};
const uint16_t PROGMEM mpu_combo[] = {KC_MPLY, KC_MS_U, COMBO_END};

const uint16_t PROGMEM mk_combo[] = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM ul_combo[] = {KC_UP, KC_LBRC, COMBO_END};

/* const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END}; */
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};

/* const uint16_t PROGMEM sb_combo[] = {KC_SPC, KC_B, COMBO_END}; */
const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END};

/* const uint16_t PROGMEM bnm_combo[] = {KC_B, KC_N, KC_M, COMBO_END}; */

const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM cs_combo[] = {KC_COMM, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [OP_COMBO] = COMBO(op_combo, KC_BSPC),

  [QW_COMBO] = COMBO(qw_combo, KC_TAB),

  [AS_COMBO] = COMBO(as_combo, KC_TAB),

  /* [YU_COMBO] = COMBO(yu_combo, KC_ESC), */
  /* [SS_COMBO] = COMBO(ss_combo, KC_ESC), */

  [DF_COMBO] = COMBO(df_combo, KC_SCLN),

  [FG_COMBO] = COMBO(fg_combo, KC_MINS),

  [GH_COMBO] = COMBO(gh_combo, KC_EQL),

  /* [UI_COMBO] = COMBO(ui_combo, KC_ESC), */
  /* [SE_COMBO] = COMBO(se_combo, KC_ESC), */
  /* [FSE_COMBO] = COMBO(fse_combo, KC_ESC), */
  /* [MWDU_COMBO] = COMBO(mwdu_combo, KC_ESC), */

  [JK_COMBO] = COMBO(jk_combo, KC_ESC),
  [DU_COMBO] = COMBO(du_combo, KC_ESC),
  [RBBS_COMBO] = COMBO(rbbs_combo, KC_ESC),
  [MUMD_COMBO] = COMBO(mumd_combo, KC_ESC),

  [HJ_COMBO] = COMBO(hj_combo, KC_ENT),
  [LD_COMBO] = COMBO(ld_combo, KC_ENT),
  [BR_COMBO] = COMBO(br_combo, KC_ENT),
  [MLD_COMBO] = COMBO(mld_combo, KC_ENT),

  [JI_COMBO] = COMBO(ji_combo, KC_ENT),
  [DE_COMBO] = COMBO(de_combo, KC_ENT),
  [RBF8_COMBO] = COMBO(rbf8_combo, KC_ENT),
  [MDWU_COMBO] = COMBO(mdwu_combo, KC_ENT),

  [BK_COMBO] = COMBO(bk_combo, KC_ENT),
  [CU_COMBO] = COMBO(cu_combo, KC_ENT),
  [CB_COMBO] = COMBO(cb_combo, KC_ENT),
  [MPU_COMBO] = COMBO(mpu_combo, KC_ENT),

  [MK_COMBO] = COMBO(mk_combo, KC_ENT),
  [UL_COMBO] = COMBO(ul_combo, KC_ENT),

  /* [JKL_COMBO] = COMBO(jkl_combo, KC_SCLN), */
  [KL_COMBO] = COMBO(kl_combo, KC_QUOT),

  [BN_COMBO] = COMBO(bn_combo, KC_COMM),
  [CD_COMBO] = COMBO(cd_combo, KC_COMM),

  [NM_COMBO] = COMBO(nm_combo, KC_DOT),
  [DS_COMBO] = COMBO(ds_combo, KC_DOT),

  [BM_COMBO] = COMBO(bm_combo, KC_SLSH),
  [CS_COMBO] = COMBO(cs_combo, KC_SLSH)
};
#endif // COMBO_ENABLE
