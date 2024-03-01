#include <stdio.h>
#include <ctype.h>

int main() {

    char questions[][256] = {
        "1. Who is the author of the Harry Potter novels?: ",
        "2. Name the spell used to create light from a wand?: ",
        "3. Who is \"He who must not be named\"?: "
    };

    char options[][100] = {
        "A. JK Rowling", "B. Steven King", "C. Agatha Christie", "D. Charles Dickens",
        "A. alohomora", "B. wingardium leviosa", "C. lumos", "D. avada kedavra",
        "A. Dumbledore", "B. Voldemort", "C. Snape", "D. Grindelwald"
    };

    char answers[3] = {'A', 'C', 'B'};

    int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);
    char guess; // Track their gues to compare to answers
    int score; // Track the player's score
    char bufferClear;

    printf("**Quiz Game**\n");

    // Nested for loops to cycle throught the questions array and each question's 4 options
    for(int i=0; i < numberOfQuestions; i++) {
        printf("*******************\n");
        printf("%s\n", questions[i]);
        printf("*******************\n");

        for(int j = i*4; j < (i*4)+4; j++) {
            printf("%s\n", options[j]);
        }
        printf("Answer: ");
        scanf("%c", &guess);
        scanf("%c", &bufferClear); // buffer clear

        guess = toupper(guess);
        // printf("%c\n", guess);
        if(guess == answers[i]) {
            score++;
        }
    }
    printf("Your score is %d out of %d.\n", score, numberOfQuestions);

    return 0;
}