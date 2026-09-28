// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Maps the universal layout onto the Planck rev6 4x12 grid (LAYOUT_ortho_4x12;
// build it with the grid plate, not the 2u-spacebar MIT layout).
//
// The top three rows are the corne's 3x6 per hand. The bottom row holds the 3
// thumbs per side in cols 3-8, and the 6 corner keys take the dactyl-only extras:
//
//   col:  0    1    2    3    4    5     6    7    8    9    10   11
//         L40  XL0  XL1  L30  L32  L31   R31  R30  R32  XR0  XR1  R40
//
// L31 (space) and R31 (R) sit innermost in cols 5/6, swapped with L32/R30
// relative to the corne order, so they meet at the centre of the grid.
//
// XL0/XL1/XR0/XR1 are shifted one column outward from their dactyl position
// (ring/middle) because col 3/8 is taken by the outer thumb. The number row and
// L41/R41 have no home here and are discarded.
#define LAYOUT_wk( \
    N00, N01, N02, N03, N04, N05,  N06, N07, N08, N09, N0A, N0B, \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
    XL0, XL1,                      XR0, XR1,                      \
                   L30, L31, L32,  R30, R31, R32,                 \
                        L40, L41,  R40, R41                       \
) \
LAYOUT_ortho_4x12( \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
    L40, XL0, XL1, L30, L32, L31,  R31, R30, R32, XR0, XR1, R40  \
)
