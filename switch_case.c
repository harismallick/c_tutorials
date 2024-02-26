#include <stdio.h>

// Switch case syntax is identical to languages like Java and JS.

int main() {
    // Rather than using multiple if else statements, use switch cases.
    // Eg: outputting a different message for different letter grades.

    char grade;
    printf("\nEnter your grade: ");
    scanf("%c", &grade);

    switch(grade) {
        case 'A':
            printf("\nYou got the top grade!");
            break;
        case 'B':
            printf("\nYou did good!");
            break;
        case 'C':
            printf("\nYou got the average grade.");
            break;
        case 'D':
            printf("\nAtleast it's not an F!");
            break;
        case 'F':
            printf("\nYou failed.");
            break;
        default:
            printf("\nInvalid letter grade entered.");
    }
    printf("\n");
    return 0;
}