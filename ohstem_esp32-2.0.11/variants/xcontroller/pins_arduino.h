#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define EXTERNAL_NUM_INTERRUPTS 16
#define NUM_DIGITAL_PINS        40
#define NUM_ANALOG_INPUTS       16

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<40)?(p):-1)
#define digitalPinHasPWM(p)         (p < 34)

static const uint8_t BUZZER = 27;
static const uint8_t RGB_LED = 12;

static const uint8_t BUTTON = 23;

static const uint8_t IR_RX = 15;
static const uint8_t IR_TX = 2;

static const uint8_t TX = 1;
static const uint8_t RX = 3;

static const uint8_t SDA = 21;
static const uint8_t SCL = 22;

static const uint8_t SS    = 5;
static const uint8_t MOSI  = 23;
static const uint8_t MISO  = 19;
static const uint8_t SCK   = 18;

static const uint8_t D1_1 = 18;
static const uint8_t D1_2 = 19;
static const uint8_t D2_1 = 4;
static const uint8_t D2_2 = 5;
static const uint8_t D3_1 = 13;
static const uint8_t D3_2 = 14;
static const uint8_t D4_1 = 16;
static const uint8_t D4_2 = 17;
static const uint8_t D5_1 = 32;
static const uint8_t D5_2 = 33;
static const uint8_t D6_1 = 25;
static const uint8_t D6_2 = 26;

static const uint8_t A2_1 = 13;
static const uint8_t A2_2 = 14;
static const uint8_t A3_1 = 4;
static const uint8_t A4_1 = 39;
static const uint8_t A4_2 = 36;
static const uint8_t A5_1 = 32;
static const uint8_t A5_2 = 33;
static const uint8_t A6_1 = 34;
static const uint8_t A6_2 = 35;

static const uint8_t T0 = 4;
static const uint8_t T1 = 0;
static const uint8_t T2 = 2;
static const uint8_t T3 = 15;
static const uint8_t T4 = 13;
static const uint8_t T5 = 12;
static const uint8_t T6 = 14;
static const uint8_t T7 = 27;
static const uint8_t T8 = 33;
static const uint8_t T9 = 32;

static const uint8_t DAC1 = 25;
static const uint8_t DAC2 = 26;

#endif /* Pins_Arduino_h */
