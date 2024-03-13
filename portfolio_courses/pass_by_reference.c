#include <stdio.h>

// The most common way to pass arguments to a function is to pass-in the variable directily.
// But, C offers the ability to pass in a pointer to a variable, rather than the variable.
// This is known as pass by reference.

void add_one(int *a);
void add_one_to_array(int *array, int size);

int main() {
    int b = 5;
    add_one(&b); // Passing in the pointer to b, rather than b itself
    printf("b = %d\n", b);

    int array[] = {1,2,3,4,5};
    int length = sizeof(array)/sizeof(array[0]);
    add_one_to_array(array, length);
    for(int i = 0; i < length; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    // Array notation:
    int *pArray = array; // points to the first element in the array. No need to use '&'
    printf("%d\n", array[2]);
    printf("%d\n", pArray[2]); // Shifts the pointer by 2 and displays the dereferenced value at that memory address.
    printf("%p\n", array);
    printf("%p\n", pArray);

    // Pointer notation:
    printf("Value at position 3 is: %d\n", *(pArray + 2));
    // Whats happening here is that you increment the memory address to which the pointer is pointing. Then dereference to get the value.
    // Example of pointer arithmetic:
    int size_2 = (pArray + length) - (pArray + 2);
    add_one_to_array(pArray+2, size_2);
    // In this example, using pointers and pointer arithmetic, we only changed the values of the last 3 elements in the array.

    return 0;
}

void add_one(int *a) {
    *a = *a + 1;
}
void add_one_to_array(int *array, int size) {
    for(int i = 0; i < size; i++) {
        array[i] += 1;
        printf("Pointer arithmetic: %d\n", *(array + i));
    }
}

