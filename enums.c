#include <stdio.h>

// enum - Its like a dictionary of key-value pairs, but for the integer datatype ONLY.
// It consists of constant integrals or integers that are given names by a user. 
// It is used help with the readability of the code.

enum Day{
    Sun = 1,
    Mon = 2,
    Tue = 3,
    Wed = 4,
    Thu = 5,
    Fri = 6,
    Sat = 7
};

int main() {

    enum Day today = Sat;

    if(today == Sat || today == Sun) {
        printf("Its the weekend!");
    }
    else {
        printf("Its a weekday, so gotta work.");
    }
    printf("\n");
    
    return 0;
}