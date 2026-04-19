// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "wk.h"

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

// Thumb rows are treated as belonging to neither hand for chordal hold.
// Works for any symmetric split keyboard where the thumb row is the last
// row of each half (MATRIX_ROWS/2 - 1 for left, MATRIX_ROWS - 1 for right).
char chordal_hold_handedness(keypos_t key) {
    if (key.row == MATRIX_ROWS - 1 || key.row == MATRIX_ROWS / 2 - 1) {
        return '*';
    }
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return !within_flow_tap_term(keycode, record);
}
