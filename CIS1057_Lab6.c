#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 100

void print_all_numbers(int[], int);
void print_largest_number(int[], int);
void print_average_number(int[], int);
void print_even_numbers(int[], int);

int main(void)
{

    int int_array[ARRAY_SIZE];

    // seed random function
    srand(time(NULL));

    // place a random number in each place in array
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        int_array[i] = (rand() % 101);
    }

    printf("The array contains the following integers: ");
    print_all_numbers(int_array, ARRAY_SIZE);

    printf("The largest number in the array is: ");
    print_largest_number(int_array, ARRAY_SIZE);

    printf("The average number of the array is: ");
    print_average_number(int_array, ARRAY_SIZE);

    printf("The even numbers in  the array are: ");
    print_even_numbers(int_array, ARRAY_SIZE);

    return 0;
}


void print_all_numbers(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_largest_number(int arr[], int size)
{
    int largest = arr[0];
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    printf("%d\n");
}

void print_average_number(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    printf("%d\n", (sum/size));
}

void print_even_numbers(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (!(arr[i]%2))
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
