#include "remove_outlier.h"

float *quntile(float arr[], float mean, float std, int n)
{
}

float *sorting(float arr[], int n)
{
    float temp;
    static float data_deviation[] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main()
{
    float mean, std;
    int outlier_found = 1;
    int N;

    float arr[] = {
        8.02, 8.16, 3.97, 8.64, 0.84, 4.46, 0.81, 7.74, 8.78, 9.26, 20.46, 29.87, 10.38, 25.71};
    int n = sizeof(arr) / sizeof(arr[0]);

    float *data = sorting(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%f ", data[i]);
    }

    return 0;
}