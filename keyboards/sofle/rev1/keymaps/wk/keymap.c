// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _ENTHIUM,
    _NAV,
    _MOUSE,
    _SYM,
    _NUM,
    _FUN,
};


enum custom_keycodes {
    CW_CAPS =  SAFE_RANGE,
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT(
  KC_NO, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_NO,
  KC_TAB, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,      KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
  KC_ESC, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,      KC_H,    LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_QUOT), KC_SCLN,
  KC_NO, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,      KC_MUTE, KC_NO,        KC_N,         KC_M,         KC_COMM,KC_DOT,  KC_SLSH, KC_ENT,
  KC_NO, KC_NO,       LT(_MOUSE, KC_ENT) ,       LT(_NAV,      KC_SPC),  KC_LSFT,MO(_SYM),      LT(_NUM,      KC_BSPC),        LT(_FUN, KC_DEL), KC_NO, KC_NO
),

[_COLEMAK] = LAYOUT(
  KC_NO, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_NO,
  KC_TAB, KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,      KC_J,    KC_L,         KC_U,         KC_Y,         KC_QUOT,         KC_BSPC,
  KC_ESC, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,      KC_M,    LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),    KC_SCLN,
  KC_NO, KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,      KC_MUTE, KC_NO,        KC_K,         KC_H,         KC_COMM,KC_DOT,  KC_SLSH,KC_ENT ,
  KC_NO, KC_NO,       LT(_MOUSE, KC_ENT) ,       LT(_NAV,      KC_SPC),  KC_LSFT,MO(_SYM),      LT(_NUM,      KC_BSPC),        LT(_FUN, KC_DEL), KC_NO, KC_NO
),

[_ENTHIUM] = LAYOUT(
        KC_NO, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_NO,
  KC_TAB, KC_Z,         KC_Y,         KC_O,         KC_U,         KC_EQL,      KC_Q,    KC_L,         KC_D,         KC_P,         KC_X,         KC_BSPC,
  KC_W, LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_A), LSFT_T(KC_E), KC_SCLN,      KC_K,    LSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S),    KC_F,
  KC_ESC, KC_QUOT,         KC_MINS,         KC_COMM,         KC_DOT,         KC_SLSH,      KC_MUTE, KC_NO,        KC_J,         KC_M,         KC_G,         KC_B,  KC_V, KC_ENT,
  KC_NO, KC_NO,       LT(_MOUSE, KC_ESC) ,       LT(_NAV,      KC_SPC),  KC_LSFT,LT(_SYM, KC_BSPC),      LT(_NUM,      KC_R),        LT(_FUN, KC_DEL), KC_NO, KC_NO
    ),

[_NUM] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_NO, KC_ASTR,      KC_7,         KC_8,         KC_9,         KC_PLUS,   KC_NO,   DF(_QWERTY),  DF(_COLEMAK), KC_NO,        QK_BOOT,         KC_NO,
  KC_NO, KC_0,      KC_4,         KC_5,         KC_6,          KC_EQL,    KC_NO,   KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,         KC_NO,
  KC_NO, KC_SLSH,       KC_1,         KC_2,         KC_3,       KC_MINS,   KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,        KC_DOT,       KC_SPC,         KC_ENT,      KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO
),

[_SYM] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_NO, KC_GRV,      KC_TILD,        KC_EXLM,      KC_AT,       KC_PLUS,   KC_PIPE, KC_LCBR,       KC_RCBR,       KC_CIRC,      KC_DLR,         KC_NO,
KC_ESC, KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      KC_COLN,   KC_MINS, KC_LPRN,      KC_RPRN,      KC_UNDS,      KC_EQL,         KC_SCLN,
  KC_NO, KC_NO,        KC_NO,        KC_HASH,      KC_PERC,       KC_BSLS,   KC_NO,   KC_NO,        KC_ASTR,      KC_LBRC,      KC_RBRC,         KC_AMPR, KC_QUES, KC_NO,
  KC_NO, KC_NO,        KC_DOT,       KC_SPC,         KC_ENT,      KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO
),

[_FUN] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_NO, KC_F12,       KC_F7,        KC_F8,        KC_F9,        KC_PSCR,   KC_NO,   DF(_QWERTY),  DF(_COLEMAK), KC_NO,        QK_BOOT,         KC_NO,
  KC_NO, KC_F11,       KC_F4,        KC_F5,        KC_F6,        KC_SCRL,   KC_VOLU, KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,         KC_NO,
  KC_NO, KC_F10,       KC_F1,        KC_F2,        KC_F3,        KC_PAUS,   KC_NO,   KC_NO,        KC_VOLD,      KC_MUTE,      KC_MPLY,         KC_MPRV, KC_MNXT, KC_NO,
  KC_NO, KC_NO,        KC_APP,       KC_SPC,       KC_TAB,       KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO
),

[_NAV] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_NO, QK_BOOT,      DF(_ENTHIUM),        DF(_COLEMAK), DF(_QWERTY),  KC_NO,     C(KC_Y), C(KC_V),      C(KC_C),      C(KC_X),      C(KC_Z),         KC_NO,
  KC_NO, KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      KC_NO,     KC_LEFT, KC_DOWN,      KC_UP,        KC_RGHT,      CW_CAPS,         KC_NO,
  KC_NO, C(KC_Z),        C(KC_X),        C(KC_C),        C(KC_V),        KC_NO,     KC_NO,   KC_NO,        KC_HOME,      KC_PGDN,      KC_PGUP,         KC_END,  KC_INS,  KC_NO,
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_BSPC, KC_DEL,       KC_NO,        KC_NO
),

[_MOUSE] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_NO, QK_BOOT,      KC_NO,        DF(_COLEMAK), DF(_QWERTY),  KC_NO,     C(KC_Y), C(KC_V),      C(KC_C),      C(KC_X),      C(KC_Z),         KC_NO,
  KC_NO, KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      KC_NO,     MS_LEFT, MS_DOWN,      MS_UP,        MS_RGHT,      KC_NO,           KC_NO,
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        MS_WHLL,      MS_WHLD,      MS_WHLU,         MS_WHLR, KC_NO,   KC_NO,
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        MS_BTN2,   MS_BTN1, MS_BTN3,      KC_NO,        KC_NO
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mods = get_mods() | get_oneshot_mods();
  switch (keycode) {
    case CW_CAPS:
      if (record->event.pressed) {
        if (mods & MOD_MASK_SHIFT) {
          tap_code16(KC_CAPS);
        } else {
          caps_word_toggle();
        }
      }
      return false;

  }

  return true;
}


