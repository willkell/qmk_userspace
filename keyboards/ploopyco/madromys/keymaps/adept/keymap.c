/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <math.h>
#include <stdlib.h>

// Defined in ploopyco.c; drives drag-scroll in pointing_device_task_kb.
extern bool is_drag_scroll;

enum custom_keycodes {
    DRG_TH = SAFE_RANGE, // tap: toggle drag-scroll; hold: momentary drag-scroll
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( MS_BTN4, MS_BTN5, DRG_TH, MS_BTN2, MS_BTN1, MS_BTN3 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t drag_timer  = 0;
    static bool     drag_was_on = false;

    switch (keycode) {
        case DRG_TH:
            if (record->event.pressed) {
                drag_timer     = timer_read();
                drag_was_on    = is_drag_scroll;
                is_drag_scroll = true; // engage now so a hold scrolls immediately
            } else if (timer_elapsed(drag_timer) < TAPPING_TERM) {
                is_drag_scroll = !drag_was_on; // tap: toggle relative to prior state
            } else {
                is_drag_scroll = false; // hold: momentary, release ends scrolling
            }
            return false;
        case MS_BTN1:
            is_drag_scroll = false;
            return true;
    }
    return true;
}

// Quadratic pointer acceleration (ported from gorlix/my-adept).
// Scales raw sensor deltas by a factor that grows with the square of speed,
// so slow movements stay precise while fast flicks travel farther. Runs before
// the keyboard-level drag-scroll conversion, so scroll accelerates too.
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    float speed = sqrtf((float)mouse_report.x * mouse_report.x +
                        (float)mouse_report.y * mouse_report.y);
    if (speed > ACCEL_OFFSET) {
        float factor = 1.0f + powf(speed - ACCEL_OFFSET, 2) * 0.001f * ACCEL_SLOPE;
        if (factor > ACCEL_LIMIT) {
            factor = ACCEL_LIMIT;
        }
        mouse_report.x = (mouse_xy_report_t)(mouse_report.x * factor);
        mouse_report.y = (mouse_xy_report_t)(mouse_report.y * factor);
    }

    // While drag-scrolling, suppress horizontal (the keyboard maps x -> h)
    // unless the sideways motion is fast or dominant, to avoid accidental
    // side-scroll. Zeroing x here means the keyboard's drag-scroll emits no h.
    if (is_drag_scroll) {
        if (abs(mouse_report.x) < SCROLL_HLOCK_THRESHOLD &&
            abs(mouse_report.x) < abs(mouse_report.y) * SCROLL_HLOCK_FACTOR) {
            mouse_report.x = 0;
        }
    }
    return mouse_report;
}
