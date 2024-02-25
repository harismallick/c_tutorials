#include <stdio.h>

int main() {
    // const - Use this reserved word to declare a constant. Its value cannot be changed and the variabled is named using capital letters.

    const float PI = (float) 22/7;
    printf("The value of pi is: %f\n", PI);

    int num1 = 5;
    int num2 = 2;
    float quotient = (float) num1/num2; // If the quotient of two ints results in a float, calculating that float requires converting one of the ints to a float, as shown.
    printf("5 divided by 2 is %0.2f\n", quotient);

    // Augmented assignment operators:
    /*
    += -> Increment by adding a value
    -= -> Decrement by subtracting a value
    *= -> Increment by multiplying a value
    /= -> Decrement by dividing a value
    %= -> Change value to the remainder by dividing by given value
    */
   num1 %= num2;
   printf("%d\n", num1);

    return 0;
}