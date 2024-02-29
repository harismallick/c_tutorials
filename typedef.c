#include <stdio.h>
#include <string.h>

// typedef = reserved keywork that gives an existing datatype a "nickname"
// This is useful for saving keystrokes when writing code, so syntax can be less verbose

// Example, creating a typedef for a char array with 25 elements:
typedef char user[25];
typedef struct {
    char name[25];
    char password[12];
    int id;
} User;
// Rather than writing "struct User username" everytime, can just type "User username"


int main() {

    user user1 = "John";
    // Rather than declaring char name[25] every time in the file. Keyword u'user' can be used to initialise a char array of 25 elements.

    // This is really useful when declaring and instantiating structs.
    User user2 = {"John Doe", "password123", 1234};

    printf("%s\n", user2.name);
    printf("%s\n", user2.password);
    printf("%d\n", user2.id);
    printf("\n");

    return 0;
}