#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    double fahr, celsius;

    printf("Fahr\tCelcius\n");
    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        celsius = (5.0 * (fahr - 32)) / 9.0;
        printf("%3.0f %10.2f\n", fahr, celsius);
    }
    return 0;
}