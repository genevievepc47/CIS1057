// preprocessor directive to include these header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// prototype functions
int get_random_number(int n);
void roll_dice(int n);

int main(void)
{
    // get a seed
    srand(time(NULL));

    printf("===== Dice Rolls =====\n");

    // roll two dice, one with 6 sides and one with 9 sides
    roll_dice(6);
    roll_dice(9);

    printf("======================\n");

    // no errors, return 0
    return 0;
}

// get random number where n is limit
int get_random_number(int n)
{
    // return random number between 1 and n
    return ((rand()) % n) + 1;
}

// print out dice
void roll_dice(int n)
{
    int r = get_random_number(n);
    printf("*****\n");
    printf("* %d *\n", r);
    printf("*****\n");
}
