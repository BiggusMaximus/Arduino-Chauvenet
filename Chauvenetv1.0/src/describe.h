#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *data_describe(float arr[], int n)
{
    float mean, var, sum;
    mean = var = sum = 0.0;
    static float data[3];

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
    data[0] = mean;
    data[1] = sqrt(var / (n - 1));
    data[2] = n;

    return data;
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
