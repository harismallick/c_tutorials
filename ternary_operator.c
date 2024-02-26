#include <stdio.h>

// Ternary operator helps reduce simple if-else checks to one line of code.
// The syntax is: (condition) ? if true : if false

int findMax(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int num1 = 5;
    int num2 = 9;
    int max = findMax(num1, num2);
    printf("\nThe max num is: %d", max);
    printf("\n");
    return 0;
}