#include <stdio.h>

int main() {
    // format specifier - defines and formats a type of data to be displayed
    // As we've learned so far:
    // %c - Format a char data type
    // %s - Format a char array aka string
    // %d - Format a decimal integer
    // %u - Unsigned integer
    // %lld - long long integer
    // %llu - unsigned long long integer
    // %f - float
    // %lf - double

    // Strings to be output can be formatted in other ways:
    // %0.1 - decimal precision - How many digits after the decimal point
    // %1 - minumum field width
    // %- = Left align

    float item1 = 5.75;
    float item2 = 13.99;
    float total = item1 + item2;

    printf("item1: %8.2f\n", item1); // The 5 right aligns the number by 5 whitespaces. 0.2 is the number of significant figures.
    printf("item1: %-8.2f\n", item2); // The minus left aligns, rather than right align
    printf("item1: %8.2f\n", total);

    return 0;

}