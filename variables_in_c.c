#include <stdio.h>
#include <stdbool.h> // Must import this library if you wish to use booleans in C

int main() {
    // Primitive data types in C
    int age; // Declaration of variable
    age = 30; // Assignment of variable
    float weight = 74.5; // Declaration + assignment together to initialise
    char grade = 'B'; // Single characters stored as char data type. In single quotes.
    char name[] = "Haris"; //This will create an array of letters for name. There is NO string data type in C

    // To add variables to the printf() function, they must be formatted in.
    // Different data types formatted in using different reserved letters following a '%' symbol.

    printf("Hello %s,\n", name);
    printf("You are %d years old.\n", age);
    printf("You currently weigh %f kgs.\n", weight);
    printf("In the test, you achieved the grade %c\n", grade);

    // short - Stored as 16 bits. (-32,768 to 32,767) - %d to format into string
    // unsigned short - Same as above. 0 to 65,535 decimal number limit. %d to format.
    // int - Stored as 32 bit. If signed, the largest number stored is 2^31 - 1 - '%d' to format into string
    // unsigned int - Stores numbers from 0 to 4,294,967,296. '%u' to format this into a string.
    // long long - Integers Stored as 64 bits. Numbers -9 to 9 quintillion can be stored as a long long. %lld to format into string.
    // unsigned long long - Integers Stored as 64 bits. Numbers 0 to 18 quintillion can be stored as an unsigned long long. %llu to format into string. 

    long long int number = 9000000000000000000;
    unsigned long long int number2 = 17000000000000000000U; // Need to add the U to prevent large number warning while compiling code.
    printf("This is a signed long long: %lld\n", number);
    printf("This is an unsigned long long: %llu\n", number2);

    // Not sticking to the byte limits of the different integer data types will result in overflow, where a short resets to the start if 32,768 stored in it.

    short number3 = 32767;
    printf("Largest number stored in a short: %d\n", number3);
    short number4 = number3 + 1;
    printf("When 1 is added to the above short variable, the result is: %d\n", number4);

    // float - Stores as 32 bit - 6-7 digits of precision - '%f' to format into string
    // double - Stored as 64 bits - 15-16 digits of precision - '%lf' to format
    // Doubles are more precise for more decimal places.
    float pi = 3.142857074737549;
    double pi2 = 3.142857074737549;
    printf("Float pi = %0.15f\n", pi);
    printf("Double pi = %0.15lf\n", pi);

    bool value = true; // boolean stores either true or false. While this needs only 1 bit of memory, it ends up using 1 byte. '%d' to format into string
    printf("Your bool value is: %d\n", value);

    // char - Used to store either the ASCII notation of a letter, or the letter in single quotes. 1 byte in memory (-128 to 127) - %d or %c
    // unsigned char - Used to store a positive number from 0 to 255 - %d or %c
    
    char f = 102;
    printf("ASCII of letter: %d\nActual letter: %c\n", f, f);
    return 0;
}