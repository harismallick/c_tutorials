#include <stdio.h>
#include <stdbool.h>

int main() {
    // && - For logical AND to check if multiple conditions are true

    float temp = 25;
    bool sunny = true;

    if(temp >= 10 && temp <= 35 && sunny) {
        printf("\nThe weather is good.");
    }
    // C is a 'truthy' language, so no need to write sunny == true. 
    else {
        printf("\nThe weather is bad.");
    }

    // || - For logical OR to check if one of the condition from the list is true.
    int age = 75;
    if(age < 18 || age > 65) {
        printf("\nYou are not of legal working age.");
    }
    else {
        printf("\nYou are of legal working age.");
    }

    // ! - NOT operator. To use this operator in C, must import the stdbool.h library

    int number = 5;
    if(number%2 != 0) {
        printf("\nThe number is odd.");
    }
    else {
        printf("\nThe number is even.");
    }
    printf("\n");
    return 0;
}