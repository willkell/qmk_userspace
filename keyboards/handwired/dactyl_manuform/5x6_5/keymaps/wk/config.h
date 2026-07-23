// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Handedness is stored per-half in EEPROM (set once at flash time with the
// uf2-split-left / uf2-split-right bootloader targets) rather than inferred
// from which half holds the USB cable.
#define EE_HANDS

// Maps the universal layout (54 keys) to the dactyl_manuform 5x6_5's 62-key
// LAYOUT_5x6_5.
//
// The dactyl has a full number row (used) and a larger thumb cluster than the
// universal layout: 7 keys per hand (5-key top row + 2-key lower row) vs. 3
// active thumbs per side. The 3 thumbs land on the inner 3 keys of the top
// thumb row (mirroring the corne's flat thumb row). The 2-key lower row on each
// hand exists only on the dactyl, so it's hardcoded here with fixed editing keys
// on every layer: left = Tab then Del, right = Bspc (inner key, below the Esc).
//
//   left top thumb row (x):  2    3    5    6    7
//                            XL0  XL1  L30  L31  L32
//   left low thumb row (x):            .    6    7
//                                           TAB  DEL
//   right top thumb row (x): 9    10   11   13   14
//                            R30  R31  R32  XR0  XR1
//   right low thumb row (x): 9    10
//                            BSPC NO
//
// LAYOUT_wk parameter order:
//   number row: N00 N01 N02 N03 N04 N05  N06 N07 N08 N09 N0A N0B
//   upper:      L00 L01 L02 L03 L04 L05  R00 R01 R02 R03 R04 R05
//   home:       L10 L11 L12 L13 L14 L15  R10 R11 R12 R13 R14 R15
//   bottom:     L20 L21 L22 L23 L24 L25  R20 R21 R22 R23 R24 R25
//   row 5:         XL0 XL1                  XR0 XR1
//   thumbs:                 L30 L31 L32  R30 R31 R32
//
// Row 5 = the inner-bottom keys under the ring/middle fingers (XL0 left ring,
// XL1 left middle, XR0 right middle, XR1 right ring), previously KC_NO.
#define LAYOUT_wk( \
    N00, N01, N02, N03, N04, N05,  N06, N07, N08, N09, N0A, N0B, \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
    XL0, XL1,                      XR0, XR1,                      \
                   L30, L31, L32,  R30, R31, R32                  \
) \
LAYOUT_5x6_5( \
    N00, N01, N02, N03, N04, N05,  N06, N07, N08, N09, N0A, N0B, \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
              XL0, XL1, L30, L31, L32,  R30, R31, R32, XR0, XR1, \
                            KC_TAB, KC_DEL,   KC_BSPC, KC_NO        \
)
