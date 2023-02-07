
int forward, backward, count_outlier;

void remove_outlier(float arr[], float mean, float std, int n)
{
    backward = forward = count_outlier = 0;

    float criterion = 1.0 / (2 * n);
    for (int i = 0; i < n; i++)
    {
        if (error_prob(arr[i], mean, std, n) > criterion)
        {
            forward = i;
            break;
        }
    }
    for (int i = forward; i < n - 1; i++)
    {

        if (error_prob(arr[n - 1 - i], mean, std, n) > criterion)
        {
            backward = n - i;
            break;
        }
    }

    if ((forward == 0) and (backward == 0))
    {
        count_outlier = 0;
    }
    else
    {

        count_outlier = n - (backward - forward);
    }
    // Serial.println("outlier : " + String(count_outlier));
    // count_outlier = (SAMPLE_SIZE - backward) + forward - 1;
}

// float chauvenet_filter_mean()
// {
//     printArray(voltage_array, SAMPLE_SIZE);
//     Serial.println("Iteration : " + String(count) + "  Outlier : " + String(count_outlier) + "  Forward : " + String(forward) + "  Backward : " + String(backward));
//     quickSort(voltage_array, 0, SAMPLE_SIZE - 1);
//     data_describe(voltage_array, SAMPLE_SIZE);
//     // printArray(voltage_array, SAMPLE_SIZE);
//     remove_outlier(voltage_array, mean, standard_deviation, SAMPLE_SIZE);
//     slice(voltage_array, forward - 1, backward);

//     count += 1;
//     while (count_outlier != 0.0)
//     {
//         Serial.println("Iteration : " + String(count) + "  Outlier : " + String(count_outlier) + "  Forward : " + String(forward) + "  Backward : " + String(backward));
//         data_describe(voltage_array, backward - forward);
//         remove_outlier(voltage_array, mean, standard_deviation, backward - forward);
//         slice(voltage_array, forward - 1, backward);
//         count += 1;
//         if (count_outlier == 0)
//         {
//             voltage_array[0] = '\0';
//             break;
//         }
//         else
//         {
//             continue;
//         }
//     }
// }

// void call_chauvenet()
// {
//     printArray(voltage_array, SAMPLE_SIZE);
//     Serial.println("Iteration : " + String(count) + "  Outlier : " + String(count_outlier) + "  Forward : " + String(forward) + "  Backward : " + String(backward));
//     quickSort(voltage_array, 0, SAMPLE_SIZE - 1);
//     data_describe(voltage_array, SAMPLE_SIZE);
//     // printArray(voltage_array, SAMPLE_SIZE);
//     remove_outlier(voltage_array, mean, standard_deviation, SAMPLE_SIZE);
//     slice(voltage_array, forward - 1, backward);

//     count += 1;
//     while (count_outlier != 0.0)
//     {
//         Serial.println("Iteration : " + String(count) + "  Outlier : " + String(count_outlier) + "  Forward : " + String(forward) + "  Backward : " + String(backward));
//         data_describe(voltage_array, backward - forward);
//         remove_outlier(voltage_array, mean, standard_deviation, backward - forward);
//         slice(voltage_array, forward - 1, backward);
//         count += 1;
//         if (count_outlier == 0)
//         {
//             voltage_array[0] = '\0';
//             break;
//         }
//         else
//         {
//             continue;
//         }
//     }

//     printArray(voltage_array, backward - forward);
//     measure_times(t2 - t1);
// }