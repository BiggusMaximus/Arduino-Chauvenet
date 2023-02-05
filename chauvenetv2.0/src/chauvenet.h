



bool chauvenet(float x, float mean, float std, int n)
{
    float temp = 0;
    float prob;
    float criterion = 1.0 / (2 * n);
    temp = zscore(x, mean, std);
    // prob = erfc(temp);
    prob = erfc_diy(temp);

    // printf("%f prob %f ", x, prob);
    // Serial.println("prob diy " + String(prob));
    if (prob < criterion)
    {
        return true;
    }
    else
    {
        return false;
    }
}