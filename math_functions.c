#include <stdio.h>
#include <math.h>

// Covering some useful math functions using standard C library.
// When compiling C files using the math library, add -lm to the compile instruction:
// gcc <C_filemane> -o <C_bin_name> -lm
// This is because gcc does not include the math library by default when linking:
// https://stackoverflow.com/questions/10409032/why-am-i-getting-undefined-reference-to-sqrt-error-even-though-i-include-math

double circle_circumference(float radius) {
    double circumference;
    const double PI = 22.0/7;
    // float radius = 3;

    circumference = 2 * PI * radius;
    return circumference;
}

double circle_area(float radius) {
    double area;
    const double PI = 22.0/7;
    // float radius = 3;

    area = PI * radius * radius;
    return area;
}

double hypotenuse(float height, float base) {
    double answer = sqrt((height*height)+(base*base));
    return answer;
}

int main() {
    // After importing the math library, certain functions become available to us.
    double A = sqrt(9);
    double B = pow(2, 4);
    int C = round(3.14);
    int D = floor(3.99); // floor always rounds to the lower integer value.
    int E = ceil(3.14); // ceiling rounds to the higher integer value.
    double F = fabs(-123);
    double G = log(3);
    double H = sin(0.523599);
    double I = cos(30);
    double J = tan(30);
    // for sin cos tan, enter value in radians, not degrees!

    printf("\nSquare root is: %lf", A);
    printf("\nResult of exponential is: %lf", B);
    printf("\nThe rounded number is: %d", C);
    printf("\nThe number rounded to floor is: %d", D);
    printf("\nThe number rounded to ceiling is: %d", E);
    printf("\nThe absolute real number is: %lf", F);
    printf("\nThe log value is: %lf", G);
    printf("\nThe sin is: %lf", H);
    printf("\nThe cos is: %lf", I);
    printf("\nThe tan is: %lf", J);
    printf("\nResult of circumference calculation:");
    float radius = 3.5;
    double circum = circle_circumference(radius);
    double area = circle_area(radius);
    printf("\nThe circumference of circle with %f cm radius is: %lf", radius, circum);
    printf("\nIts area is %lf cm squared.", area);
    float height = 4.0;
    float base = 3.0;
    double hypot = hypotenuse(height, base);
    printf("\nThe hypotenuse of %f and %f is: %lf", height, base, hypot);
    printf("\n");

    return 0;
}