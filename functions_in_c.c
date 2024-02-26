#include <stdio.h>

// Functions help organise the code into sections. One function for one task
// This helps with debugging and troubleshooting.
// Less lines of code written, as functions help reduce repetition.
// Being a strongly typed language, the datatype of function arguments must be declared.
// variables should only be declared within functions, to maintain local context.
// Global variables should be avoided, as it can lead to incoherent and spagetti code.

void birthday_song() {
    printf("\nHappy birthday to you...");
    printf("\nHappy birthday to you...");
    printf("\nHappy birthday to you...dear YOU");
    printf("\nHappy birthday to you!");
}
void bday_wish(char name[], int age) {
    printf("\nHappy birthday, %s!", name);
    printf("\nYou are now %d years old!", age);
}
double num_squared(double num) {
    return num * num;
}
int main() {
    // birthday_song();
    // birthday_song();
    char name[] = "John";
    int age = 32;
    bday_wish(name, age);

    double number = 9.9;
    double new_num = num_squared(number);
    printf("\n%0.2lf squared is %0.2lf", number, new_num);
    printf("\n");
    return 0;
}