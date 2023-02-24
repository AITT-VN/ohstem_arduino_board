#ifndef _YOLOBIT_H_
#define _YOLOBIT_H_

#include "Arduino.h"

#include "FastLED.h"
#include "Dots5x5font.h"

class YoloBit {
    public:

        YoloBit(void);
        ~YoloBit(void);

        void showChar(CRGB (*matrix)[5], CRGB color, int x, char character);
        void showString(String message);
        void showString(String message, CRGB color);
        void showNumber(int number);
        void showNumber(int number, CRGB color);
        void showNumber(float number);
        void showNumber(float number, CRGB color);
        void showImage(const byte data[], CRGB color);
        void showColor(CRGB color);
        void setBrightness(int value);
        void clearLed();

        float getTemperature();
        int getLightLevel();

        //bool isButtonAPressed();
        //bool isButtonBPressed();

    private:
        int brightness;
        CRGB currentColor;
        CRGBArray<25> ledMatrix;

};

#endif
