#include "patcoll.h"

/* enum combos { */
/*   #<{(| FJ_ZER, |)}># */
/*   #<{(| SCDN_ZER, |)}># */
/*  */
/*   OP_COMBO, */
/*  */
/*   #<{(| QW_COMBO |)}># */
/*   AS_COMBO, */
/*  */
/*   #<{(| YU_COMBO |)}># */
/*   #<{(| SS_COMBO |)}># */
/*  */
/*   DF_COMBO, */
/*  */
/*   FG_COMBO, */
/*  */
/*   GH_COMBO, */
/*  */
/*   #<{(| UI_COMBO, |)}># */
/*   #<{(| SE_COMBO, |)}># */
/*   #<{(| FSE_COMBO, |)}># */
/*   #<{(| MWDU_COMBO, |)}># */
/*  */
/*   JK_COMBO, */
/*   DU_COMBO, */
/*   RBBS_COMBO, */
/*   MUMD_COMBO, */
/*  */
/*   HJ_COMBO, */
/*   LD_COMBO, */
/*   BR_COMBO, */
/*   MLD_COMBO, */
/*  */
/*   JI_COMBO, */
/*   DE_COMBO, */
/*   RBF8_COMBO, */
/*   MDWU_COMBO, */
/*  */
/*   BK_COMBO, */
/*   CU_COMBO, */
/*   CB_COMBO, */
/*   MPU_COMBO, */
/*  */
/*   #<{(| JKL_COMBO, |)}># */
/*   KL_COMBO, */
/*  */
/*   SB_COMBO, */
/*   BN_COMBO, */
/*   CD_COMBO, */
/*  */
/*   #<{(| BNM_COMBO, |)}># */
/*  */
/*   NM_COMBO, */
/*   DS_COMBO, */
/*  */
/*   BM_COMBO, */
/*   CS_COMBO */
/* }; */
/*  */
/* #<{(| const uint16_t PROGMEM fj_zero[] = {KC_F, KC_J, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM scdn_zero[] = {KC_SCLN, KC_DOWN, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END}; |)}># */
/* const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM ss_combo[] = {KC_6, KC_7, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM fg_combo[] = {KC_F, KC_G, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM gh_combo[] = {KC_G, KC_H, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM se_combo[] = {KC_7, KC_8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM fse_combo[] = {KC_F7, KC_F8, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM mwdu_combo[] = {KC_WH_D, KC_WH_U, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM du_combo[] = {KC_DOWN, KC_UP, COMBO_END}; */
/* const uint16_t PROGMEM rbbs_combo[] = {KC_RBRC, KC_BSLS, COMBO_END}; */
/* const uint16_t PROGMEM mumd_combo[] = {KC_MS_U, KC_MS_D, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END}; */
/* const uint16_t PROGMEM ld_combo[] = {KC_LEFT, KC_DOWN, COMBO_END}; */
/* const uint16_t PROGMEM br_combo[] = {KC_LBRC, KC_RBRC, COMBO_END}; */
/* const uint16_t PROGMEM mld_combo[] = {KC_MS_L, KC_MS_D, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM ji_combo[] = {KC_J, KC_I, COMBO_END}; */
/* const uint16_t PROGMEM de_combo[] = {KC_DOWN, KC_8, COMBO_END}; */
/* const uint16_t PROGMEM rbf8_combo[] = {KC_RBRC, KC_F8, COMBO_END}; */
/* const uint16_t PROGMEM mdwu_combo[] = {KC_MS_D, KC_WH_U, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM bk_combo[] = {KC_B, KC_K, COMBO_END}; */
/* const uint16_t PROGMEM cu_combo[] = {KC_COMM, KC_UP, COMBO_END}; */
/* const uint16_t PROGMEM cb_combo[] = {KC_COMM, KC_BSLS, COMBO_END}; */
/* const uint16_t PROGMEM mpu_combo[] = {KC_MPLY, KC_MS_U, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM mk_combo[] = {KC_M, KC_K, COMBO_END}; */
/* #<{(| const uint16_t PROGMEM cu_combo[] = {KC_COMM, KC_UP, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM cb_combo[] = {KC_COMM, KC_BSLS, COMBO_END}; |)}># */
/* #<{(| const uint16_t PROGMEM mpu_combo[] = {KC_MPLY, KC_MS_U, COMBO_END}; |)}># */
/*  */
/* #<{(| const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END}; |)}># */
/* const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM sb_combo[] = {KC_SPC, KC_B, COMBO_END}; |)}># */
/* const uint16_t PROGMEM bn_combo[] = {KC_B, KC_N, COMBO_END}; */
/* const uint16_t PROGMEM cd_combo[] = {KC_COMM, KC_DOT, COMBO_END}; */
/*  */
/* #<{(| const uint16_t PROGMEM bnm_combo[] = {KC_B, KC_N, KC_M, COMBO_END}; |)}># */
/*  */
/* const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END}; */
/* const uint16_t PROGMEM ds_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; */
/*  */
/* const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END}; */
/* const uint16_t PROGMEM cs_combo[] = {KC_COMM, KC_SLSH, COMBO_END}; */
