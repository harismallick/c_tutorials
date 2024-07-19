#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_SIZE 40

int sum_nums(int count, ...);
char *read_input(void);
void write_file(const char *fname);
void read_file(const char *fname);

int main()
{
    int sum_result = sum_nums(4, 5,6,7,8);
    printf("Sum: %d\n", sum_result);
    // read_input();
    const char *fname = "io_test.txt";
    write_file(fname);
    read_file(fname);
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

void write_file(const char *fname)
{
    FILE *file;
    file = fopen(fname, "w");
    char string[CHAR_SIZE];
    char *temp = (char *) malloc(2 * sizeof(char));
    for (int i = 0; i < 5; i++)
    {
        // fputs for writing string to file:
        strcpy(string, "This is line number: ");
        int tt = i + 1;
        *(temp) = (char) tt + '0'; // This only works for singe digits.
        *(temp + 1) = '\0';
        strcat(string, temp);
        printf("%s\n", string);
        strcat(string, "\n\0");
        fputs(string, file);

        // fprintf for writing line to file:
        fprintf(file, "Line number using fprintf: %d\n", tt);

        // Need to pick the write function for the job. 
        // In this case, fprintf() makes more sense.
    }
    fclose(file);
    free(temp);
}

void read_file(const char *fname)
{
    FILE *file;
    file = fopen(fname, "r");
    char *buffer = (char *) malloc(CHAR_SIZE * sizeof(char));
    // while ((fgets(buffer, CHAR_SIZE, file)) != NULL)
    // {
    //     printf("%s", buffer);
    // }
    size_t bufsize = sizeof(buffer);
    printf("Memory address of buffer: %p\n", &buffer);
    printf("Memory address of buf_size: %p\n", &bufsize);

    // getline() is different from fgets() because it requires passing the 
    // actual memory addresses of the buffer pointer and sizeof buffer.
    while ((getline(&buffer, &bufsize, file)) != EOF)
        printf("%s", buffer);
    fclose(file);
    printf("\n");
    free(buffer);
}