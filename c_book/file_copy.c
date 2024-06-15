#include <stdio.h>

int main()
{
    int c; // Store the input char from text stream
    long long nc = 0; // Count the number of input chars. This includes escape characters
    int nl = 0; // Count number of lines in the text stream.

    // c = getchar();
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        if (c == '\n')
        {
            nl++;
        }
        nc++;
        // printf("\n");
    }
    printf("%d\n", (c = getchar()) != EOF);
    printf("Number of chars entered: %lld\n", nc);
    printf("Number of lines: %d\n", nl);
    printf("End of while loop.\n");
    return 0;
}