#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * Author: Yakir Lebovits
 * Contact: yakirlebovits@temple.edu
 * Professor: Dr. Morris
 * Class: CIS 1057
 * Due: 11 December, 2018
 *
 * This program generates an N by N  grid of lowercase characters, and prompts
 * the user to enter a string to search for within the grid. If not found,
 * an error message will be displayed. If the string is found, the program
 * will output the coordinates, in order, at which the string appears.
 *
 */

#define GRIDSIZE 10

char rand_char(void);
void generate_grid(char grid[GRIDSIZE][GRIDSIZE], int size);
void print_grid(char grid[GRIDSIZE][GRIDSIZE], int size);
int find_initial_point(char grid[][GRIDSIZE], char tgt_str[], int size, int rows[], int columns[]);
int search_for_string(char grid[][GRIDSIZE], char tgt_str[], int size, int rows[], int columns[], int row, int col, int mov_row, int mov_col);


int main(void)
{
    char grid[GRIDSIZE][GRIDSIZE];
    char input[1024];

    srand(time(NULL));

    generate_grid(grid, GRIDSIZE);
    print_grid(grid, GRIDSIZE);

    printf("\nEnter a string to search for: ");
    scanf("%s", input);

    int rows[strlen(input)], columns[strlen(input)];

    if (find_initial_point(grid, input, GRIDSIZE, rows, columns))
    {
        printf("Found at the following coordinates: ");

        for (int i = 0; i < strlen(input); ++i)
        {
            printf("%c%i ", rows[i] + 'A', columns[i] + 1); /* offset by A and 1 for user readability*/
        }

        print_grid(grid, GRIDSIZE);
    }

    else
    {
        printf("Not found!\n");
    }

    return 0;
}

// returns random lowercase character
char rand_char(void)
{
    return (rand() % 26) + 97;
}

// populates an N by N multidimensional array with lowercase characters
void generate_grid(char grid[GRIDSIZE][GRIDSIZE], int size)
{
    for (int row = 0; row < size; ++row)
    {
        for (int column = 0; column < size; ++column)
        {
            grid[row][column] = rand_char();
        }
    }
}

// outputs an N by N multidimensional array with row and column labels
void print_grid(char grid[GRIDSIZE][GRIDSIZE], int size)
{
    printf("\n ");

    for (int i = 1; i <= size; ++i)
        printf(" %i", i);

    for (int row = 0; row < size; ++row)
    {
        printf("\n%c", row + 65);

        for (int column = 0; column < size; ++column)
            printf(" %c", grid[row][column]);
    }
}

// searches grid and finds any occurrence of the first character of the target string
// if found, calls a function to search for the remainder of the string
int find_initial_point(char grid[][GRIDSIZE], char tgt_str[], int size, int rows[], int columns[])
{
    for (int row = 0; row < size; ++row)
    {
        for (int column = 0; column < size; ++column)
        {
            if (grid[row][column] == tgt_str[0])
            {
                if (search_for_string(grid, tgt_str, size, rows, columns, row,  column, 0, 1)) // look right
                    return 1;

                if (search_for_string(grid, tgt_str, size, rows, columns, row,  column, 0, -1)) // look left
                    return 1;

                if (search_for_string(grid, tgt_str, size, rows, columns, row,  column, 1, 0)) // look up
                    return 1;

                if (search_for_string(grid, tgt_str, size, rows, columns, row,  column, -1, 0)) // look down
                    return 1;
            }
        }
    }
    return 0;
}

/* takes an initial coordinate and looks in a given direction for the rest of the word.
 * mov_row and mov_col specify which direction to look in */
int search_for_string(char grid[][GRIDSIZE], char tgt_str[], int size, int rows[], int columns[], int row, int col, int mov_row, int mov_col)
{
    int coord_pos = 1; /* where to place next coordinate in rows and columns arrays */

    /* first coordinates will always be the initial coordinate*/
    rows[0] = row;
    columns[0] = col;

    // if string is a single character
    if (strlen(tgt_str) == 1)
    {
        rows[0] = row;
        columns[0] = col;
        return 1;
    }


    for (int x = 1; x < strlen(tgt_str); ++x)
    {
        row += mov_row;
        col += mov_col;

        /* out of bounds */
        if ((row < 0) || (row >= size) || (col < 0) || (col >= size))
            return 0;

        /* break if the next item in the grid isn't the next char in the string */
        if (grid[row][col] != tgt_str[x])
        {
            return 0;
        }

        /* record coordinates of matching char */
        rows[coord_pos] = row;
        columns[coord_pos++] = col;
    }

    /* assume we found the string unless proven otherwise */
    return 1;
}
