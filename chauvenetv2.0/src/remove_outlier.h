
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