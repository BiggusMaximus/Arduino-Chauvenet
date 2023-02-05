#include <math.h>

float erf_diy(float x)
{

    float erf = ((2 / sqrt(M_PI)) *
                 (x -
                  pow(x, 3) / 3 +
                  pow(x, 5) / (5 * 2) -
                  pow(x, 7) / (7 * 2 * 3) +
                  pow(x, 9) / (9 * 2 * 3 * 4)
                  //   pow(x, 11) / (11 * 2 * 3 * 4 * 5) +
                  //   pow(x, 13) / (13 * 2 * 3 * 4 * 5 * 6)
                  //   pow(x, 15) / (15 * 2 * 3 * 4 * 5 * 6 * 7) +
                  //   pow(x, 17) / (17 * 2 * 3 * 4 * 5 * 6 * 7 * 8) -
                  //   pow(x, 19) / (19 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9)
                  //   pow(x, 21) / (21 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10) -
                  //   pow(x, 23) / (23 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11)
                  //   pow(x, 25) / (25 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12) -
                  //   pow(x, 27) / (27 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13) +
                  //   pow(x, 29) / (29 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14) -
                  //   pow(x, 31) / (31 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15)

                  ));
    // printf("%f => erf : %f\n", x, erf);
    return erf;
}
float erfc_diy(float x)
{
    return 1.0 - erf_diy(x);
}

float error_prob(float x, float mean, float std, int n)
{
    float temp = 0;
    float prob;
    temp = zscore(x, mean, std);
    // prob = erfc(temp);
    prob = erfc_diy(temp);
    //Serial.println("val : " + String(x) + "  prob : " + String(prob));
    return prob;
}