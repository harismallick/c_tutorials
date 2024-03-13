#include <stdio.h>
#include <stdlib.h> // using the function in this library called atoi() which converts a string to an integer type.

// When executing complied binaries from the command line, one can pass arguments to the executable.
// These arguments can be used to modify how the binary will be executed.
// For example, gcc -o <name> <c_file>, in this executable, -o is an argument that tells gcc to name the complied binary <name>

// So how can one pass arguments of their own from the CMD?
// need to add two arugments to the main function of the binary:
// int argc -> This is a counter of how many arguments are passed to the executable separated by \s.
// char *argv[] -> This is an array that will store all the strings separated by \s passed as arguments.

int main(int argc, char *argv[]) {

    printf("Total arguments passed into function: %d\n", argc);
    
    if(argc == 3) {
        // argc can be used as the limiter to loop through argv[]
        for(int i = 0; i < argc; i++) {
            printf("argv[%d] = %s\n", i, argv[i]);
        }
        // The first argument stored at argv[0] is always the path of the binary being executed.
        // Need to use the atoi() function (short for 'argument to int')
        int counter = atoi(argv[2]);

        // Typecasting a string to an integer DOES NOT work! The below line will throw an error: //

        // int counter = (int) argv[2];
        // printf("counter value: %d\n", counter);
        for (int j = 0; j < counter; j++) {
            printf("%s\n", argv[1]);
        }
    }
    else {
        printf("Two arguments expected!\n");
        printf("1. The text to show in the terminal.\n");
        printf("2. The number of times to print it.\n");
        return 1;
    }

    return 0;
}