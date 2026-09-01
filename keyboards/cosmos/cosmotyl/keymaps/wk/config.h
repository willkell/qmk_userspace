// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Maps the universal layout (58 keys) to cosmotyl's 62-key LAYOUT.
//
// Like the dactyl_manuform, this board has a full number row (used) and a
// larger thumb cluster than the universal layout: 5 keys per hand vs. 3 active
// thumbs per side. The 3 universal thumbs land on the inner 3 keys; the 2
// outermost are hardcoded here with fixed editing keys on every layer:
// left = Tab then Del, right = Bspc then unused (the old dactyl had no key
// there).
//
// Row 5 = the inner-bottom keys under the ring/middle fingers (XL0 left ring,
// XL1 left middle, XR0 right middle, XR1 right ring).
//
// The physical column -> finger mapping was verified empirically with
// qmk console debug-matrix; it lives in keyboard.json's matrix positions, so
// this macro only has to deal with the logical order below.
//
// LAYOUT_wk parameter order:
//   number row: N00 N01 N02 N03 N04 N05  N06 N07 N08 N09 N0A N0B
//   upper:      L00 L01 L02 L03 L04 L05  R00 R01 R02 R03 R04 R05
//   home:       L10 L11 L12 L13 L14 L15  R10 R11 R12 R13 R14 R15
//   bottom:     L20 L21 L22 L23 L24 L25  R20 R21 R22 R23 R24 R25
//   row 5:         XL0 XL1                  XR0 XR1
//   thumbs:                 L30 L31 L32  R30 R31 R32
#define LAYOUT_wk( \
    N00, N01, N02, N03, N04, N05,  N06, N07, N08, N09, N0A, N0B, \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
    XL0, XL1,                      XR0, XR1,                     \
                   L30, L31, L32,  R30, R31, R32                 \
) \
LAYOUT( \
    N00, N01, N02, N03, N04, N05,  N06, N07, N08, N09, N0A, N0B, \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
    XL0, XL1,                      XR0, XR1,                     \
    L30, L31, L32,                 R30, R31, R32,                \
    KC_TAB, KC_DEL,                KC_BSPC, KC_NO                \
)
