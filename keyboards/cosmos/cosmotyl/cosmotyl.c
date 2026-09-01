// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

// The Lemon Wired controller gates RGB LED power behind a MOSFET on GP11.
// Without driving it high the LEDs stay dark no matter what is sent on the
// WS2812 data line (GP2).
//
// Follow the matrix state so "RGB off" actually cuts the rail rather than
// leaving 62 LEDs powered and blank, drawing quiescent current.
#define RGB_POWER_PIN GP11

static bool rgb_powered;

static bool rgb_power_wanted(void) {
    return rgb_matrix_is_enabled() && rgb_matrix_get_val() > 0;
}

void keyboard_post_init_kb(void) {
    rgb_powered = rgb_power_wanted();
    gpio_set_pin_output(RGB_POWER_PIN);
    gpio_write_pin(RGB_POWER_PIN, rgb_powered);

    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    bool wanted = rgb_power_wanted();
    if (wanted != rgb_powered) {
        rgb_powered = wanted;
        gpio_write_pin(RGB_POWER_PIN, rgb_powered);
    }

    housekeeping_task_user();
}
