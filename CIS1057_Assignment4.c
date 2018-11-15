#include <stdio.h>

/*
 * Author:    Yakir Lebovits
 * Contact:   yakirlebovits@temple.edu
 * Professor: Dr. Morris
 * Class:     CIS 1057
 * Due:       7 November, 2018
 *
 * This program prompts the user to enter an array of grades. Once entered,
 * the program then sorts the array, calculates the lowest value, highest
 * value, median value, and mean value, and then prints this information.
 *
 */

// function prototypes
void sort_grades(int[], int);
void print_all_grades(const int[], int);
int get_lowest_grade(const int[], int);
int get_highest_grade(const int[], int);
double get_median_grade(const int [], int);
double get_mean_grade(const int[], int);

int main(void)
{
    int num_grades = 0, entered_grades = 0, grade_input;

    printf("How many grades will you enter? ");
    scanf("%i", &num_grades);

    // cannot enter 0 grades or a negative number of grades
    if (num_grades < 1)
    {
        printf("That's an invalid number of grades!\n");
        return 1;
    }

    int grades[num_grades];

    for (int i = 0; i < num_grades; ++i)
    {
        printf("Enter a grade: ");
        scanf("%i", &grade_input);

        // -1 is sentinel value to stop entering grades
        if (grade_input == -1)
        {
            break;
        }

        // if input is invalid, ignore it and just loop and additional time
        else if (grade_input < 0)
        {
            printf("That an invalid grade!\n");
            i--;
        }

        else
        {
            grades[entered_grades++] = grade_input;
        }
    }

    sort_grades(grades, entered_grades);

    printf("\nThe grades, from lowest to highest, are: ");
    print_all_grades(grades, entered_grades);

    printf("The lowest grade is %d\n",
            get_lowest_grade(grades, entered_grades));

    printf("The highest grade is: %d\n",
            get_highest_grade(grades, entered_grades));

    printf("The median grade is: %0.2f\n",
           get_median_grade(grades, entered_grades));

    printf("The mean grade is: %0.2f\n",
            get_mean_grade(grades, entered_grades));

    return 0;
}

// print each item in array
void print_all_grades(const int array[], int items)
{
    for (int i = 0; i < items; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// sorts array in ascending order
void sort_grades(int array[], int items)
{
    int sorted, temp;

    // loop through the array n^2 times
    for (int i = 0; i < items; ++i)
    {
        // so far, no swaps have been completed for this iteration
        sorted = 1;

        // only need to check to n-1 because each step checks j and j+1
        // minus i because we've already bubbled the highest values to the top
        // so we know they're sorted
        for (int j = 0; j < items - i - 1; ++j)
        {
            if (array[j] > array[j+1])
            {
                // swap them
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;

                // swap has occurred, so we cant say for sure that array is sorted
                sorted = 0;
            }
        }

        if (sorted)
        {
            break;
        }
    }
}

// precondition: array is sorted in ascending order
int get_lowest_grade(const int array[], int items)
{
    return array[0];
}

// precondition: array is sorted in ascending order
int get_highest_grade(const int array[], int items)
{
    return array[items-1];
}

// precondition: array is sorted
// returns middle number
double get_median_grade(const int array[], int items)
{
    // if single mid-point
    if (items % 2 == 1)
    {
        return array[items/2];
    }

    // if array is even, get the two middle values and average them
    else
    {
        return (array[(items-1)/2] + array[items/2])/2.0;
    }
}

// add all numbers, divide by # of numbers
// returns average number
double get_mean_grade(const int array[], int items)
{
    double sum = 0;

    for (int i = 0; i < items; ++i)
    {
        sum += array[i];
    }

    return (sum/items);
}