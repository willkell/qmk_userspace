// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _ENTHIUM,
    _GAME,
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
    _NUM_SYM,
};

enum custom_keycodes {
    CW_CAPS =  SAFE_RANGE,
};

const uint16_t PROGMEM tab_combo[]  = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM copy_combo[]  = { KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM shift_copy_combo[]  = { KC_QUOT, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM paste_combo[]  = { KC_DOT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM shift_paste_combo[]  = { KC_COMM, KC_DOT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM esc_combo[]  = { LALT_T(KC_I), LSFT_T(KC_A), COMBO_END};
const uint16_t PROGMEM oss_combo[]  = { KC_QUOT, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(tab_combo,  KC_TAB),
    COMBO(copy_combo,  C(KC_C)),
    COMBO(shift_copy_combo,  LCS(KC_C)),
    COMBO(paste_combo,  C(KC_V)),
    COMBO(shift_paste_combo,  LCS(KC_V)),
    COMBO(esc_combo, LSA_T(KC_ESC)),
    COMBO(oss_combo, OS_LSFT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_ENTHIUM] = LAYOUT(
        KC_NO, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_NO,
  KC_TAB, KC_Q,         KC_Y,         KC_O,         KC_U,         KC_EQL,      KC_X,    KC_L,         KC_D,         KC_W,         KC_Z,         KC_BSPC,
  KC_B, LGUI_T(KC_C), LALT_T(KC_I), LSFT_T(KC_A), LCTL_T(KC_E), KC_MINS,      KC_K,    RCTL_T(KC_H), RSFT_T(KC_T), RALT_T(KC_N), RGUI_T(KC_S),    KC_F,
  KC_ESC, KC_QUOT,         KC_COMM,         KC_DOT,         KC_SCLN,         KC_SLSH,      KC_MUTE, KC_NO,        KC_J,         KC_M,         KC_G,         KC_P,  KC_V, KC_ENT,
  KC_NO,          KC_NO,         LT(_FUN, KC_DEL),        KC_SPC,    OSL(_NUM_SYM), OS_LSFT,LT(_NAV,      KC_R),         KC_BSPC, KC_NO, KC_NO
    ),

[_GAME] = LAYOUT(
  KC_ESC, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_DEL,
  KC_TAB, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,      KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
  KC_LSFT, KC_A, KC_S, KC_D,KC_F, KC_G,      KC_H,    KC_J, KC_K, KC_L, KC_QUOT, KC_SCLN,
  KC_LCTL, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,      KC_MUTE, KC_NO,        KC_N,         KC_M,         KC_COMM,KC_DOT,  KC_SLSH, KC_ENT,
  KC_LGUI, KC_LALT,       LT(_NAV, KC_DEL) ,       KC_SPC,   LT(_SYM, KC_ESC), OSL(_NUM_SYM), MO(_NAV),        KC_BSPC, KC_NO, KC_NO
),

[_QWERTY] = LAYOUT(
  KC_NO, KC_1,        KC_2,        KC_3,        KC_4,        KC_5,     KC_6,   KC_7,        KC_8,        KC_9,        KC_0,           KC_NO,
  KC_TAB, KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,      KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
  KC_ESC, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G,      KC_H,    RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_QUOT), KC_SCLN,
  KC_NO, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,      KC_MUTE, KC_NO,        KC_N,         KC_M,         KC_COMM,KC_DOT,  KC_SLSH, KC_ENT,
  KC_NO,          KC_NO,         LT(_FUN, KC_DEL),        KC_SPC,   OS_LSFT, OSL(_NUM_SYM), MO(_NAV),        KC_BSPC, KC_NO, KC_NO
),

[_NUM_SYM] = LAYOUT(
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_TAB, KC_GRV,      KC_TILD,       KC_LCBR,       KC_RCBR,       KC_PIPE,   KC_DLR, KC_7, KC_8, KC_9,        KC_NO,         KC_NO,
  KC_NO, KC_EXLM,      KC_AT,      KC_LPRN,      KC_RPRN,      KC_HASH,    KC_PERC, RCTL_T(KC_4), RSFT_T(KC_5), RALT_T(KC_6), RGUI_T(KC_0),         KC_NO,
  KC_ESC, KC_BSLS,        KC_AMPR,         KC_LBRC,      KC_RBRC,       KC_ASTR,   KC_NO,   KC_NO, KC_CIRC, KC_1, KC_2, KC_3, KC_DOT,   KC_ENT,
  KC_NO,    KC_NO,        KC_NO,       KC_SPC,         KC_NO,      KC_NO,     KC_NO,   KC_NO,        KC_NO,        KC_NO
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
  KC_TAB, QK_BOOT,      DF(_QWERTY),        DF(_GAME), DF(_ENTHIUM),  KC_NO,     C(KC_Y), C(KC_V),      C(KC_C),      C(KC_X),      C(KC_Z),         KC_NO,
  KC_NO, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D),      LCTL_T(KC_F),      KC_NO,   CW_CAPS,   KC_LEFT, KC_DOWN,      KC_UP,        KC_RGHT,              KC_NO,
  KC_NO, C(KC_Z),        C(KC_X),        C(KC_C),        C(KC_V),        KC_NO,     KC_NO,   KC_NO,        KC_HOME,      KC_PGDN,      KC_PGUP,         KC_END,  KC_INS,  KC_ENT,
  KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,     KC_BSPC, KC_DEL,       KC_NO,        KC_NO
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


// make thumb keys not part of any hand
char chordal_hold_handedness(keypos_t key) {
    if (key.row == MATRIX_ROWS - 1 || key.row == MATRIX_ROWS / 2 - 1) {
        return '*';
    }

    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
      // Disable the combo if it's pressed within the Flow Tap term.
      return !within_flow_tap_term(keycode, record);
}
