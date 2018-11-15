// preprocessor directives to include standard input/output and math header files
#include <stdio.h>
#include <math.h>


// declare main function
int main(void)
{
    // declare integer variables to store triangle side lengths
    double side1, side2, side3;

    // prompt user to input side lengths
    printf("Enter the length of side 1: ");
    scanf("%lf", &side1);

    printf("Enter the length of side 2: ");
    scanf("%lf", &side2);

    printf("Enter the length of side 3: ");
    scanf("%lf", &side3);

    // declare integer to store perimeter
    double perimeter = side1 + side2 + side3;

    // declare s, half the perimeter
    double s = perimeter*0.5;

    // declare variable to store area, and calculate area
    double area = sqrt((s * (s - side1) * (s - side2) * (s - side3)));

    // give user some information
    printf("The area of the triangle with sides %.2f, %.2f, and %.2f is %.2f\n",
            side1, side2, side3, area);

    // return error code 0
    return 0;
}