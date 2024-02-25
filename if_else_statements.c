#include <stdio.h>

int main() {
    int age;

    printf("\nEnter your age: ");
    scanf("%d", &age);

    if (age >=18) {
        printf("You are eligible to sign up for a credit card.");
    } else if (age == 0) {
        printf("\nYou were just born!");
    } else {
        printf("\nYou\'re not old enought to apply.");
    }
    printf("\n");
    return 0;
}