#include <stdio.h>

int main(void)
{
    // Try to access defined variable:
    // num1 = 10;
    // This throws an error

    // Try to access declared variable:
    // It must be defined once after declaration:
    int num2 = 20;
    // This compiles correctly.

    // printf("defined variable: %d\n", num1);
    printf("declared variable: %d\n", num2);

    return 0;
}

// Define after main:
int num1;
// Declare after main:
extern int num2;