#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game where the user attempts to guess the randomly generated number

int main() {
    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int totalGuesses;
    int answer;
    char bufferClear;

    // Use current time to generate a seed:
    srand(time(0));

    // Generate a random number between the MIN and MAX values:
    answer = (rand() % MAX) + MIN;
    
    do {
        printf("Try to guess the number: ");
        scanf("%d", &guess);
        scanf("%c", &bufferClear);

        totalGuesses++;
        if(totalGuesses == 5) {
            int hint = answer/10;
            if(hint > 0) {
                printf("HINT: Try guessing a number starting with %d\n", hint);
            }
            else {
                printf("HINT: Try guessing a single digit number...\n");
            }
        }
        if(guess > answer) {
            printf("Guess too high! Try a smaller number\n");
        }
        else if( guess < answer) {
            printf("Guess too low! Try a larger number\n");
        }
        else {
            printf("Correct! %d is the answer.\n", answer);
            printf("Total guesses: %d\n", totalGuesses);
        }
    } while(answer != guess);

    printf("\n");
    return 0;
}