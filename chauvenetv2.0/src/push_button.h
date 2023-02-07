#define PUSH_BUTTON_PIN 12
#include <Arduino.h>

void innit_push_button(int pin)
{
    pinMode(pin, INPUT_PULLUP);
}

bool read_push_button(int pin)
{
    bool temp = digitalRead(pin);
    Serial.println(temp);
    return temp;
}
