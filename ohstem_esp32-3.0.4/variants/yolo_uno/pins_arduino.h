#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>
#include "soc/soc_caps.h"

#define USB_VID 0x2341
#define USB_PID 0x0070

#define EXTERNAL_NUM_INTERRUPTS 46
#define NUM_DIGITAL_PINS        25
#define NUM_ANALOG_INPUTS       8

#define analogInputToDigitalPin(p)  (p)
#define digitalPinToInterrupt(p)    ((((uint8_t)digitalPinToGPIONumber(p)) < 48)? digitalPinToGPIONumber(p) : -1)
#define digitalPinHasPWM(p)         (((uint8_t)digitalPinToGPIONumber(p)) < 46)

#ifndef __cplusplus
#define constexpr const
#endif

// primary pin names

static constexpr uint8_t D0         = 44; // also RX
static constexpr uint8_t D1         = 43; // also TX
static constexpr uint8_t D2         = 5;
static constexpr uint8_t D3         = 6; // also CTS
static constexpr uint8_t D4         = 7; // also DSR
static constexpr uint8_t D5         = 8;
static constexpr uint8_t D6         = 9;
static constexpr uint8_t D7         = 10;
static constexpr uint8_t D8         = 17;
static constexpr uint8_t D9         = 18;
static constexpr uint8_t D10        = 21; // also SS
static constexpr uint8_t D11        = 38; // also MOSI
static constexpr uint8_t D12        = 47; // also MISO
static constexpr uint8_t D13        = 48; // also SCK, LED_BUILTIN

static constexpr uint8_t RGB_LED    = 45;

static constexpr uint8_t A0         = 1; // also DTR
static constexpr uint8_t A1         = 2;
static constexpr uint8_t A2         = 3;
static constexpr uint8_t A3         = 4;
static constexpr uint8_t A4         = 11; // also SDA
static constexpr uint8_t A5         = 12; // also SCL
static constexpr uint8_t A6         = 13;
static constexpr uint8_t A7         = 14;

// alternate pin functions

static constexpr uint8_t LED_BUILTIN = D13;

static constexpr uint8_t TX   = D1;
static constexpr uint8_t RX   = D0;
static constexpr uint8_t RTS  = RGB_LED;
static constexpr uint8_t CTS  = D3;
static constexpr uint8_t DTR  = A0;
static constexpr uint8_t DSR  = D4;

static constexpr uint8_t SS   = D10;
static constexpr uint8_t MOSI = D11;
static constexpr uint8_t MISO = D12;
static constexpr uint8_t SCK  = D13;

static constexpr uint8_t SDA  = A4;
static constexpr uint8_t SCL  = A5;

#define PIN_I2S_SCK     D7
#define PIN_I2S_FS      D8
#define PIN_I2S_SD      D9
#define PIN_I2S_SD_OUT  D9 // same as bidir
#define PIN_I2S_SD_IN   D10

#ifndef __cplusplus
#undef constexpr
#endif

#endif /* Pins_Arduino_h */
