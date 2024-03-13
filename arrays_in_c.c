#include <stdio.h>
#include <string.h>

// arrays in C are static - ie - you must declare a fixed size for the array.
// Cannot add more elements to an array once its full.
// Must create a new array with more memory allocation.
// arrays are initialised by adding elements inside {} curly brackets.
// Only 1 data type can be stored in the array.

void twoDArray();
void stringArray();

int main() {
    // Initialising the array if all the elements are known
    // In this case, we do not need to declare a size for the integer array.
    // C compiler will be able to determine that based on the number of elements passed in the assignment.
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

    // Iterate through arrays using for loop
    // In C, there is no built-in method to return the length of an array.
    // Length of an array must be calculated using the sizeof() function, which returns size of variable/data-structure in bytes.
    // Divide this by the size of an individual element in the array, to get the length.

    for(int i=0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        printf("%d  ", numbers[i]);
    }
    printf("\n");
    twoDArray();
    stringArray();

    return 0;
}

void twoDArray() {
    // A 2D array is an array of arrays.
    // Its useful for creating matrices, grids, or tables of data.x

    // How to initialise a 2D array:
    int array[][3] = {{1,2,3},{4,5,6}}; // Must declare the max no of elements that will be stored in the subarrays.

    // Assignment and declaration separate:
    int array2[2][3];

    array2[0][0] = 1;
    array2[0][1] = 2;
    array2[0][2] = 3;
    array2[1][0] = 4;
    array2[1][1] = 5;
    array2[1][2] = 6;
    // Must use the 2D indices for assignment.

    // Iterate through a 2D array using nested for loops:

    for(int i=0; i < sizeof(array)/sizeof(array[0]); i++) {
        for(int j=0; j < sizeof(array[0])/sizeof(array[0][0]); j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

}

void stringArray() {
    // To declare an array of strings is analagous to declaring a 2D array.
    // One dimension to store the total number of strings
    // Another dimension to store the array of characters making up each string.
    // Must declare max characters for each string stored in the array:

    char string_list[][15] = {"Apple", "Banana", "Kiwi"};
    // must use strcpy() to change the string at a given index position in the array
    // cannot be changed by simply pointing to the index position

    strcpy(string_list[0], "Orange");

    // A for loop to iterate through the items in the array:
    for(int i=0; i < sizeof(string_list)/sizeof(string_list[0]); i++) {
        printf("%s  ", string_list[i]);
    }
    printf("\n");
}