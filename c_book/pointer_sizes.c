#include <stdio.h>

void pointer_tests(void);

int main()
{
    char letter = 'a';
    char *cP;
    int *iP;
    void *vP;
    double *dP;
    long long int *lP;

    printf("Size of char pointer:\t%lu\n", sizeof(cP));
    printf("Size of int pointer:\t%lu\n", sizeof(iP));
    printf("Size of void pointer:\t%lu\n", sizeof(vP));
    printf("Size of double pointer:\t%lu\n", sizeof(dP));
    printf("Size of long pointer:\t%lu\n", sizeof(lP));

    printf("Size of char:\t%lu\n", sizeof(letter));
    pointer_tests();
    return 0;
}

void pointer_tests(void)
{
    int num = 10;
    int *pNum = &num;

    // Arithmetic operations using pointers:
    *pNum = *pNum + 1;
    printf("Value of num: %d\n", num);
    // This also works:
    *pNum += 1;
    printf("Value of num: %d\n", num);

    // Pointers and arrays

    int arr[5] = {0,1,2,3,4};
    // Declare pointer to point to first element in the array:
    // int *pArr = &arr[0]; // or:
    int *pArr = arr;
    // Different ways of accessing elements inside an array:
    printf("%d\n", arr[2]);
    printf("%d\n", *(arr + 2));
    printf("%d\n", *(pArr + 2));

}