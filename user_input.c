#include <stdio.h>
#include <string.h> // Include this library to work with strings in C.

// In this lesson, we cover how to take input from a user.
int main() {
    // Taking string input
    char name[25]; // 25 bytes allocated to storing the name char array.
    // If more than 25 bytes used, it will cause memory overflow.
    printf("\nEnter your name: ");
    // scanf("%s", &name[0]); // Why add the [0]? So compiler doesn't throw error.
    // See this stackoverlfow page: https://stackoverflow.com/questions/16570716/compiler-message-warning-format-s-expects-type-char-but-argument-2-has

    // scanf scans the input string until a whitespace character, then stops.
    // So, if you enter John Doe as your name, scanf will only capture John.
    // To read whitespace inputs from user, need to use fgets() method.

    fgets(name, 25, stdin);
    // fgets() inserts a newline after the user input, which might not be desired.
    // To fix this, some string formatting can be done using string.h module
    name[strlen(name)-1] = '\0'; // This changes the last element in char array from \n to \0

    // Taking integer input
    int age;
    printf("\nEnter your age:");
    scanf("%d", &age); // Point to the memory address of age variable

    // Outputing values
    printf("\nHello %s, How are you?", name);
    printf("\nYou are %d years old.", age);
    printf("\n");
    return 0;
}