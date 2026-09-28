// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Stock discipline default keymap (QWERTY) plus:
//   - Caps Lock -> Escape
//   - one-shot shifts
//   - home row mods, GACS order to match the wk userspace
// Chordal hold handedness comes from the key x-positions in keyboard.json.
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FN,
};

// Left-hand home row mods
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LSFT_T(KC_D)
#define HM_F LCTL_T(KC_F)
// Right-hand home row mods
#define HM_J    RCTL_T(KC_J)
#define HM_K    RSFT_T(KC_K)
#define HM_L    RALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_ansi(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_GRV,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_DEL,
      KC_ESC,  HM_A,    HM_S,    HM_D,    HM_F,   KC_G,   KC_H,   HM_J,   HM_K,   HM_L,    HM_SCLN, KC_QUOT,  KC_ENT,            KC_PGUP,
      OS_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  OS_RSFT, KC_UP,    KC_PGDN,
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                 KC_RALT, MO(_FN), KC_RCTL,  KC_LEFT, KC_DOWN,  KC_RIGHT),

  [_FN] = LAYOUT_65_ansi(
     /* esc      1        2        3        4       5       6       7       8       9         0        -         =     bkspc       `~  */
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,   KC_PSCR,
     /*  tab      Q       W        E        R        T      Y        U      I        O        P        [         ]        \      delete*/
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,KC_TRNS,KC_TRNS,KC_TRNS,KC_INS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_PAUS, KC_TRNS,  KC_TRNS,
     /*  esc      A       S        D        F        G      H        J      K        L        ;        '        enter             pg up*/
      CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_INS,            KC_HOME,
     /* shift             Z         X        C       V       B       N      M        ,        .        /        shift     up      pg dn*/
      KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_VOLU,  KC_END,
     /* ctrl     win      alt                              space                    alt      fn       ctrl      left     down     right*/
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_TRNS,                KC_RALT, KC_TRNS, KC_RCTL,  KC_TRNS, KC_VOLD,  KC_TRNS)
};
