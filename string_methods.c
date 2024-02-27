#include <stdio.h>
#include <string.h>
#include <ctype.h> // This header file contains the toupper() and tolower() functions for char

// covering the different standard string methods available in C
// there's no function in the standard C library to convert a string to lower or upper case.
// There is the ability to convert individual characters to upper or lower case.
// These functions must be looped over the entire string to achieve the desired output.
// Here's an implementation of this from stackoverflow: https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c
// https://blog.hubspot.com/website/string-functions-c


char* toLower(char* s) {
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}

char* toUpper(char* s) {
  for(char *p=s; *p; p++) *p=toupper(*p);
  return s;
}
int main() {
    char string1[] = "John";
    char string2[] = "Doe";

    // toLower(string1); // strlwr() - Converts a given string to lower case. This only works on Windows!
    // // strlwr() not part of the standard C library.
    // printf("\nLower case: %s", string1);

    // toUpper(string1); // strupr() - Works only on Windows! Not part of the standard C library
    // printf("\nUpper case: %s", string1);

    // // strcat(string1, string2);   // strcat() - appends second argument to end of first argument.
    // // printf("\nConcatenated string: %s", string1);

    // strncat(string1, string2, 2); // strncat() - appends 'n' characters from second argument to end of first argument.
    // printf("\nConcatenated string: %s", string1);

    // strcpy(string1, string2);    // This function copies (replaces) all the characters string1 with string2
    // printf("\nCopied string: %s", string1);

    // strncpy(string1, string2, 1); // This function does not replace the entire string1. Only first n characters from string2 replace first n characters of string1
    // printf("\nn Copied string: %s", string1);

    char *substring = strstr(string1, "oh"); // strstr() captures a substring from the first occurrence of the search string
    printf("\nThe substring is : %s", substring);

    // strtok() - this is a split function to break the string by searching for a specified delimiter.
    // strdup() - this function duplicates a string.

    int length = strlen(string1);
    printf("\nLength of string1 is: %d", length);

    int compare = strcmp(string1, string2); // compared two strings for the number of non-identical characters. If identical strings, the output is 0.
    printf("\nResult of string comparison: %d", compare);

    printf("\n");
    return 0;
}