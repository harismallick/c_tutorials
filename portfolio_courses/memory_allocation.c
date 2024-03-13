#include <stdio.h>
#include <stdlib.h> // This library contains functions to allocate and free memory from the heap
#include <string.h>

// int nums[] = {1,2,3,4,5};
// int nums[5];
// Arrays declared in this way cannot be resized. In this example, they will only ever store a max of 5 elements.
// This is because all variables declared in an executable get added to the call stack, where they occupy contiguous memory addresses.
// Lets say nums is occupying memory addresses from 0x00 to 0x20 (as its an int array of 5 elements).
// Then another variable int i = 3; in the stack occupies 0x21 to 0x24.
// If we wanted to resize nums to add another element, this wouldn't be possible as 0x21 to 0x24 memory addresses are occupied.

// To create a re-sizable, or dynamic array, we must dynamically allocate memory to it, from the memory heap.
// You enlarge the array by as many elements as needed and assign memory for it from the heap.
// The new, bigger array will be stored in the newly assigned memory addresses.
// The memory being used for the smaller redundant array can then be freed.
// Such operations can be performed using the malloc() and free() funcitons in the stdlib library.
// Other functions in the library include calloc() and realloc()

typedef struct {
    char firstname[50];
    char lastname[50];
    int age;
} Student;

void dynamic_array_input();
void dynamic_struct_init();
void change_age(Student *s);

int main() {

    int length = 5;
    int *arr = malloc(sizeof(int) * length);
    int *arr2 = calloc(length, sizeof(int));
    // Both these functions can be used to allocate memory for a variable or datastructure.
    // But malloc() doesn't clear the allocated memory addresses of the previously stored data.
    // calloc() ensures all allocated memory addresses are set to 0. Thus, calloc() is more computationally intensive.

    for(int i = 0; i < length; i++) {
        arr[i] = i + 1;
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    free(arr2);
    dynamic_array_input();
    dynamic_struct_init();

    return 0;
}

void dynamic_array_input() {

    int *nums;
    int size = 2;
    nums = malloc(sizeof(int) * size);
    int input = 0, i = 0;

    do {
        if(i == size) {
            size += 2;
            nums = realloc(nums, sizeof(int) * size);
            printf("memory reallocated for %d integers\n", size);
        }
        printf("Enter a number (-1 to quit): \n");
        scanf("%d", &input);
        if(input != -1) {
            nums[i] = input;
            i++;
        }
    } while(input != -1);

    float total = 0;
    for(int j = 0; j < i; j++) {
        total += (float) nums[j];
    }
    printf("The average of input numbers is: %.2f\n", total/i);

    free(nums);
}

void dynamic_struct_init() {
    Student *s1;
    s1 = calloc(1, sizeof(Student)); // allocate memory for n instances of this struct.
    // How do we assign struct variables using pointer notation?
    // Two ways:
    (*s1).age = 25;
    printf("Student's age = %d\n", (*s1).age);
    // while this method helps understand what C is doing under the hood, its not very readable.
    // You dereference the struct instance the pointer is pointing to, then alter its variables.

    // More more readable code, use the '->' syntax. Example below:
    strcpy(s1->firstname, "John");
    strcpy(s1->lastname, "Doe");
    printf("Student's name: %s %s\n", s1->firstname, s1->lastname);

    // When passing in a struct as a reference, its instance variables can be changed:
    change_age(s1);
    printf("Student's age = %d\n", s1->age);

    free(s1);
}

void change_age(Student *s) {
    s->age += 1;
}