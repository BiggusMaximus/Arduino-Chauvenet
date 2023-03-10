#include <Arduino.h>
#define VOLT_PIN A5

float *read_voltage_calibration_array(int pin, int n)
{

    static float data[250] = {};

    for (int i = 0; i < n; i++)
    {
        data[i] = 0.06449091372411075 - 0.05 + 0.024386004366555764 * analogRead(pin);
        // delay(10);
        // Serial.println(data[i], 2);
    }
    return data;
}
float read_voltage_calibration(int pin)
{
    return 0.06449091372411075 + 0.024386004366555764 * (float)analogRead(pin);
}