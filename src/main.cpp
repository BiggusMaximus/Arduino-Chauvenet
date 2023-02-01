#include "read.h"
#include "remove_outlier.h"
#include "measure_time.h"

float mean, standard_deviation;
float *data, *array_chauvenet, *array_volt;
int *index_outlier;
int N = 50;
unsigned long t1, t2, t3, elapsed1, elapsed2;

void setup()
{
  Serial.begin(115200);
  pinMode(VOLT_PIN, INPUT);

  t1 = millis();
  array_volt = read_voltage_calibration_array(VOLT_PIN);
  data = data_describe(array_volt, N);
  mean = data[0];
  standard_deviation = data[1];
  Serial.println(
      "mean : " + String(mean) +
      " std : " + String(standard_deviation));

  t2 = millis();
  remove_outliers(array_volt, standard_deviation, mean, N);
  t3 = millis();
  elapsed2 = t2 - t1;
  elapsed2 = t3 - t1;
  Serial.println(elapsed1);
  Serial.println(elapsed2);
}

void loop()
{
  // float volt = read_voltage_calibration(VOLT_PIN);
  // Serial.println(volt, 5);
}