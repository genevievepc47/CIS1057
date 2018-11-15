#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Author:    Yakir Lebovits
 * Contact:   yakirlebovits@temple.edu
 * Professor: Dr. Morris
 * Class:     CIS 1057
 * Due:       23 October, 2018
 *
 *
 * This program is a game of Pico, Fermi, Bagel. The user will attempt to guess
 * a three-digit number with unique digits. After each guess, the user will be
 * provided with a hint, informing them if their guess had the correct numbers
 * or the correct numbers in the correct places.
 */

// function prototypes
int get_random_number(int max);
int is_guess_correct(int guess, int secret1, int secret2, int secret3);
void split_3_digit_number(int num, int *d1, int *d2, int *d3);
void generate_secret_number(int *a, int *b, int *c);
void play_game(void);

int main(void)
{
    int flag = 1;
    char inpt;

    // seed random
    srand(time(NULL));

    printf("Welcome to Pico, Fermi, Bagel\n");
    printf("Your goal is to guess a secret number\n");
    printf("For each guess you make, the program will print out a hint\n\n");

    // let user play until they choose to end
    do
    {
        play_game();

        // check if users wants to play again
        printf("Would you like to play again? [Y/n]: ");
        scanf(" %c", &inpt);

        if (inpt == 'Y' || inpt == 'y') {
            flag  = 1;
        }
        else {
            flag = 0;
        }
    }
    while(flag);

    printf("Thanks for playing!\n");

    return 0;
}

/*
 * takes an integer (max)
 * return a random number between 0 and max
 */
int get_random_number(int max)
{
    return ((rand() % (max+1)));
}

/*
 * takes three int pointers and assigns a random number to each memory location to which the pointer points
 */
void generate_secret_number(int *a, int *b, int *c)
{

    // generate random numbers until the first number is not 0, and no numbers match
    do
    {
        *a = get_random_number(9);
    }
    while (*a == 0);

    do
    {
        *b = get_random_number(9);
    }
    while (*b == *a);

    do
    {
        *c = get_random_number(9);
    }
    while (*c  == *a || *c == *b);
}

/*
 * takes three int pointers and a num
 * assigns each digit to a location pointed to by one of the pointers
 */
void split_3_digit_number(int num, int *digit1, int *digit2, int *digit3)
{
    *digit1 = num / 100;
    num -= *digit1 * 100;

    *digit2 = num / 10;
    num -= *digit2 * 10;

    *digit3 = num;
}

// check if users guess is correct
int is_guess_correct(int guess, int secret1, int secret2, int secret3)
{
    int g1, g2, g3;
    split_3_digit_number(guess, &g1, &g2, &g3);

    if (g1 == secret1 && g2 == secret2 && g3 == secret3) {
        return 1;
    }

    else {
        return 0;
    }
}

void print_hint(int guess, int a1, int b1, int c1)
{
    // take guess and split it into three digits
    int a2, b2, c2;
    split_3_digit_number(guess, &a2, &b2, &c2);

    // show user their guess
    printf("guess = %d, ", guess);

    // check for right digits in right place
    if (a1 == a2)  {
        printf("Fermi ");
    }
    if (b1 == b2) {
        printf("Fermi ");
    }
    if (c1 == c2) {
        printf("Fermi ");
    }

    // check for right digits in wrong place
    if (a1 == b2 || a1 == c2) {
        printf("Pico ");
    }
    if (b1 == a2 || b1 == c2) {
        printf("Pico ");
    }
    if (c1 == a2 || c1 == b2) {
        printf("Pico ");
    }

    // if nothing matches
    if ((a1 != a2) && (a1 != b2) && (a1 != c2) && (b1 != a2) && (b1 != b2) && (b1 != c2) && (c1 != a2) && (c1 != b2) && (c1 != c2)) {
        printf("Bagels ");
    }

    printf("\n");

}
void play_game()
{
    // declare variables
    int digit1, digit2, digit3, guess, flag, guess_count;

    flag = 1;
    guess_count = 0;
    generate_secret_number(&digit1, &digit2, &digit3);

    do
    {
        // prompt user to enter a guess and increase guess counter
        printf("Enter a Number (- to quit): ");
        scanf("%d", &guess);

        // negative numbers are sentinel values to exit the game
        if (guess < 0)
        {
            flag = 0;
            printf("User quit after %d guesses!\n\n", guess_count);
        }

        // if not exit, check if they won or print a hint
        else
        {
            if (is_guess_correct(guess, digit1, digit2, digit3))
            {
                printf("guess = %d, Winner!\n", guess);
                printf("User won after %d guesses!\n\n", guess_count);
                flag = 0;
            }

            else
            {
                print_hint(guess, digit1, digit2, digit3);
            }
        }

        guess_count += 1;

    }
    while(flag);
}