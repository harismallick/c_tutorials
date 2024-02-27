#include <stdio.h>

// arrays in C are static - ie - you must declare a fixed size for the array.
// Cannot add more elements to an array once its full.
// Must create a new array with more memory allocation.
// arrays are initialised by adding elements inside {} curly brackets.
// Only 1 data type can be stored in the array.

int main() {
    // Initialising the array if all the elements are known
    int numbers[] = {1,2,3,4,5};
    printf("%d", numbers[2]);
    printf("\n");

    // Declaring the array, then adding elements to it later.
    // Must declare a size for the array.

    int numbers2[6];
    numbers2[0] = 40;
    numbers2[1] = 30;
    numbers2[2] = 20;
    numbers2[3] = 60;
    printf("%d", numbers2[2]);
    printf("\n");

    return 0;
}