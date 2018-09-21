#include <stdio.h>
#include <math.h>

/*
 * Author:     Yakir Lebovits
 * Contact:    yakirlebovits@temple.edu
 * Due:        27 September 2018
 * Professor:  Dr. Morris
 *
 * This program takes three inputs, corresponding to triangle side lengths. It
 * then determines if the input sides can form a valid triangle. Next, it
 * calculates the area of the triangle, and determines the type of triangle,
 * based upon the sides. It outputs the validity, area and type (if applicable)
 */

// prototype functions
int is_valid_triangle(double, double, double);
double get_triangle_area(double, double, double);
void get_triangle_type(double, double, double);

int main(void)
{
    // declare variables for later use
    double side1, side2, side3, area;

    // prompt user and get side lenths
    printf("Please enter the length of side 1: ");
    scanf("%lf", &side1);

    printf("Please enter the length of side 2: ");
    scanf("%lf", &side2);

    printf("Please enter the length of side 3: ");
    scanf("%lf", &side3);

    // call function to check if its a valid triangle
    if (!is_valid_triangle(side1, side2, side3))
    {
        printf("No triangle with sides %.2f, %.2f, and %.2f can exist.\n",
               side1, side2, side3);

        return 1;
    }

    printf("The triangle with sides %.2f, %.2f, and %.2f is valid!\n",
           side1, side2, side3);

    // call function to calculate area
    area = get_triangle_area(side1, side2, side3);

    printf("The triangle with sides %.2f, %.2f, and %.2f has an area of %.2f units squared!\n",
           side1, side2, side3, area);

    // call function to figure out what type of triangle the user input
    get_triangle_type(side1, side2, side3);

    return 0;
}

// if any two sides are bigger than the 3rd side, the "triangle" isn't valid
int is_valid_triangle(double side1, double side2, double side3)
{
    // if any two sides are greater than or equal to the third side, it's invalid
    // three sides, pick two, where n!/(r!(n - r)!) = 3 outcomes = 3 conditions
    if ((side3 >= side1 + side2) || (side1 >= side2 + side3) || (side2 >= side3 + side1))
    {
        // if invalid, return "false"
        return 0;
    }

    // if not invalid return "true"
    return 1;
}

// takes three side length as arguments
// applies formula area = sqrt(s(s-a)(s-b)(s-c))
double get_triangle_area(double side1, double side2, double side3)
{
    // calculate half of the perimeter
    double half_perimeter = (side1 + side2 + side3)/2;

    // return the area according to above formula
    return sqrt((half_perimeter * (half_perimeter - side1) * (half_perimeter - side2) * (half_perimeter - side3)));
}

// determine type of triangle, and print out type
void get_triangle_type(double side1, double side2, double side3)
{
    double square1, square2, square3;

    // determine "side" types first

    // equilateral has all equal sides
    if ((side1 == side2) && (side2 == side3))
    {
        printf("The triangle with sides %.2f, %.2f, and %.2f is equilateral\n", side1, side2, side3);
    }

        // isosceles has two equal sides
    else if (side1 == side2 || side2 == side3 || side3 == side1)
    {
        printf("The triangle with sides %.2f, %.2f, and %.2f is isosceles\n", side1, side2, side3);
    }

    // determine "angle" types second

    // square all sides, since we needs the squares for the next step
    square1 = side1 * side1;
    square2 = side2 * side2;
    square3 = side3 * side3;

    // right triangle a^2 + b^2 = c^2
    // sides squared already, so a + b = c
    if ((square3 + square1 == square2) || (square1 + square2 == square3) || (square2 + square3 == square1))
    {
        printf("The triangle with sides %.2f, %.2f, and %.2f is right\n", side1, side2, side3);
    }

        // acute triangle a^2 + b^2 < c^2
    else if ((square3 + square1 > square2) || (side1 + square2 > square3) || (square2 + square3 > square1))
    {
        printf("The triangle with sides %.2f, %.2f, and %.2f is acute\n", side1, side2, side3);
    }

        // obtuse triangle a^2 + b^2 > c^2
        // but other cases have already been checked, so no need to compare
    else
    {
        printf("The triangle with sides %.2f, %.2f, and %.2f is obtuse\n", side1, side2, side3);
    }
}