#include <stdio.h>
#include <string.h>

// How to swap variable values in C.
// Need to declare a temporary variable to store the value of one of the variables during the swap.

int main() {
    // Swapping numbers:
    int a = 5;
    int b = 9;
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("a = %d and b = %d", a, b);
    printf("\n");


    // Swapping string values in variables:
    // This is a bit more intricate, as you need to use the strcpy() function.
    // Also, you must explicitly declare the size of the char array for each variable before the swap.
    // Otherwise it can lead to unexpected behaviour.
    // Example: strcpy(string1, string2); If string2 < string1, then string1 will be blank after the operation.
    // Explicitly declaring the char array size avoids this issue.

    char string1[15] = "Apple";
    char string2[15] = "Kiwi";
    char tempString[15];

    strcpy(tempString, string1);
    strcpy(string1, string2);
    strcpy(string2, tempString);
    printf("string1 = %s and string2 = %s", string1, string2);
    printf("\n");

    return 0;
}