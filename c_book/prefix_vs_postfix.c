#include <stdio.h>

int main()
{
    int m, n;
    m = n = 0;

    // prefix example
    while (m < 10)
    {
        printf("%d ", ++m);
    }
    printf("\n");
    
    // postfix example
    while (n < 10)
    {
        printf("%d ", n++);
    }
    printf("\n");
    return 0;
}