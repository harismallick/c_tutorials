/*
In this example code, we look at how to return an array from a function.
In C, we can only return single values or pointers from functions.
So, we have to return a pointer to an array from the function.
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5
// Function to return an array of 5 integers given a start value
// The array must be declared in the calling function, and passed as argument to 
// the function that will assign values to it. The return is void for such a function.
void array_func(int start, int *array);

// The alternative to declaring an empty array in the calling function is allocate
// memory in the function being used to create and assign values to the array.
int *array_func2(int start);
void free_mem(int *arr_start);

int main()
{
    int start = 6;
    int array[LENGTH] = { 0 };
    array_func(start, array);
    int *arr_start = array;
    int *arr_end = array + LENGTH - 1;
    printf("Array 1: ");
    while (arr_start <= arr_end)
    {
        printf("%d ", *arr_start);
        arr_start++;
    }
    printf("\n");
    printf("Array 2: ");
    int *array2 = array_func2(start);
    int *arr2_start = array2;
    int *arr2_end = array2 + LENGTH - 1;
    while (arr2_start <= arr2_end)
    {
        printf("%d ", *arr2_start);
        arr2_start++;
    }
    printf("\n");

    free(array2);
    return 0;
}
void array_func(int start, int *array)
{
    for (int i = 0; i < LENGTH; i++)
    {
        array[i] = start;
        start++;
    }
}
int *array_func2(int start)
{
    int *array = malloc(LENGTH * sizeof(int));
    for (int i = 0; i < LENGTH; i++)
    {
        *(array + i) = start;
        start++;
    }
    return array;
}
void free_mem(int *arr_start)
{

}