#include "leds.h"


static uint8_t __pins[4];


/**
 * @brief Get the pin that corresponds to the led number
 * 
 * @param ledNumber led index, 0-3
 * @return pin number
 */
static uint8_t _ledNumToPin(uint8_t ledNumber)
{
    if (ledNumber < 0 || ledNumber > 3) return 0;
    return __pins[ledNumber];
}


/**
 * @brief Sets a led to the given value
 * 
 * @param ledNumber led index, 0-3
 * @param value between 0 and 255
 */
static void _setLedValue(uint8_t ledNumber, int value)
{
    if (ledNumber < 0 || ledNumber > 3) return;
    analogWrite(_ledNumToPin(ledNumber), value);
}


void initializeLeds(uint8_t p0, uint8_t p1, uint8_t p2, uint8_t p3)
{
    __pins[0] = p0; __pins[1] = p1; __pins[2] = p2; __pins[3] = p3;
    for (int i = 0; i < 4; i++) pinMode(_ledNumToPin(i), OUTPUT);
}

void setLed(uint8_t ledNumber)
{
    if (ledNumber < 0 || ledNumber > 3) return;

    clearAllLeds();
    _setLedValue(ledNumber, 255);
}


void clearAllLeds()
{
    for (int i = 0; i < 4; i++) _setLedValue(i, 0);
}


void setAllLeds()
{
    for (int i = 0; i < 4; i++) _setLedValue(i, 255);
}


void testLeds(int timeBetween)
{
    // blink each led in order
    for (uint8_t i = 0; i < 4; i++)
    {
        setLed(i);
        delay(timeBetween);
    }

    // blink all leds twice
    for (int i = 0; i < 2; i++)
    {
        clearAllLeds();
        delay(timeBetween);
        
        setAllLeds();
        delay(timeBetween);
    }
    
    clearAllLeds();
    delay(timeBetween);
}
