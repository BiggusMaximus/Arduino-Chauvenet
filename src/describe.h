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

double zscore(double x, double mean, double std)
{

    return fabs(x - mean) / std;
}
