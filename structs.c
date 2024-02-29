#include <stdio.h>
#include <string.h>

// Struct - Its short for structure and used to refer to a collection of related variables.
// DIfferent data types can be stored inside a struct
// Each struct is listed under one name in a block of memory.
// Very similar to classes, but structs cannot store functions.
// So, while there are instance variables, there are no instance methods.

// Declare the struct like a class with init variables.
// Then create an instance of the struct.
// struct variables can be assigned and changed using dot notation.
struct Player {
    char name[25];
    int score;
};

typedef struct {
    char* name;
    float gpa;
} StudentGrade;

StudentGrade createStudent(char* name, float gpa);
void printArray(StudentGrade* students, int arrSize);

int main() {
    struct Player player1;
    struct Player player2;

    // Set intance values for each Player instance:

    player1.score = 4;
    strcpy(player1.name, "John"); // string copy function must be used to assign/edit string variables in the struct.

    strcpy(player2.name, "Jane");
    player2.score = 5;

    printf("Player name: %s\n", player1.name);
    printf("%s's score: %d\n", player1.name, player1.score);

    StudentGrade student1 = createStudent("Spongebob", 3.0);
    StudentGrade student2 = createStudent("Patrick", 2.0);
    StudentGrade student3 = createStudent("Sandy", 4.0);
    StudentGrade student4 = createStudent("Squidward", 2.5);

    // printf("%s\n", student1.name);
    // printf("%0.1f\n", student1.gpa);
    StudentGrade studentArr[] = {student1, student2, student3, student4};
    int arrSize = sizeof(studentArr)/sizeof(studentArr[0]);
    printArray(studentArr, arrSize);

    return 0;
}

StudentGrade createStudent(char* name, float gpa) {
    StudentGrade instance = {name, gpa};
    return instance;
}

void printArray(StudentGrade* students, int arrSize) {
    for(int i=0; i < arrSize; i++) {
        printf("%-12s\t%.1f", students[i].name, students[i].gpa);
        printf("\n");
    }
}