// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _MEDIA,
    _NAV,
    _MOUSE,
    _SYM,
    _NUM,
    _FUN,
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,     KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_NO, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,    KC_Y,      KC_U,         KC_I,         KC_O,         KC_P,            KC_NO,
  KC_NO, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H,      LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_QUOT), KC_NO,
  KC_NO, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,    KC_MUTE,   KC_NO,        KC_N,         KC_M,         KC_COMM,         KC_DOT,   KC_SLSH, KC_NO,
  KC_NO, KC_NO,        LT(_MEDIA,    KC_ESC),      LT(_NAV,      KC_SPC), LT(_MOUSE, KC_TAB),      LT(_SYM,      KC_ENT),      LT(_NUM,         KC_BSPC), LT(_FUN, KC_DEL), KC_NO, KC_NO
),

[_COLEMAK] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,   KC_NO,     KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
  KC_NO, KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,    KC_J,      KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_NO,
  KC_NO, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,    KC_M,      LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_NO,
  KC_NO, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,    KC_MUTE,   KC_NO,        KC_K,         KC_H,         KC_COMM,      KC_DOT,   KC_SLSH, KC_NO,
  KC_NO, KC_NO,        LT(_MEDIA,    KC_ESC),      LT(_NAV,      KC_SPC), LT(_MOUSE, KC_TAB),      LT(_SYM,      KC_ENT),      LT(_NUM,      KC_BSPC), LT(_FUN, KC_DEL), KC_NO, KC_NO
),

[_NUM] = LAYOUT(
  KC_NO, KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,       KC_NO,        KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_LBRC, KC_7,   KC_8,  KC_9,    KC_RBRC, KC_NO, DF(_QWERTY), DF(_COLEMAK), KC_NO,   QK_BOOT, KC_NO,
  KC_NO, KC_SCLN, KC_4,   KC_5,  KC_6,    KC_EQL,  KC_NO, KC_LSFT,     KC_LCTL,      KC_LALT, KC_LGUI, KC_NO,
  KC_NO, KC_GRV,  KC_1,   KC_2,  KC_3,    KC_BSLS, KC_NO, KC_NO,       KC_NO,        KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO,   KC_DOT, KC_0,  KC_MINS, KC_NO,   KC_NO, KC_NO,       KC_NO,        KC_NO
),

[_SYM] = LAYOUT(
  KC_NO, KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,       KC_NO,        KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_LBRC, KC_7,   KC_8,  KC_9,    KC_RBRC, KC_NO, DF(_QWERTY), DF(_COLEMAK), KC_NO,   QK_BOOT, KC_NO,
  KC_NO, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,    KC_M,      LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_NO,
  KC_NO, KC_GRV,  KC_1,   KC_2,  KC_3,    KC_BSLS, KC_NO, KC_NO,       KC_NO,        KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO,   KC_DOT, KC_0,  KC_MINS, KC_NO,   KC_NO, KC_NO,       KC_NO,        KC_NO
),
};
