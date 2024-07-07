#include <stdio.h>

int main(int argc, char *argv[])
{
    // Treating argv as a pointer to array of pointers to access the arguments:

    while (--argc > 0)
    {
        printf((argc > 1) ? "%s ": "%s", *++argv);
        // Format arguments for printf can be expressions, as shown.
    }
    printf("\n");
    return 0;
}