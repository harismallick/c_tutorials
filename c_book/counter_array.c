#include <stdio.h>

#define DIGITS 10

int main()
{

    int ndigits[DIGITS] = {0};
    int c, i, nwhite, nother;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ndigits[c - '0']++; // ASCII subtraction
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            nwhite++;
        }
        else
        {
            nother++;
        }
    }

    printf("Count of each digit 0-9:\n");
    for (i = 0; i < DIGITS; i++)
    {
        printf("%d ", ndigits[i]);
    }
    printf("\nWhitespaces: %d\nOther: %d\n", nwhite, nother);

    return 0;
}