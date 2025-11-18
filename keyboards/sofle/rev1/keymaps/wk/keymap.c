// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAME,
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
#define KC_GAME PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT(
  KC_NO, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_NO,
  KC_TAB, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,      KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
  KC_ESC, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,      KC_H,    LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_QUOT), KC_SCLN,
  KC_NO, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,      KC_MUTE, KC_NO,        KC_N,         KC_M,         KC_COMM,KC_DOT,  KC_SLSH, KC_ENT,
  KC_NO, KC_NO,       LT(_MOUSE, KC_DEL) ,       LT(_NAV,      KC_SPC),   LT(_SYM, KC_ESC),OS_LSFT, MO(_NUM),        LT(_FUN, KC_BSPC), KC_NO, KC_NO
),

[_GAME] = LAYOUT(
  KC_ESC, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_DEL,
  KC_TAB, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,      KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
  KC_LSFT, KC_A, KC_S, KC_D,KC_F, KC_G,      KC_H,    KC_J, KC_K, KC_L, KC_QUOT, KC_SCLN,
  KC_LCTL, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,      KC_MUTE, KC_NO,        KC_N,         KC_M,         KC_COMM,KC_DOT,  KC_SLSH, KC_ENT,
  KC_LGUI, KC_LALT,       LT(_MOUSE, KC_DEL) ,       MO(KC_SPC),   LT(_SYM, KC_ESC),OS_LSFT, MO(_NUM),        LT(_FUN, KC_BSPC), KC_NO, KC_NO
),

[_ENTHIUM] = LAYOUT(
        KC_NO, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_NO,
  KC_TAB, KC_Z,         KC_Y,         KC_O,         KC_U,         KC_EQL,      KC_Q,    KC_L,         KC_D,         KC_P,         KC_X,         KC_BSPC,
  KC_W, LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_A), LSFT_T(KC_E), KC_SCLN,      KC_K,    LSFT_T(KC_H), LCTL_T(KC_T), LALT_T(KC_N), LGUI_T(KC_S),    KC_F,
  KC_ESC, KC_QUOT,         KC_MINS,         KC_COMM,         KC_DOT,         KC_SLSH,      KC_MUTE, KC_NO,        KC_J,         KC_M,         KC_G,         KC_B,  KC_V, KC_ENT,
  KC_NO, KC_NO,       LT(_MOUSE, KC_DEL) ,       LT(_NAV,      KC_SPC),   LT(_SYM, KC_ESC),OS_LSFT, LT(_NUM,      KC_R),        LT(_FUN, KC_BSPC), KC_NO, KC_NO
    ),

[_NUM] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_TAB, KC_ASTR,      KC_7,         KC_8,         KC_9,         KC_PLUS,   KC_NO,   DF(_QWERTY),  DF(_GAME), KC_NO,        QK_BOOT,         KC_NO,
  KC_NO, KC_0,      KC_4,         KC_5,         KC_6,          KC_EQL,    KC_NO,   KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,         KC_NO,
  KC_NO, KC_SLSH,       KC_1,         KC_2,         KC_3,       KC_MINS,   KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,   KC_NO,   KC_ENT,
  KC_NO, KC_NO,        KC_DOT,       KC_SPC,         KC_ESC,      KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO
),

[_SYM] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_TAB, KC_GRV,      KC_TILD,        KC_EXLM,      KC_AT,       KC_PLUS,   KC_PIPE, KC_LCBR,       KC_RCBR,       KC_CIRC,      KC_DLR,         KC_NO,
KC_ESC, KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      KC_COLN,   KC_MINS, KC_LPRN,      KC_RPRN,      KC_UNDS,      KC_EQL,         KC_SCLN,
  KC_NO, KC_NO,        KC_NO,        KC_HASH,      KC_PERC,       KC_BSLS,   KC_NO,   KC_NO,        KC_ASTR,      KC_LBRC,      KC_RBRC,         KC_AMPR, KC_QUES, KC_ENT,
  KC_NO, KC_NO,        KC_DOT,       KC_SPC,         KC_ESC,      KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO
),

[_FUN] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_TAB, KC_F12,       KC_F7,        KC_F8,        KC_F9,        KC_PSCR,   KC_NO,   DF(_QWERTY),  DF(_GAME), KC_NO,        QK_BOOT,         KC_NO,
  KC_NO, KC_F11,       KC_F4,        KC_F5,        KC_F6,        KC_SCRL,   KC_VOLU, KC_LSFT,      KC_LCTL,      KC_LALT,      KC_LGUI,         KC_NO,
  KC_NO, KC_F10,       KC_F1,        KC_F2,        KC_F3,        KC_PAUS,   KC_NO,   KC_NO,        KC_VOLD,      KC_MUTE,      KC_MPLY,         KC_MPRV, KC_MNXT, KC_ENT,
  KC_NO, KC_NO,        KC_APP,       KC_SPC,         KC_ESC,       KC_NO, KC_NO,   KC_NO,        KC_NO,        KC_NO
),

[_NAV] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_TAB, QK_BOOT,      DF(_ENTHIUM),        DF(_GAME), DF(_QWERTY),  KC_NO,     C(KC_Y), C(KC_V),      C(KC_C),      C(KC_X),      C(KC_Z),         KC_NO,
  KC_NO, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D),      LSFT_T(KC_F),      KC_NO,     KC_LEFT, KC_DOWN,      KC_UP,        KC_RGHT,      CW_CAPS,         KC_NO,
  KC_NO, C(KC_Z),        C(KC_X),        C(KC_C),        C(KC_V),        KC_NO,     KC_NO,   KC_NO,        KC_HOME,      KC_PGDN,      KC_PGUP,         KC_END,  KC_INS,  KC_ENT,
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_BSPC, KC_DEL,       KC_NO,        KC_NO
),

[_MOUSE] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_TAB, QK_BOOT,      DF(_ENTHIUM),        DF(_GAME), DF(_QWERTY),  KC_NO,     C(KC_Y), C(KC_V),      C(KC_C),      C(KC_X),      C(KC_Z),         KC_NO,
  KC_NO, KC_LGUI,      KC_LALT,      KC_LCTL,      KC_LSFT,      KC_NO,     MS_LEFT, MS_DOWN,      MS_UP,        MS_RGHT,      KC_NO,           KC_NO,
  KC_NO, LCS(KC_Z),    LCS(KC_X),    LCS(KC_C),    LCS(KC_V),    KC_NO,     KC_NO,   KC_NO,        MS_WHLL,      MS_WHLD,      MS_WHLU,         MS_WHLR, KC_NO,   KC_ENT,
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        MS_BTN2,   MS_BTN1, MS_BTN3,      KC_NO,        KC_NO
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mods = get_mods() | get_oneshot_mods();
    uint8_t current_layer = get_highest_layer(layer_state);
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
    case LGUI_T(KC_A):
        if (current_layer == _NAV && record->tap.count && record->event.pressed) {
                tap_code16(C(KC_A));
                return false;
        }
    case LALT_T(KC_S):
        if (current_layer == _NAV && record->tap.count && record->event.pressed) {
                tap_code16(C(KC_S));
                return false;
        }
    case LCTL_T(KC_D):
        if (current_layer == _NAV && record->tap.count && record->event.pressed) {
                tap_code16(C(KC_D));
                return false;
        }
    case LSFT_T(KC_F):
        if (current_layer == _NAV && record->tap.count && record->event.pressed) {
                tap_code16(C(KC_F));
                return false;
        }

  }

  return true;
}


// make thumb keys not part of any hand
char chordal_hold_handedness(keypos_t key) {
    if (key.row == MATRIX_ROWS - 1 || key.row == MATRIX_ROWS / 2 - 1) {
        return '*';
    }

    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

