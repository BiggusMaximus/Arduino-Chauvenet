#include "chauvenet.h"

int *find_index_outlier(float arr[], float std, float mean, int n)
{
    // Serial.println("N : " + String(n));
    static int data[50];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (chauvenet(arr[i], mean, std, n) == true)
        {
            // Serial.println(
            //     "Outlier " + String(arr[i]) +
            //     " in index : " + String(i) +
            //     " count " + String(count));
            data[count] = i;
            count += 1;
        }
        else
        {
            continue;
        }
    }

    return data;
}

void remove_outliers(float arr[], float std, float mean, int n)
{
    int *index_outlier;
    static float array_chauvenet[50];
    float *data;
    int count, pass = 0;
    int outlier_found = counting_outlier(arr, mean, std, n);
    while (outlier_found != 0)
    {
        Serial.println(
            "pass - " + String(pass) +
            " mean : " + String(mean) +
            " std : " + String(std) +
            " N : " + String(n));
        index_outlier = find_index_outlier(arr, mean, std, n);
        count = 0;
        for (int i = 0; i < outlier_found; i++)
        {
            for (int j = index_outlier[i] - count; j < n - count; j++)
            {
                arr[j] = arr[j + 1];
            }

            count = count + 1;
            n--;
        }

        data = data_describe(arr, n);
        mean = data[0];
        std = data[1];

        pass += 1;
        outlier_found = counting_outlier(arr, mean, std, n);
    }
    Serial.println(
        "pass - " + String(pass) +
        " mean : " + String(mean) +
        " std : " + String(std) +
        " N : " + String(n));

    for (int i = 0; i < n; i++)
    {
        array_chauvenet[i] = arr[i];
        Serial.println(array_chauvenet[i], 2);
    }
    Serial.println("end");
}
