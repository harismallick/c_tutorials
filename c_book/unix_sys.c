#include <stdio.h>
#include <stdint.h>

int main(void)
{
    char arr[] = "hello world";
    char *cP = arr;
    while (*cP != '\0')
    {
        printf("%c\n", *cP++);
    }

    uint8_t num = 0b00001000;
    // & has lower precedence than ==
    // Must put the bitwise operation in parenthesis to work correctly.
    
    if ((num & 0b00001000) == 8)
        printf("Byte to decimal: %d\n", num);
    return 0;
}