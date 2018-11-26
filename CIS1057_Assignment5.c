#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE 128


/* function prototypes */
double get_grade(void);
void get_name(char name[]);

int main(void)
{
    int no_students;

    printf("How many students will you enter: ");
    scanf("%i", no_students);

    double grades[no_students];
    char names[no_students][NAMESIZE];



    return 0;
}

/* prompt user to input a floating point number grade */
double get_grade(void)
{
    double grade = -1.0;

    do
    {
        printf("Enter a valid grade: ");
        scanf("%f", grade);
    }
    while (grade < 0.0 || grade > 100.0);

    return grade;
}

/* prompt user to input a name */
void get_name(char name[])
{
    do
    {
        printf("Enter a name: ");
        gets(name);
    }
    while(name[0] == '\0'); /* make sure input is not empty */
}

