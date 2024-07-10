#include <stdio.h>
#include <string.h>

#define SIZE 5

void structs_example_1();
void nested_structs();

int main()
{
    structs_example_1();
    nested_structs();
    return 0;
}

void structs_example_1()
{
    struct example1 {
        int x;
        char name[SIZE];
    } age, name;
    // defining variables with the struct assigns stack memory to the declaration.
    // In this case, "age" and "name" are two structs declared using the "example1"
    // struct definition. Memory is allocated for them.
    // Structs can also be defined without variable declarations built into the definition.
    // In this case, no memory is allocated.

    int y;
    char name2[SIZE];
    printf("%ld\n", sizeof(age));
    printf("%ld\n", sizeof(name));
    // Both have size of 12 bytes.

    printf("%ld\n", sizeof(y));
    printf("%ld\n", sizeof(name2));

    age.x = 25;
    strcpy(age.name, "foo");
    printf("Age: %d\n", age.x);
    printf("Name: %s\n", age.name);
}
void nested_structs()
{
    struct point {
        int x;
        int y;
    };

    struct rectangle {
        struct point pt1;
        struct point pt2;
    };

    struct rectangle rec_1;
    rec_1.pt1.x = 5;
    rec_1.pt1.y = 5;
    rec_1.pt2.x = 10;
    rec_1.pt2.y = 10;

    int area = (rec_1.pt2.x - rec_1.pt1.x) * (rec_1.pt2.y - rec_1.pt1.y);
    printf("Area of rectangle: %d\n", area);
}