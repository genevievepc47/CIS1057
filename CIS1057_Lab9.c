#include <stdio.h>
#include <string.h>

/*
 * Contact: yakirlebovits@temple.edu
 * Class: CIS1057
 * Professor: Dr. Morris
 * TA: Shi Kai Fang
 *
 * This program prompts the user to input a string, and then it reverses it
 */

void reverse(char string[]);
void swap(char *x, char *y);


int main(void)
{

    char string[128];

    printf("Enter a string to reverse: ");
    scanf("%[^\n]s", string);

    printf("Original: %s\n", string);

    reverse(string);

    printf("Reversed: %s", string);

    return 0;
}


void reverse(char string[])
{
    int len = strlen(string);
    char tmp;
    for (int i = 0; i < len/2; ++i)
    {
        swap(&string[i], &string[len-i-1]);
    }
}

void swap(char *x, char *y)
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

