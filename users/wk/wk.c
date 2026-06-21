// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Universal keymap. LAYOUT_wk is defined per-keyboard in config.h.
// Parameter order:
//   number row: N00 N01 N02 N03 N04 N05  N06 N07 N08 N09 N0A N0B
//   upper row:  L00 L01 L02 L03 L04 L05  R00 R01 R02 R03 R04 R05
//   home row:   L10 L11 L12 L13 L14 L15  R10 R11 R12 R13 R14 R15
//   bottom row: L20 L21 L22 L23 L24 L25  R20 R21 R22 R23 R24 R25
//   thumbs:                 L30 L31 L32  R30 R31 R32
//
// Keyboards without a number row (e.g. corne) ignore N00-N0B in their macro.

#include "wk.h"

const uint16_t PROGMEM copy_combo[]        = { KC_COMM, KC_DOT,           COMBO_END };
const uint16_t PROGMEM shift_copy_combo[]  = { KC_QUOT, KC_COMM, KC_DOT,  COMBO_END };
const uint16_t PROGMEM paste_combo[]       = { KC_DOT,  KC_SCLN,          COMBO_END };
const uint16_t PROGMEM shift_paste_combo[] = { KC_COMM, KC_DOT,  KC_SCLN, COMBO_END };
const uint16_t PROGMEM cut_combo[] = { KC_QUOT, KC_COMM, COMBO_END };
const uint16_t PROGMEM undo_combo[] = { KC_SCLN, KC_SLSH, COMBO_END };

combo_t key_combos[] = {
    COMBO(copy_combo,        C(KC_C)),
    COMBO(shift_copy_combo,  LCS(KC_C)),
    COMBO(paste_combo,       C(KC_V)),
    COMBO(shift_paste_combo, LCS(KC_V)),
    COMBO(cut_combo, C(KC_X)),
    COMBO(undo_combo, C(KC_Z)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ENTHIUM] = LAYOUT_wk(
    // number row
    KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,  KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
    // upper
    KC_TAB,  KC_Q,         KC_Y,         KC_O,          KC_U,          KC_EQL,
    KC_X,    KC_L,         KC_D,         KC_W,          KC_Z,          KC_BSPC,
    // home
    KC_B,    LGUI_T(KC_C), LALT_T(KC_I), LSFT_T(KC_A),  LCTL_T(KC_E),  KC_MINS,
    KC_K,    RCTL_T(KC_H), RSFT_T(KC_T), RALT_T(KC_N),  RGUI_T(KC_S),  KC_F,
    // bottom
    OS_LSFT, KC_QUOT,      KC_COMM,      KC_DOT,        KC_SCLN,       KC_SLSH,
    KC_J,    KC_M,         KC_G,         KC_P,          KC_V,          OS_RSFT,
    // thumbs
    LT(_FUN, KC_DEL), LT(_NAV, KC_ESC), LT(_SYM, KC_SPC),
    KC_R,           LT(_NUM, KC_ENT),   KC_BSPC
),

[_GAME] = LAYOUT_wk(
    // number row
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,  KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
    // upper
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_Y,    KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    // home
    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_H,    KC_J, KC_K, KC_L, KC_QUOT, KC_SCLN,
    // bottom
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,
    KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    // thumbs
    LT(_NAV, KC_DEL), KC_SPC,    LT(_SYM, KC_ESC),
    OSL(_NUM),    MO(_NAV),  KC_BSPC
),

[_QWERTY] = LAYOUT_wk(
    // number row
    KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5,  KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
    // upper
    KC_TAB,  KC_Q,         KC_W,         KC_E,          KC_R,          KC_T,
    KC_Y,    KC_U,         KC_I,         KC_O,          KC_P,          KC_BSPC,
    // home
    KC_ESC,  LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D),  LCTL_T(KC_F),  KC_G,
    KC_H,    RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L),  RGUI_T(KC_QUOT), KC_SCLN,
    // bottom
    KC_NO,   KC_Z, KC_X, KC_C, KC_V, KC_B,
    KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    // thumbs
    LT(_FUN, KC_DEL), LT(_NAV, KC_ESC), LT(_SYM, KC_SPC),
    KC_R,           LT(_NUM, KC_ENT),   KC_BSPC
),

[_NAV] = LAYOUT_wk(
    // number row
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // upper
    KC_TAB,  QK_BOOT,      DF(_QWERTY),  DF(_GAME),     DF(_ENTHIUM),  KC_NO,
    C(KC_Y), C(KC_LEFT),   C(KC_C),      C(KC_V),       C(KC_RGHT),    KC_NO,
    // home
    KC_NO,   KC_LGUI,      KC_LALT,      KC_LSFT,       KC_LCTL,       KC_NO,
    CW_CAPS, KC_LEFT,      KC_DOWN,      KC_UP,         KC_RGHT,       KC_NO,
    // bottom
    KC_NO,   C(KC_Z),      C(KC_X),      C(KC_C),       C(KC_V),       KC_NO,
    KC_INS,  KC_HOME,      KC_PGDN,      KC_PGUP,       KC_END,        KC_ENT,
    // thumbs
    KC_NO, KC_NO, KC_NO,
    KC_NO, KC_BSPC, KC_DEL
),

[_SYM] = LAYOUT_wk(
    // number row
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // upper
    KC_DLR,  KC_GRV,  KC_TILD, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_NO,  C(KC_H),   C(KC_J),   C(KC_K),   C(KC_L),   KC_NO,
    // home
    KC_PERC,   KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_HASH,
    KC_NO, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_NO,
    // bottom
    KC_CIRC,  KC_BSLS, KC_AMPR, KC_LBRC, KC_RBRC, KC_ASTR,
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,
    // thumbs
    KC_NO, KC_SPC, KC_NO,
    KC_SPC, KC_NO, KC_BSPC
),

[_NUM] = LAYOUT_wk(
    // number row
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // upper
    KC_TAB,  KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS,
    KC_NO,   DF(_QWERTY), DF(_GAME), KC_NO, QK_BOOT, KC_NO,
    // home
    KC_NO,   KC_0,    KC_4, KC_5, KC_6, KC_EQL,
    KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
    // bottom
    KC_NO,   KC_SLSH, KC_1, KC_2, KC_3, KC_MINS,
    KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_ENT,
    // thumbs
    KC_DOT, KC_SPC, KC_ESC,
    KC_NO,  KC_NO,  KC_NO
),

[_FUN] = LAYOUT_wk(
    // number row
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // upper
    KC_TAB,  KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,
    KC_NO,   DF(_QWERTY), DF(_GAME), KC_NO, QK_BOOT, KC_NO,
    // home
    KC_NO,   KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,
    KC_VOLU, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
    // bottom
    KC_NO,   KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,
    KC_VOLD, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, KC_ENT,
    // thumbs
    KC_APP, KC_SPC, KC_ESC,
    KC_NO,  KC_NO,  KC_NO
),
};
