#include <stdio.h>

int main() {
    // The six standard bitwise operators across most programming languages are:
    // & - AND operator
    // | - OR operator
    // ^ - XOR operator
    // << - Left shift by 1 bit
    // >> - Right shift by 1 bit
    // ~ - The complement operator. It flips all the bits, ie, 0s become 1s and 1s become 0s.

    int x = 6;  // 00000110
    int y = 12; // 00001100
    int z = 0;  // 00000000

    // & operator will compare two bits and if both bits are 1 and 1, the output is 1.
    z = x & y; // should be 00000100, which is 4
    printf("Result of & is: %d\n", z);

    z = x | y; // should be 00001110, which is 14
    printf("Result of | is: %d\n", z);

    z = x ^ y; // should be 00001010, which is 10
    printf("Result of ^ is: %d\n", z);

    z = x >> 1; // Right shifting bits is dividing the base 10 integer by 2.
    printf("x right shifted = %d\n", z);

    z = x << 1; // Left shifting bits is multiplying the base 10 integer by 2.
    printf("x left shifted = %d\n", z);

    z = ~x;
    printf("The complement of x is: %d\n", z);

    return 0;
}