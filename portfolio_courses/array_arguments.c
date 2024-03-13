#include <stdio.h>

// When allocating memory to a function, C tends to use contiguous or nearby memory addresses for the function's variables.

void print_array(int arr[], int size);
void pointer_demo(void);

int main() {

    int nums[] = {1,2,3,4,5};
    printf("Memory address of initialised array:\n%p\n", &nums);
    int size = sizeof(nums) / sizeof(nums[0]);
    print_array(nums, size);
    // This example shows that when arrays are passed as arugments in a function, its their memory address being passed.
    // Unlike datatypes like int, float, char, where the actual value stored in the variable is passed into the function.
    // This is known as decay. When an array is passed as an argument to a function, it 'decays' to a pointer pointing to the memory address of said array.
    
    pointer_demo();
    return 0;
}

void print_array(int arr[], int size) {

    printf("Memory address of passed in array:\n%p\n", arr);
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}
void pointer_demo(void) {
    int a = 5;
    int *pA = &a;

    // manipulating the value stored in a variable directly:
    a = a + 1;
    printf("a = %d\n", a);

    // manipulating values stored in variable by manipulating the dereferenced pointer:
    *pA = *pA + 1;
    printf("*pA or a = %d\n", *pA);
}
