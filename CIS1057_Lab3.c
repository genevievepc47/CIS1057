#include <stdio.h>
#include <math.h>

// Accept the radius of a circle inscribed in, and removed from an equilateral triangle, and return the
// remaining surface area – see the illustration above.
double calculate_area_less_inscribed_circle(double);
// Accept the radius of a circle and return that circle’s area
double calculate_circle_area(double);
// Accept the radius of the inscribed circle of
double calculate_triangle_area(double);

int main() {
    double radius;

    // get user input
    printf("Please enter radius: ");
    scanf("%lf", &radius);
`
    printf("The remaining area of the triangle is %.2f\n",
            calculate_area_less_inscribed_circle(radius));

    return 0;
}

double calculate_triangle_area(double radius)
{
    return (3 * sqrt(3) * radius * radius);
}

// radius squared x pi
double caclculate_circle_area(double radius)
{
    return radius * radius * M_PI;
}

// triangle area - circle area
double calculate_area_less_inscribed_circle(double radius)
{
    return calculate_triangle_area(radius) - caclculate_circle_area(radius);
}