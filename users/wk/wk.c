// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Universal keymap. LAYOUT_wk is defined per-keyboard in config.h.
// Parameter order:
//   number row: N00 N01 N02 N03 N04 N05  N06 N07 N08 N09 N0A N0B
//   upper row:  L00 L01 L02 L03 L04 L05  R00 R01 R02 R03 R04 R05
//   home row:   L10 L11 L12 L13 L14 L15  R10 R11 R12 R13 R14 R15
//   bottom row: L20 L21 L22 L23 L24 L25  R20 R21 R22 R23 R24 R25
//   row 5:         XL0 XL1                  XR0 XR1
//   thumbs:                 L30 L31 L32  R30 R31 R32
//
// Keyboards without a number row (e.g. corne) ignore N00-N0B in their macro.
// Row 5 is the dactyl's inner-bottom keys under the ring/middle fingers
// (XL0 left ring, XL1 left middle, XR0 right middle, XR1 right ring); corne and
// sofle have no such keys and discard XL0/XL1/XR0/XR1 in their macros.

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
    // row 5 (dactyl inner-bottom; mirrored parens/brackets. discarded on corne/sofle)
    KC_LPRN, KC_RPRN,   KC_LBRC, KC_RBRC,
    // thumbs
    LT(_FUN, KC_DEL), LT(_NAV, KC_SPC), KC_ESC,
    LT(_SYM, KC_ENT), LT(_NUM, KC_R),   KC_NO
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
    // row 5
    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    // thumbs
    LT(_NAV, KC_DEL), KC_SPC,    LT(_SYM, KC_ESC),
    OSL(_NUM),    MO(_NAV),  KC_BSPC
),

[_NAV] = LAYOUT_wk(
    // number row
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // upper
    KC_TAB,  QK_BOOT,      KC_NO,  DF(_GAME),     DF(_ENTHIUM),  KC_NO,
    C(KC_Y), C(KC_LEFT),   C(KC_C),      C(KC_V),       C(KC_RGHT),    KC_NO,
    // home
    KC_NO,   KC_LGUI,      KC_LALT,      KC_LSFT,       KC_LCTL,       KC_NO,
    CW_CAPS, KC_LEFT,      KC_DOWN,      KC_UP,         KC_RGHT,       KC_NO,
    // bottom
    KC_NO,   C(KC_Z),      C(KC_X),      C(KC_C),       C(KC_V),       KC_NO,
    KC_INS,  KC_HOME,      KC_PGDN,      KC_PGUP,       KC_END,        KC_ENT,
    // row 5
    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    // thumbs
    KC_NO, KC_NO, KC_NO,
    KC_NO, KC_BSPC, KC_DEL
),

// Symbol layer, adapted from Sunaku's Glove80 "Symbol Layer" (Glorious Engrammer,
// https://sunaku.github.io/moergo-glove80-keyboard.html). The left hand holds the
// symbols; the right hand keeps the home-row mods and adds whitespace/editing keys
// (Esc/Tab/Bspc/Del/Enter/Space/Ins/S-Tab) so you can modify and insert without
// leaving the layer. Sunaku spreads his symbols over five physical rows; here they
// fold onto the number row + three main rows, so boards without a number row (corne)
// only get the three main rows. Right-hand outer/inner columns carry the symbols
// that didn't fit on the left (& \ @ % " ' :).
[_SYM] = LAYOUT_wk(
    // number row  (Sunaku R1 + tilde/angle spill; absent on corne)
    KC_TILD, KC_LABK, KC_LPRN, KC_RPRN, KC_SCLN, KC_COMM,
    KC_PERC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DOT,
    // upper       (Sunaku R2)
    KC_PLUS, KC_GRV,  KC_LCBR, KC_RCBR, KC_RBRC, KC_QUES,
    KC_AMPR, KC_ESC,  KC_TAB,  KC_BSPC, KC_DEL,  KC_DQUO,
    // home        (Sunaku R3; right hand keeps home-row mods)
    KC_EXLM, KC_LBRC, KC_EQL,  KC_UNDS, KC_DLR,  KC_ASTR,
    KC_BSLS, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_QUOT,
    // bottom      (Sunaku R4)
    KC_HASH, KC_CIRC, KC_PIPE, KC_MINS, KC_RABK, KC_SLSH,
    KC_AT,   KC_ENT,  KC_SPC,  KC_INS,  LSFT(KC_TAB), KC_COLN,
    // row 5
    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    // thumbs (left thumbs mirror Sunaku's rolls: \ escape, % match-delimiter, : cmd;
    // right thumb holds the layer, so Space lives on the right-hand fingers instead)
    KC_BSLS, KC_PERC, KC_COLN,
    KC_SPC,  KC_NO,   KC_BSPC
),

[_NUM] = LAYOUT_wk(
    // number row
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // upper
    KC_TAB,  KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS,
    KC_NO,   KC_NO, DF(_GAME), KC_NO, QK_BOOT, KC_NO,
    // home
    KC_NO,   KC_0,    KC_4, KC_5, KC_6, KC_EQL,
    KC_NO,   KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_NO,
    // bottom
    KC_NO,   KC_SLSH, KC_1, KC_2, KC_3, KC_MINS,
    KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_ENT,
    // row 5
    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    // thumbs
    KC_DOT, KC_SPC, KC_ESC,
    KC_NO,  KC_NO,  KC_NO
),

[_FUN] = LAYOUT_wk(
    // number row
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    // upper
    KC_TAB,  KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,
    KC_NO,   KC_NO,  DF(_GAME), KC_NO, QK_BOOT, KC_NO,
    // home
    KC_NO,   KC_F11, KC_F4, KC_F5, KC_F6, KC_SCRL,
    KC_VOLU, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_NO,
    // bottom
    KC_NO,   KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,
    KC_VOLD, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, KC_ENT,
    // row 5
    KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,
    // thumbs
    KC_APP, KC_SPC, KC_ESC,
    KC_NO,  KC_NO,  KC_NO
),
};
