// preprocessor directive to include the standard input/output header file
#include <stdio.h>

// declare main function
int main(void)
{
    int height, length; // initialize integer variables height and width

    // prompt user for inputs and store them in their respective variables
    printf("Enter the height of the rectangle: ");
    scanf("%d", &height);

    printf("Enter the width of the rectangle: ");
    scanf("%d", &length);

    // calculate area
    int area = height * length;

    // output area to user
    printf("The area of the rectangle with a height of %d and a length of %d is %d\n",
            height, length, area);

    // no errors, return status code 0
    return 0;
}
