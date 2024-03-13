#include <stdio.h>
#include <string.h> // This library contains functions for string manipulation
#include <ctype.h>  // This library is for the manipulation of the char datatype. Includes functions like toupper() and tolower()

// char arrays used to store strings always end in the null terminator - '\0'
// All char arrays representing a string end with this null terminator.
// This special character is not printable.
int main() {
    // One way to declare a string char array:
    char s1[5];
    s1[0] = 'a';
    s1[1] = 'b';
    s1[2] = 'c';
    s1[3] = 'd';
    s1[4] = '\0';

    printf("%s\n", s1);
    // The easier way to declare a string:
    char s2[] = "This is my string";
    // When initialising a string this way, no need to declare size of the array, and no need to add the null terminator;
    // Compiler automatically adds the '\0' to the char array of strings.

    printf("%s\n", s2);
    // Can add an if condition to check for the '\0' and print something user defined:
    for(int i = 0; i < sizeof(s2); i++) {
        if(s2[i] == '\0') {
            printf("s2[%d] = \\0\n", i);
        }
        else {
            printf("s2[%d] = %c\n", i, s2[i]);
        }
    }
    // The fact that strings end with '\0' can be used to loop through strings in a certain way:
    int i = 0;
    while(s2[i] != '\0') {
        if(s2[i] == 's') {
            printf("Found letter s.\n");
        }
        i++;
    }

    return 0;
}