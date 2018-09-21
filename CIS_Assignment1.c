#include <stdio.h> 

/*
 * Author: Yakir Lebovits
 * Professor: Dr. Morris
 * 
 * This program takes inputs of an item cost and money tendered,
 * and prints out how much change is owed and how that change can
 * be most efficiently returned.
 */

// prototype function
int get_int();

// main function
int main(void)
{
    // declare variables to use later
    int quarters, dimes, nickles, pennies;
    int price_paid, item_price;
    int change_amount;

    // prompt user for input
    printf("Enter the price of the item (in cents): ");
    item_price = get_int();

    // check to see if valid price
    if (item_price > 99 || item_price < 1)
    {
        printf("This is a DOLLAR store, enter a price between 1 and 99 cents!\n");

        // user input bad value, return error code 1
        return 1;
    }

    // prompt user for input
    printf("Enter the price paid (in cents): ");
    price_paid = get_int();

    if (price_paid > 99 || price_paid < 1)
    {
        printf("This is a DOLLAR store, don't pay with more than 99 cents!\n");

        return 2;
    }

    // output price info to user
    printf("Item Price: %i\n", item_price);
    printf("Amount Paid: %i\n", price_paid);

    // calculate amount of change owed and output it to user
    change_amount = price_paid - item_price;
    printf("Change Due: %i\n", change_amount);

    // check if user needs change
    if (change_amount == 0)
    {
        printf("No change due!\n");
    }

    // check if user paid enough
    else if (change_amount < 0)
    {
        printf("You haven't paid enough!\n");
    }

    // if user paid enough and is owed change, calculate it
    else
    {
        quarters = change_amount / 25; // most times 25 goes in
        change_amount %= 25; // after calculating quarters owed, update change to reflect remainder of owed change

        dimes = change_amount / 10;
        change_amount %= 10;

        nickles = change_amount / 5;
        change_amount %= 5;

        pennies = change_amount / 1;

        // print out change to user
        printf("You will receive the following change: \n");
        printf("%i quarters\n%i dimes\n%i nickles\n%i pennies\n", quarters, dimes, nickles, pennies);
    }

    // no errors, return status code 0
    return 0;
}

// function to get integer from user
int get_int()
{
    // declare buffer and input variables
    char buffer[256];
    int inpt;

    // read line into buffer
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        // read input we want and put it in the input variable
        if (1 == sscanf(buffer, "%i", &inpt))
        {
            // return input
            return inpt;
        }
    }
}
