#include "read.h"
#include "remove_outlier.h"
#include "measure_time.h"

float mean, standard_deviation;
float *data, *array_chauvenet, *array_volt;
int *index_outlier;
int N = 250;
unsigned long t1, t2, elapsed;

void setup()
{
  Serial.begin(9600);
  pinMode(VOLT_PIN, INPUT);

  t1 = millis();

  array_volt = read_voltage_calibration_array(VOLT_PIN);
  data = data_describe(array_volt, N);
  mean = data[0];
  standard_deviation = data[1];
  Serial.println(
      "mean : " + String(mean) +
      " std : " + String(standard_deviation));

  // remove_outliers(array_volt, standard_deviation, mean, N);
  t2 = millis();
  elapsed = t2 - t1;
  measure_times(elapsed);
}

void loop()
{
  // float volt = read_voltage_calibration(VOLT_PIN);
  // Serial.println(volt, 5);
}