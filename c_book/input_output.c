#include <stdio.h>
#include <stdarg.h>

int sum_nums(int count, ...);
char *read_input(void);

int main()
{
    int sum_result = sum_nums(4, 5,6,7,8);
    printf("Sum: %d\n", sum_result);
    read_input();
    return 0;
}
// Variadic function example:
int sum_nums(int count, ...)
{
    va_list ap; // arguments pointer
    va_start(ap, count); // Initialise pointer to first unnamed arg after the named arg

    int sum, temp;
    sum = 0;
    for (int i = 0; i < count; i++)
    {
        temp = va_arg(ap, int); // Pass the datatype to retrieve
        sum += temp;
    }
    va_end(ap);
    return sum;
}

char *read_input(void)
{
    char input[10];
    char input2[20];
    printf("Enter name: ");
    scanf("%s", input);
    // Try two inputs: "John" and "John Doe"
    printf("Your name is: %s\n", input);
    // Only John is read to the stdout. As whitespace was not formatted into the 
    // string format specifier for scanf, the input is only read to the first whitespace.
    // To avoid this, add whitespace to the formatter.
    
    // Clear the stdin buffer from the previous input:
    int buff_clear;
    while ((buff_clear = getchar()) != '\n')
        ;
    printf("Try again: ");
    scanf("%s %s", input, input2);
    printf("Your name: %s %s\n", input, input2);
}