#include <Arduino.h>
#include <math.h>

float mean, var, sum, standard_deviation;

void data_describe(float arr[], int n)
{
    mean = var = sum = 0;

    for (int i = 0; i < n; i++)
    {
        // printf("%f \n", arr[i]);
        sum = sum + arr[i];
    }
    mean = sum / (float)n;
    for (int i = 0; i < n; i++)
    {
        var += pow(arr[i] - mean, 2);
    }
    standard_deviation = sqrt(var / (n - 1));
    if (n == 1)
    {
        standard_deviation = 0;
    }
    Serial.println("Mean : " + String(mean) + " Std : " + String(standard_deviation) + " N : " + String(n));
}

float zscore(float x, float mean, float std)
{

    return fabs(x - mean) / std;
}

float find_dmax(float arr[], float mean, float std, float n)
{
    Serial.println(arr[0]);
    float dmax = zscore(arr[0], mean, std);
    for (int i = 0; i < n; i++)
    {
        if (zscore(arr[i], mean, std) > dmax)
        {
            dmax = zscore(arr[i], mean, std);
            Serial.println("Dmax : " + String(dmax));
        }
    }
    return dmax;
}
