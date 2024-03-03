#include <stdio.h>

// What is a pointer?
// It is a variable-like reference that holds a memory address to another variable, array, etc.
// Some tasks in C are performed faster using pointers that directly referencing the variable.
/*
Some advantages of pointers include:
    - Less time in program execution
    - Working on the original variable (in place, not creating duplicates)
    - With the help of pointers, we create certain data structures (linked lists, stacks and queues)
    - Return more than one value from a function using pointers
    - Searching and sorting large data easily.
    - Dynamic memory allocation
*/
// The convention for declaring a pointer is to add and asterisk in front of the variable name, and capitalise the first letter.

// Important info about use of pointers in a 2D and 3D array:
// https://www.geeksforgeeks.org/pointer-array-array-pointer/ 
// To move the pointer to a specific memory address in a 2D/3D array, pointer arithmetic must be done.

void age_print_from_pointer(int *pAge) {
    printf("You are %d years old.\n", *pAge);
}

int main() {

    int num = 30;
    int *pNum = &num; // Pointer to the memory address of num

    // Accessing the memory address 2 different ways:
    printf("Memory address using variable: %p\n", &num);
    printf("Memory address using pointer to variable: %p\n", pNum);

    // Accessing the value stored at memory address 2 different ways:
    printf("Get value using variable: %d\n", num);
    printf("Get value using pointer to variable: %d\n", *pNum); // adding the asterisk dereferences the pointer to get value 

    printf("Size of variable is: %lu bytes\n", sizeof(num));
    printf("Size of pointer to variable is: %lu bytes\n", sizeof(pNum));

    // Even though the variable and the pointer to the variable are the same datatype (int), the pointer is 8 bytes, double the size on an int.
    // This is the case in 64-bit machines.

    // pointers can be passed as arguments to functions
    age_print_from_pointer(pNum);

    // How to declare a pointer without assigning a value to it:
    int *pWeight = NULL; // MUST declare an empty pointer, aka a void pointer, this way.
    int weight = 70;
    pWeight = &weight;

    printf("You weigh %d kgs.\n", *pWeight);

    return 0;
}