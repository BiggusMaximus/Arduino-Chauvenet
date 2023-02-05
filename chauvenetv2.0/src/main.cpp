#include <Arduino.h>
#include "describe.h"
#include "read.h"
#include "sorting.h"
#include "measure_time.h"
#include "error_prob.h"
#include "chauvenet.h"
#include "remove_outlier.h"

unsigned long t1, t2, t3, elapsed1, elapsed2;
const int SAMPLE_SIZE = 100;
float *voltage_array;
float temp_mean, temp_std;
int temp_N;
int count = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(VOLT_PIN, INPUT);

  //float voltage_array[] = {8.02, 8.16, 3.97, 8.64, 0.84, 4.46, 0.81, 7.74, 8.78, 9.26, 20.46, 29.87, 10.38, 25.71};
  t1 = millis();
  voltage_array = read_voltage_calibration_array(VOLT_PIN, SAMPLE_SIZE);
  Serial.println("Iteration : " + String(count) + "  Outlier : " + String(count_outlier) + "  Forward : " + String(forward) + "  Backward : " + String(backward));
  quickSort(voltage_array, 0, SAMPLE_SIZE - 1);
  data_describe(voltage_array, SAMPLE_SIZE);
  // printArray(voltage_array, SAMPLE_SIZE);
  remove_outlier(voltage_array, mean, standard_deviation, SAMPLE_SIZE);
  slice(voltage_array, forward - 1, backward);

  count += 1;
  while (count_outlier != 0.0)
  {
    Serial.println("Iteration : " + String(count) + "  Outlier : " + String(count_outlier) + "  Forward : " + String(forward) + "  Backward : " + String(backward));
    data_describe(voltage_array, backward - forward);
    remove_outlier(voltage_array, mean, standard_deviation, backward - forward);
    slice(voltage_array, forward - 1, backward);
    count += 1;
    if (count_outlier == 0){
      voltage_array[0] = '\0';
      break;
    }else{
      continue;
    }
  }
  t2 = millis();
  measure_times(t2 - t1);
}

void loop()
{
  //read_voltage_calibration(VOLT_PIN);
  // put your main code here, to run repeatedly:
}