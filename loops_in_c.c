#include <stdio.h>
#include <string.h>

void printShape(int length, int height, char symbol);
void breakContinue();

int main() {
    // for loop syntax in C:

    for(int i=0; i<10; i++) {
        printf("\t%d", i);
    }
    printf("\n");

    // while syntax in C:

    char name[25];
    printf("\nEnter your name: ");
    fgets(name, 25, stdin);
    name[strlen(name)-1] = '\0';
    // fgets() adds \n add the end of the input. Remove this by:
    while(strlen(name) == 0) {
        printf("\nYou must enter a name: ");
        fgets(name, 25, stdin);
        name[strlen(name)-1] = '\0';
    }
    printf("\nHi, %s", name);
    printf("\n");

    // do-while loop - It always executes the conditional code atleast once.
    int j = 0;
    do {
        printf("%d\t", j);
        j += 1;
    } while(j < 10);

    // Nested loops example: print shape of user-defined symbol

    int height;
    int width;
    char symbol;
    char bufferClear;

    printf("\nEnter the symbol: ");
    scanf("%c", &symbol);
    printf("\nEnter the height of rectangle: ");
    scanf("%d", &height);
    printf("\nEnter the width of rectangle: ");
    scanf("%d", &width);
    scanf("%c", &bufferClear); // This is to get rid of the \n in buffer
    printf("\n");

    printShape(height, width, symbol);

    breakContinue();

    return 0;
}

void printShape(int height, int width, char symbol) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%c", symbol);
        }
        printf("\n");
    }
}

void breakContinue() {
    // Applying break and continue to loops in C
    // Print only odd numbers up until a limit.

    int i = 0;
    while(i >= 0) {
        if (i % 2 == 0) {
            i++;
            continue;
        } 
        else if(i == 21) {
            break;
        }
        printf("%d\n", i);
        i++;
    }
}