#include <stdio.h>

#define MAXLINE 1000

int getline2(char* line, int maxline);
// Had to change name of func, as getline() exists in the stdio library.
void copy(char* to, char* from);

int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) // There was a line
    {
        printf("%s\n", longest);
    }

    return 0;
}

int getline2(char* line, int maxline)
{
    int c, i;

    for (i = 0; i < maxline-1 && (c = getchar()) != EOF \
    && c != '\n'; i++)
    {
        *(line + i) = c;
    }
    if (c == '\n')
    {
        *(line + i) = c;
        i++;
    }
    *(line + i) = '\0';
    
    return i;
}

void copy(char* to, char* from)
{
    int i = 0;

    while ((*(to+i) = *(from+i)) != '\0')
    {
        i++;
    }
}