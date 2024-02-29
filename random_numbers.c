#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Can generate pseudo random numbers in C.
// Why is it pseudo? Because generating the random number is dependent on providing a 'seed'.
// The same seed value will produce the same number every time.

int main() {

    // First must generate a seed for the random number:
    srand(time(0)); // Without this seed generator, same number will be generated every time.

    int number1 = (rand() % 6) + 1; //To limit the random number between 1 and 6
    // rand() can generate any number upto the max value of signed int16 -- 32767
    // To limit this number to desired ranges, use the % operator with the divisor set to max desired value.
    // In this example, trying to randomly generate a roll of the dice.
    int number2 = (rand() % 6) + 1;
    int number3 = (rand() % 6) + 1;

    printf("%d\n", number1);
    printf("%d\n", number2);
    printf("%d\n", number3);

    return 0;
}