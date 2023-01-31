#include "describe.h"
#include "error.h"

int counting_outlier(float arr[], float mean, float std, int n)
{
    int found_outlier = 0;
    float temp = 0;
    float prob;
    float criterion = 1.0 / (2 * n);

    for (int i = 0; i < n; i++)
    {
        temp = zscore(arr[i], mean, std);
        prob = erfc_diy(temp);
        if (prob < criterion)
        {
            // Serial.println(" Outlier detected : " + String(arr[i]));
            found_outlier += 1;
        }
        else
        {
            continue;
        }
    }

    return found_outlier;
}

bool chauvenet(float x, float mean, float std, int n)
{
    float temp = 0;
    float prob;
    float criterion = 1.0 / (2 * n);
    temp = zscore(x, mean, std);
    // prob = erfc(temp);
    prob = erfc_diy(temp);

    // printf("%f prob %f ", x, prob);
    // printf("prob diy %f ", prob_diy);
    printf("\n");
    if (prob < criterion)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// int main()
// {
//     float mean, std;
//     float *data;
//     float arr[] = {
//         8.02, 8.16, 3.97, 8.64, 0.84, 4.46, 0.81, 7.74, 8.78, 9.26, 20.46, 29.87, 10.38, 25.71};

//     data = data_describe(arr, 14);
//     mean = data[0];
//     std = data[1];

//     for (int i = 0; i < 14; i++)
//     {
//         if (chauvenet(arr[i], mean, std, 14) == false)
//         {
//             printf("val : %f \n", arr[i]);
//         }
//     }
// }