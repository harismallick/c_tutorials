#include <stdio.h>
#include <ctype.h>

int main() {
    char temp_unit;
    float temp;
    float converted_temp;

    printf("\nIs the temperature in F or C?: ");
    scanf("%c", &temp_unit);

    temp_unit = toupper(temp_unit); // If unit entered in lowercase.

    if(temp_unit == 'C' || temp_unit == 'F') {
        printf("\nEnter the temperature value to convert: ");
        scanf("%f", &temp);
        if(temp_unit == 'C') {
            converted_temp = (temp * 9/5) + 32;
            printf("\n%0.1f C is %0.1f F", temp, converted_temp);
        }
        else {
            converted_temp = ((temp - 32) * 5)/9;
            printf("\n%0.1f F is %0.1f C", temp, converted_temp);
        }
    }
    else {
        printf("\nIncorrect unit of temperature entered.");
    }
    printf("\n");
    return 0;
}