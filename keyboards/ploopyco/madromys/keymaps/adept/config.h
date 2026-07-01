#pragma once

// Invert the vertical direction of drag-scroll.
#define PLOOPY_DRAGSCROLL_INVERT

// Slow down drag-scroll (default 8.0; higher = slower).
#define PLOOPY_DRAGSCROLL_DIVISOR_H 32.0
#define PLOOPY_DRAGSCROLL_DIVISOR_V 32.0

// Base sensor speed: 600 CPI. All options are equal so any DPI index
// persisted in EEPROM still resolves to the same value.
#define PLOOPY_DPI_OPTIONS { 600, 600, 600, 600, 600 }
#define PLOOPY_DPI_DEFAULT 0

// Quadratic pointer acceleration (ported from gorlix/my-adept).
// 16-bit mouse reports so an accelerated delta can't overflow int8.
#define MOUSE_EXTENDED_REPORT
// Drag-scroll horizontal lock: only scroll sideways when the horizontal motion
// is fast (>= threshold) or clearly dominates vertical, to stop accidental
// side-scroll while scrolling up/down.
#define SCROLL_HLOCK_THRESHOLD 4  // min horizontal speed (counts/poll) to allow side-scroll
#define SCROLL_HLOCK_FACTOR    1.5 // horizontal must exceed vertical by this factor

#define ACCEL_OFFSET 5   // min speed (counts/poll) before accel engages
#define ACCEL_SLOPE  4.5 // curve steepness
#define ACCEL_LIMIT  6.0 // max multiplier (cap)
