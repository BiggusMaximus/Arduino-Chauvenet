#include "math.h"
// #include <stdio.h>
// #include <stdlib.h>
#include <Arduino.h>

void measure_times(unsigned long elapsed)
{
    float h, m, s, ms;
    unsigned long over;
    h = int(elapsed / 3600000);
    over = elapsed % 3600000;
    m = int(over / 60000);
    over = over % 60000;
    s = int(over / 1000);
    ms = over % 1000;

    Serial.print("Raw elapsed time: ");
    Serial.println(elapsed);
    Serial.print("Elapsed time: ");
    Serial.print(h, 0);
    Serial.print("h ");
    Serial.print(m, 0);
    Serial.print("m ");
    Serial.print(s, 0);
    Serial.print("s ");
    Serial.print(ms, 0);
    Serial.println("ms");
    Serial.println();
    // printf("Raw elapsed time: %f \n", elapsed);
    // printf("Elapsed time: %fh %fm %fs %fms", h, m, s, ms);
}

void measure_time2()
{
}

// int main()
// {
//     measure_times(10940);
// }