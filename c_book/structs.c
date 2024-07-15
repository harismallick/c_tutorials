#include <stdio.h>
#include <string.h>

#define SIZE 5
#define TEST sizeof (int)

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point pt1;
    struct point pt2;
};

void structs_example_1();
void nested_structs();
int point_in_rect(struct point, struct rectangle);
void array_pointers(void);

int main()
{
    structs_example_1();
    nested_structs();
    array_pointers();
    // sizeof is a compile-time unary operator/
    // But it can be used in #define because it is not handled by the preprocessor
    // Trying to use test in the code:

    printf("TEST definition: %lu\n", TEST);
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
    struct rectangle rec_1;
    rec_1.pt1.x = 5;
    rec_1.pt1.y = 5;
    rec_1.pt2.x = 10;
    rec_1.pt2.y = 10;

    int area = (rec_1.pt2.x - rec_1.pt1.x) * (rec_1.pt2.y - rec_1.pt1.y);
    printf("Area of rectangle: %d\n", area);

    struct point point_1 = { 6, 6 };
    struct point point_2 = { 12, 4 };
    if (point_in_rect(point_1, rec_1) == 1)
        printf("Point (%d, %d) is inside the rectangle.\n", point_1.x, point_1.y);
    
    if (point_in_rect(point_2, rec_1) == 1)
        printf("Point (%d, %d) is inside the rectangle.\n", point_2.x, point_2.y);

}

int point_in_rect(struct point pt, struct rectangle rec)
{
    return pt.x >= rec.pt1.x && pt.x <= rec.pt2.x && pt.y >= rec.pt1.y &&
            pt.y <= rec.pt2.y;
}

void array_pointers(void)
{
    int array[5] = { 1,2,3,4,5 };
    int *low, *mid, *high;
    low = array;
    high = array + 5;
    mid = low + ((high - low) / 2);
    printf("Low: %d\tHigh: %d\tMid: %d\n", *low, *high, *mid);
}