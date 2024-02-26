#include <stdio.h>
// Function prototype

// It is a function declaration without a body, before the main() function.
// Prototypes ensure that calls to a function are made with the correct syntax.
// This is analagous to variable declaration before assignment.
// You declare a function with the desired arguments before the main() function.
// Then you can "assign" a body to this function after the main()
// Its offers a coding style choice.

// NOTES
// Many C compilers do not check for parameter matching. 
// Missing arguments will result in unexpected behaviour.
// This is why its considered good practice to declare all functions and prototypes BEFORE main()
// As code is read procedurally from top to bottom, this makes the compiler aware of all arguments
// required to invoke a function, before the function is called. 

// Advantages of using function prototypes
// 1. Easier to navigate a program file with main() at the top
// 2, Helps with debugging.
// 3. Commonly used in header files.

void hello(char name[], int age);

int main() {
    hello("haris", 32);
    printf("\n");
    return 0;
}

void hello(char name[], int age) {
    printf("\nHello %s, %d years of age.", name, age);
}