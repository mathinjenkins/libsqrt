#include<sqrt/sqrt.h>
#include<exponent/exponent.h>

float CalculateSqrt(float number, int precision) {
    // get a rough estimation first
    int n = 1;
    int power = n;
    float a = number;
    while ((number / CalculateExponent(10, power)) > 1) {
        a = number / CalculateExponent(10, power);
        n++;
        power = CalculateExponent(n, 2);
    }
    n--;

    float x;
    if (a < 10) {
        //x0
        x = 2 * CalculateExponent(10, n);
    } else
    {
        //x0
        x = 6 * CalculateExponent(10, n);
    }
    
    // Babylonian method
    for (int i=0; i<precision; i++) {
        x = 0.5 * (x + number / x);
    }

    return x;

}