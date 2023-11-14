#include "leds.h"

#define LED_NUM_TO_PIN(x) (A2 + x)


/**
 * @brief Sets a led to the given value
 * 
 * @param ledNumber led index, 0-3
 * @param value between 0 and 255
 */
static void _setLedValue(uint8_t ledNumber, int value)
{
    analogWrite(LED_NUM_TO_PIN(ledNumber), value);
}


void initializeLeds()
{
    for (int i = 0; i < 4; i++) pinMode(LED_NUM_TO_PIN(i), OUTPUT);
}

void setLed(uint8_t ledNumber)
{
    if (ledNumber < 0 || ledNumber > 3) return;

    clearAllLeds();
    _setLedValue(0, 255);
}


void clearAllLeds()
{
    for (int i = 0; i < 4; i++) _setLedValue(i, 0);
}

void setAllLeds()
{
    for (int i = 0; i < 4; i++) _setLedValue(i, 255);
}
