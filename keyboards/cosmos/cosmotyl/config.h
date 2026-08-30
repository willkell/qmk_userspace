#pragma once

// Handedness stored in EEPROM, set at flash time via uf2-split-left/uf2-split-right.
#define EE_HANDS

// Split serial: fixed Lemon Wired pins (confirmed against the official pinout).
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define SPLIT_USB_DETECT
