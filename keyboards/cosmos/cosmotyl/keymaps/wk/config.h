// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Maps the universal layout (58 keys) to cosmotyl's 62-key LAYOUT.
//
// Physical column -> finger, verified empirically via qmk console debug-matrix
// (right half) and mirrored for the left:
//   col0            thumb cluster only (2 keys)
//   col1            index-inner-stretch column (+2 thumb-cluster keys)
//   col2            index
//   col3            middle
//   col4            ring
//   col5            pinky
//   col6            pinky-outer-stretch
//
// col3/col4 row 0 are the "extra" keys below the bottom row under ring/middle
// (this board's XL0/XL1/XR0/XR1, same concept as the old dactyl_manuform).
//
// Each hand's 5-key thumb cluster: the 3 innermost keys are universal thumbs
// (L30-L32/R30-R32); the 2 outermost are hardcoded, mirroring the old board's
// fixed low-thumb-row keys (left: Tab, Del; right: Bspc, Del).
#define LAYOUT_wk( \
    N00, N01, N02, N03, N04, N05,  N06, N07, N08, N09, N0A, N0B, \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
    XL0, XL1,                      XR0, XR1,                     \
                   L30, L31, L32,  R30, R31, R32                 \
) \
LAYOUT( \
    /* left: col0 */   KC_TAB,  L30, \
    /* left: col1 */   KC_DEL,  L31, L25, L15, L05, N05, \
    /* left: col2 */   L32, L24, L14, L04, N04, \
    /* left: col3 */   XL1, L23, L13, L03, N03, \
    /* left: col4 */   XL0, L22, L12, L02, N02, \
    /* left: col5 */   L21, L11, L01, N01, \
    /* left: col6 */   L20, L10, L00, N00, \
    /* right: col0 */  KC_BSPC, R30, \
    /* right: col1 */  KC_DEL,  R31, R20, R10, R00, N06, \
    /* right: col2 */  R32, R21, R11, R01, N07, \
    /* right: col3 */  XR0, R22, R12, R02, N08, \
    /* right: col4 */  XR1, R23, R13, R03, N09, \
    /* right: col5 */  R24, R14, R04, N0A, \
    /* right: col6 */  R25, R15, R05, N0B \
)
