#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

bool freeze_c(int temp);
bool freeze_f(int temp);
void is_freezing(bool (*freeze)(int), int input);

// A common use case for function pointers is to create a callback function.
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: file <temp> <unit>");
        return 1;
    }
    if (tolower(argv[2][0]) == 'c')
        is_freezing(freeze_c, atoi(argv[1]));
    else if (tolower(argv[2][0]) == 'f')
        is_freezing(freeze_f, atoi(argv[1]));
    else
    {
        printf("Invalid unit given. \n");
        return 2;
    }

    return 0;
}
bool freeze_c(int temp)
{
    if (temp <= 0) return true;
    else return false;
}
bool freeze_f(int temp)
{
    if (temp <= 32) return true;
    else return false;
}
void is_freezing(bool (*freeze)(int), int input)
{
    if (freeze(input))
        printf("It's freezing!\n");
    else
        printf("It's not freezing.\n");
}