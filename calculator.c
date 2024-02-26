#include <stdio.h>
// scanf() is a piece of shit.
// If using this function to accept int or float user input, and the user presses Enter.
// This enter press creates a "\n" input which is stored by scanf()
// This \n input can mess up any future inputs.
// So, declare a char datatype variable to "eat" the new line inputs before accepting other inputs.
// Example shown below
// Advice taken from this page: https://stackoverflow.com/questions/34023682/c-cannot-read-string-after-i-read-an-integer

int main() {
    double num1;
    double num2;
    double result;
    char operator;
    char newline; // To eat trailing new lines.

    printf("\nEnter the first number: ");
    scanf("%lf", &num1);
    scanf("%c", &newline);
    printf("\nEnter the second number: ");
    scanf("%lf", &num2);
    scanf("%c", &newline);
    printf("\nEnter the operation to perform (+, -, /, *):");
    scanf("%c", &operator);

    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("\nIncorrect operator given;");
    }
    printf("\n%0.1f %c %0.1f = %0.1lf", num1, operator, num2, result);
    printf("\n");
    return 0;
}