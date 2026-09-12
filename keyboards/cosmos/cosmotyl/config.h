#pragma once

// Handedness stored in EEPROM, set at flash time via uf2-split-left/uf2-split-right.
#define EE_HANDS

// Split serial: fixed Lemon Wired pins (confirmed against the official pinout).
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

// Auto-defined on ChibiOS/ARM; listed here for visibility.
#define SPLIT_USB_DETECT
// Default 2000ms is too short behind a KVM — the host doesn't enumerate in
// time on a cold boot and both halves delegate to slave.
#define SPLIT_USB_TIMEOUT 3000
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 4000
