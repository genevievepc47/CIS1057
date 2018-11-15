#include <stdio.h>

#define ARRAYSIZE 25

void insert(int array[], int item_count, int value);
int delete(int array[], int item_count, int delete_target);

int main(void)
{
    int item_count = 0;
    int array[ARRAYSIZE];
    int choice, value;

    printf("Select an option:\n1 - Insert value into array\n2 - Delete a value from array\n3 - Print all items in array\n4 - Exit program\n");

    do
    {
        printf("Make a selection: ");
        scanf("%i", &choice);

        if (choice == 1)
        {
            if (item_count < ARRAYSIZE-1)
            {
                printf("Enter a value to be inserted: ");
                scanf("%i", &value);
                insert(array, item_count++, value);
            }

            else
            {
                printf("The array is full!\n");
            }
        }

        else if (choice == 2)
        {
            if (item_count == 0)
            {
                printf("Nothing in the array!\n");
            }

            else
            {
                printf("Enter a value to be deleted: ");
                scanf("%i", &value);
                if (delete(array, item_count--, value))
                {
                    printf("Deleted!\n");
                }
                else
                {
                    printf("Couldn't find %i in the array\n", value);
                }
            }
        }

        else if (choice == 3)
        {
            if (item_count == 0)
            {
                printf("Nothing in the array!\n");
            }

            else
            {
                printf("Array contents: ");
                for (int i = 0; i < item_count; ++i)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");
            }
        }

        else if (choice == 4)
        {
            break;
        }

        else
        {
            printf("Invalid option!\n");
        }
    }
    while (1);


    return 0;
}

// insert new item into array
// parameters: array, number of items in array, value to be inserted
void insert(int array[],int item_count, int value)
{
    int insert_index = 0;

    // if empty, no place finding needed
    if (item_count == 0)
    {
        array[0] = value;
    }

    // if new value is bigger than biggest in array, put it at the end
    else if (value >= array[item_count-1])
    {
        array[item_count] = value;
    }

    else
    {
        // find the index at which the new value should be inserted
        for (int i = 0; i < item_count; ++i)
        {
            if (array[i] > value)
            {
                insert_index = i;
                break;
            }
        }

        // shift values right
        for (int j = item_count; j > insert_index; --j)
        {
            array[j] = array[j-1];
        }

        // insert new value
        array[insert_index] = value;
    }

}

// delete item from array
// parameters: array, number of items in array, value to be deleted
int delete(int array[], int item_count, int delete_target)
{
    int index = -1;

    // find index of item in array
    for (int i = 0; i < item_count; ++i)
    {
        if (array[i] == delete_target)
        {
            index = i;
        }
    }

    // return false if unable to find item to delete
    if (index == -1)
    {
        return 0;
    }

    // shift items once item has been deleted
    for (int j = index; j < item_count ; ++j)
    {
        array[j] = array[j+1];
    }

    return 1;
}