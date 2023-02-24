#include "YoloBit.h"
#include <math.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 5
#define NUM_LEDS (NUM_ROWS * NUM_COLUMNS)
#define LED_PIN 4

YoloBit::YoloBit()
{
    brightness = 50;
    currentColor = CRGB::Red;
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(ledMatrix, 25);
    FastLED.setBrightness(brightness);
    delay(500);
}

YoloBit::~YoloBit(void)
{

}

void YoloBit::showChar(CRGB (*matrix)[5], CRGB color, int x, char character) {
  int y = 0;
  int width = 5;
  int height = 5;


  if (width > 0 && height > 0) {
    int charIndex = (int)character - 32;
    int xBitsToProcess = width;
    for (int i = 0; i < height; i++) {
      byte fontLine = FontData[charIndex][i];
      for (int bitCount = 0; bitCount < xBitsToProcess; bitCount++) {
        CRGB pixelColour = CRGB(0, 0, 0);
        if (fontLine & 0b10000000) {
          pixelColour = color;
        }
        fontLine = fontLine << 1;
        int xpos = x + bitCount;
        int ypos = y + i;
        if (xpos < 0 || xpos > 10 || ypos < 0 || ypos > 5);
        else {
          matrix[xpos][ypos] = pixelColour;
        }
      }
    }
  }
}
void YoloBit::showString(String message, CRGB color)
{
  CRGB matrixBackColor[10][5];
  int mapLED[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
  int messageLength = message.length();

  for (int x = 0; x < messageLength; x++) {
    char myChar = message[x];
    showChar(matrixBackColor, color, 0 , myChar);
    for (int sft = 0; sft <= 5; sft++) {
      for (int x = 0; x < NUM_COLUMNS; x++) {
        for (int y = 0; y < 5; y++) {
          int stripIdx = mapLED[y * 5 + x];
          if (x + sft < 5) {
            ledMatrix[stripIdx] = matrixBackColor[x + sft][y];
          } else {
            ledMatrix[stripIdx] = CRGB(0, 0, 0);
          }
        }
      }
      FastLED.show();
      if (sft == 0) {
        FastLED.delay(500);
      } else {
        FastLED.delay(200);
      }
    }
  }
}

void YoloBit::showString(String message)
{
    showString(message, CRGB::Red);
}

void YoloBit::showNumber(int number, CRGB color)
{
  showString(String(number), color);
}

void YoloBit::showNumber(int number)
{
    showString(String(number), CRGB::Red);
}

void YoloBit::showNumber(float number, CRGB color)
{
    char message[8];
    dtostrf(number, 5, 2, message); /*Double converted to string*/
    showString(String(message), color);
}

void YoloBit::showNumber(float number)
{
    showNumber(number, CRGB::Red);
}

void YoloBit::showImage(const byte data[], CRGB color)
{
    for (int c = 0; c < 5; c++){
        for (int r = 0; r < 5; r++){
            if (bitRead(data[c], r)){
                ledMatrix[c * 5 + 4-r] = color;
            }
            FastLED.show();
            delay(5);
        }
    }
}

void YoloBit::showColor(CRGB color)
{
    for (int c = 0; c < 5; c++){
        for (int r = 0; r < 5; r++){
              ledMatrix[c * 5 + r] = color;
        }
    }
    FastLED.show();
}

void YoloBit::clearLed()
{
    FastLED.clear();
    FastLED.show();
}

void YoloBit::setBrightness(int value)
{
    if (value < 0 || value > 255)
        return;
    brightness = value;
    FastLED.setBrightness(value);
}

int YoloBit::getLightLevel()
{
    analogReadResolution(10);
    analogSetPinAttenuation(LIGHT_SENSOR, ADC_2_5db);

    int sensorValue = analogRead(LIGHT_SENSOR);
    int lightLevel = 0; 
    analogReadResolution(12);

    if (sensorValue < 50)
        lightLevel = sensorValue * 10; //500
    else if (sensorValue < 150)
        lightLevel = sensorValue * 5; // 700
    else if (sensorValue < 350)
        lightLevel = sensorValue * 2.5; // 800
    else if (sensorValue < 650)
        lightLevel = sensorValue * 1.5; // 900
    else if (sensorValue < 950)
        lightLevel = sensorValue * 1.2; // 1023
    else
        lightLevel = sensorValue * 1.1; // 1023

    if (sensorValue > 1023)
        lightLevel = 1023;
    return int(lightLevel/10.23);

}

float YoloBit::getTemperature()
{
    analogReadResolution(12);
    analogSetPinAttenuation(TEMPERATURE_SENSOR, ADC_11db);

    float Tp = 273.15;
    float T = Tp; // #+ 5 # Normal Temperature Parameters
    float _T = 1 / T;
    float B = 3950;

    int sensorValue = analogRead(TEMPERATURE_SENSOR);

    float Vout = sensorValue * 3.9 / 4095.0;
    if (0 < Vout && Vout < 3.3) { // -26.9 and 160.5
        float Rt = ((3.3 / Vout) - 1) * 0.51; //  Sampling Resistance is 5.1K ohm
        float T1 = 1 / (_T + log(Rt) / B) - Tp;
        return roundf(T1*10)/10;
    } 
    return -1;
}