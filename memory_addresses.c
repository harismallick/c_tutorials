#include <stdio.h>

// memory - It is an array of bytes within the RAM
// memory block - It is a single unit (byte) within memory, used to hold some value.
// memory address - It is the address of where a memory block is located.
// memory addresses are in hexadecimal

int main() {
    char a = 'x';
    char b = 'y';
    char c = 'z';

    // As a char variable occupies only 1 byte, we should be able to see its memory address.
    // The string formating notation for memory addresses is %p
    printf("Memory address of %c is %p\n", a, &a);
    printf("Memory address of %c is %p\n", b, &b);
    printf("Memory address of %c is %p\n", c, &c);
    /*
    Memory address of x is 0x7ffd840cea75
    Memory address of y is 0x7ffd840cea76
    Memory address of z is 0x7ffd840cea77
    */

    // These hexadecimal addresses increment based on the size of the datatype, indicating contiguous memory blocks are allocated.

    char arr[5];
    char d[5];
    printf("Memory address of %s is %p\n", arr, &arr);
    printf("Memory address of %s is %p\n", d, &d);

    /*
    Memory address of  is 0x7fff4078974e
    Memory address of  is 0x7fff40789753

    4e, 4f, 50, 51, 52 assigned to arr[5]
    53, 54, 55, 56, 57 assigned to d[5]
    */

    return 0;
}