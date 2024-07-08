#include <stdio.h>

void pointer_tests(void);
char *string_copy(char *s, char *d);
void string_copy2(char *s, char* d);
void print_func(int x);
double add_floats(double x, double y);

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

    void (*func_pointer)(int);
    func_pointer = print_func;
    // Calling a function using a pointer:
    (*func_pointer)(5);

    double (*p_add_float)(double, double) = add_floats;
    // Don't need to dereference function pointer when calling function using pointer
    double result = p_add_float(30.0, 40.0);
    printf("Add float result: %0.2f\n", result);

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

    char source[] = "Hello world";
    char dest[25];
    printf("Original: %s\n", source);
    printf("Dest start: %s\n", dest);
    string_copy2(source, dest);
    printf("Dest after cp: %s\n", dest);
    
}

char *string_copy(char *s, char *d)
{
    char *p = d;
    while (*s != '\0')
    {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
    return p;
}

// String copy function in 2 lines of code as in the C book:
void string_copy2(char *s, char* d)
{
    while (*d++ = *s++)
        ;
}

void print_func(int x)
{
    printf("Executing function using pointer: %d\n", x);
}

double add_floats(double x, double y)
{
    return x + y;
}