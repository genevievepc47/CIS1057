#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Author:     Yakir Lebovits
 * Class:      CIS 1057
 * Professor:  Dr. Morris
 * Date Due:   4 October 2018
 *
 * A simple slot game program that repeats until the user ends the game
 *
 */

// prototype functions
int get_random_number(int max);
int play_slot(void);

int main(void)
{
    // declare variables
    int games_played = 0;
    int matched;
    int matched_two = 0, matched_three = 0;
    int game_flag = 1;
    char play_again;

    // keep playing until user wants to quit
    do
    {
        // prompt user for input
        printf("Would you like to play the slot machine?\nEnter Y or y > ");
        scanf(" %c", &play_again);

        // check if user wants to play again, if they don't, set flag to false
        if ((play_again == 'y') || (play_again == 'Y'))
        {
            // play game, save result
            matched = play_slot();

            // check which match occurred, and increment its counter
            if (matched == 3) matched_three++;
            else if (matched == 2) matched_two++;

        }

        else
        {
            game_flag = 0;
        }


    } while (game_flag);

    printf("You played %d times\nYou matched 3 %d times\nYou matched 2 %d times",
            games_played, matched_three, matched_two);

    return 0;
}

// returns a random number between 1 and max
int get_random_number(int max)
{
    return ((rand() % max) + 1);
}

// gets three random numbers and checks them for matches
// returns a code corresponding to the number of numbers which matched
int play_slot(void)
{
    // seed random at the start of every game to get a new sequence
    srand(time(NULL));

    // declare and initialize one variable for each "row" in the slot machine
    int row_one_number, row_two_number, row_three_number;
    row_one_number = get_random_number(6);
    row_two_number = get_random_number(6);
    row_three_number = get_random_number(6);

    // if all three are equal
    if ((row_one_number == row_two_number) && (row_two_number == row_three_number))
    {
        printf("\nYou've hit the Jackpot!\n\n");
        return 3;
    }

    // if two are equal
    else if ((row_one_number == row_two_number) || (row_two_number == row_three_number))
    {
        printf("\nYou've matched 2!\n\n");
        return 2;
    }

    // if none are equal
    else
    {
        printf("\nSorry. Better lucky next time.\n\n");
        return 1;
    }
}

