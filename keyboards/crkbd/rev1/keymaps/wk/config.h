// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Handedness stored per-half in EEPROM (set at flash time with the
// avrdude-split-left / avrdude-split-right bootloader targets) rather than
// inferred from which half holds the USB cable.
#define EE_HANDS

// crkbd has no number row — N00-N0B params are accepted but discarded.
// The remaining 42 params map directly to LAYOUT_split_3x6_3.
#define LAYOUT_wk( \
    N00, N01, N02, N03, N04, N05,  N06, N07, N08, N09, N0A, N0B, \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
                   L30, L31, L32,  R30, R31, R32                  \
) \
LAYOUT_split_3x6_3( \
    L00, L01, L02, L03, L04, L05,  R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,  R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,  R20, R21, R22, R23, R24, R25, \
                   L30, L31, L32,  R30, R31, R32                  \
)
