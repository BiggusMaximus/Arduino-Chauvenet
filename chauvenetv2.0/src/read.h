#define VOLT_PIN A5

float *read_voltage_calibration_array(int pin, int n)
{
    static float data[100] = {};

    for (int i = 0; i < n; i++)
    {
        data[i] = 0.05849091372411075 + 0.02989 + 0.024388004366555764 * (float)analogRead(pin);
        // delay(10);
        // Serial.println(data[i], 2);
    }
    return data;
}
void read_voltage_calibration(int pin)
{
    float sum = 0;
    for (int i = 0; i < 100; i++)
    {
        sum += 0.06449091372411075 + 0.03159 + 0.024386004366555764 * (float)analogRead(pin);
    }
    sum = sum / 100.0;
    Serial.println(sum);
}