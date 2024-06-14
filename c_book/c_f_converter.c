#include <stdio.h>

int main()
{
    double fahr, celsius;
    double lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahr\tCelcius\n");
    for(fahr = lower; fahr <= upper; fahr = fahr + step)
    {
        celsius = (5.0 * (fahr - 32)) / 9.0;
        printf("%3.0f %10.2f\n", fahr, celsius);
    }
    return 0;
}