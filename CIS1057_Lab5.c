#include <stdio.h>
#include <stdlib.h>

void sort(int *, int *, int *, int *);
void swap(int *, int *);
int max(int a, int b);
int min(int a, int b);

int main(void)
{
    int a, b, c, d;
    a = 1;
    b = 3;
    c = 4;
    d = 9;

    printf("%d %d %d %d\n", a, b, c, d);

    sort(&a, &b, &c, &d);

    printf("%d %d %d %d\n", a, b, c, d);

    return 0;
}

// swaps value of two integers via indirect reference
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// sorts four integers so that their size inversely corresponds with place (first = biggest, etc)
void sort(int *first, int *second, int *third, int *fourth)
{
    int max1, max2;
    int min1, min2;
    int mid1, mid2;

    if (*first >= *second)
    {
        max1 = *first;
        min1 = *second;
    }

    else
    {
        max1 = *second;
        min1 = *first;
    }

    if (*third > *fourth)
    {
        max2 = *third;
        min2 = *fourth;
    }

    else
    {
        max2 = *fourth;
        min2 = *third;
    }

    if (max1 > max2)
    {
        *first = max1;
        mid1 = max2;
    }

    else
    {
        *first = max2;
        mid1 = max1;
    }

    if (min1 > min2)
    {
        *fourth = min2;
        mid2 = min1;
    }

    else
    {
        *fourth = min1;
        mid2 = min2;
    }

    if (mid1 > mid2)
    {
        *second  = mid1;
        *third = min2;
    }

    else
    {
        *second = mid2;
        *third = mid1;
    }

}