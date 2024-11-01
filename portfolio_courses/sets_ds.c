#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

// Source: https://www.youtube.com/watch?v=RVqdK6WAjUI&list=PLUNSJLxa5Bo45-NK7icehlzf5aV-S8F3g&index=127
// Only working with integers in this example

typedef struct {
    int *members;
    int length;
} Set;

Set *init();
bool is_empty(Set *set);
void insert(Set *set, int member);
void free_set_memory(Set *set);
void print_set(Set *set);
Set *set_union(Set *setA, Set *setB);
Set *set_intersection(Set *setA, Set *setB);
Set *set_diff(Set *setA, Set *setB);
bool is_subset(Set *setA, Set *setB);
bool is_equal(Set *setA, Set *setB);
bool is_member(Set *setA, int num);

int main(void) 
{
    Set *setA = init();
    if (is_empty(setA)) printf("The set is empty.\n");
    else printf("The set is not empty.\n");

    insert(setA, 5);
    insert(setA, 6);
    insert(setA, 7);
    insert(setA, 8);
    printf("Set A:\t\t");
    print_set(setA);

    // create another set
    Set *setB = init();
    insert(setB, 7);
    insert(setB, 8);
    insert(setB, 9);
    insert(setB, 10);
    printf("Set B:\t\t");
    print_set(setB);

    Set *union_AB = set_union(setA, setB);
    printf("Union AB:\t");
    print_set(union_AB);

    Set *intersect_AB = set_intersection(setA, setB);
    printf("Set intersect:\t");
    print_set(intersect_AB);

    Set *diff_AB = set_diff(setA, setB);
    printf("Diff A-B:\t");
    print_set(diff_AB);
    
    Set *diff_BA = set_diff(setB, setA);
    printf("Diff B-A:\t");
    print_set(diff_BA);

    bool a_subset_b = is_subset(setA, setB);
    if (a_subset_b)
        printf("SetA is a subset of setB\n");
    else 
        printf("SetA is not a subset of setB\n");

    bool is_a_equal_b = is_equal(setA, setB);
    printf("SetA equal to setB? %s\n", is_a_equal_b ? "True":"False");

    int search = 5;
    bool is_search_in_set = is_member(setA, search);
    printf("Is %d in setA? %s\n", search, is_search_in_set ? "True":"False");

    free_set_memory(setA);
    free_set_memory(setB);
    free_set_memory(union_AB);
    free_set_memory(intersect_AB);
    free_set_memory(diff_AB);
    free_set_memory(diff_BA);
    return 0;
}

Set* init()
{
    // Initialise a set
    Set *new_set = malloc(sizeof(Set));
    new_set->length = 0;
    new_set->members = malloc(sizeof(int));
    return new_set;
}

void insert(Set *set, int member)
{
    bool in_set = false;

    for (int i = 0; i < set->length; i++)
    {
        if (set->members[i] == member)
        {
            in_set = true;
        }
    }
    if (!in_set)
    {
        set->members = realloc(set->members, sizeof(int) * (set->length + 1));
        set->members[set->length] = member;
        set->length = set->length + 1;
    }
}

void print_set(Set *set)
{
    printf("{");
    for (int i = 0; i < set->length-1; i++)
    {
        printf("%d, ", set->members[i]);
    }
    printf("%d", set->members[set->length - 1]);
    printf("}\n");
}
bool is_empty(Set *set)
{
    return (set->length == 0);
}


Set *set_union(Set *setA, Set *setB)
{
    Set *new_set = init();
    for (int i = 0; i < setA->length; i++)
    {
        insert(new_set, setA->members[i]);
    }

    for (int i = 0; i < setB->length; i++)
    {
        insert(new_set, setB->members[i]);
    }
    return new_set;
}

void free_set_memory(Set *set)
{
    free(set->members);
    // free(set->length);
    free(set);
}

Set *set_intersection(Set *setA, Set *setB)
{
    Set *intersection = init();
    for (int i = 0; i < setA->length; i++)
        for (int j = 0; j < setB->length; j++)
            if (setA->members[i] == setB->members[j])
                insert(intersection, setA->members[i]);
    
    return intersection;
}

Set *set_diff(Set *setA, Set *setB)
{
    Set *diff = init();
    bool match = false;
    for (int i = 0; i < setA->length; i++)
    {
        for (int j = 0; j < setB->length; j++)
            if (setA->members[i] == setB->members[j])
                match = true;
        
        if (!match)
            insert(diff, setA->members[i]);
        match = false;
    }
    return diff;
}

bool is_subset(Set *setA, Set *setB)
{
    if (setA->length > setB->length)
        return false;

    int count_both_sets = 0;
    for (int i = 0; i < setA->length; i++)
    {
        for (int j = 0; j < setB->length; j++)
        {
            if (setA->members[i] == setB->members[j])
                count_both_sets++;
        }
    }
    if (count_both_sets == setA->length)
        return true;
    return false;
}

bool is_equal(Set *setA, Set *setB)
{
    if (setA->length != setB->length)
        return false;
    else
        return is_subset(setA, setB);
}
bool is_member(Set *setA, int num)
{
    for (int i = 0; i < setA->length; i++)
    {
        if (setA->members[i] == num)
            return true;
    }
    return false;
}