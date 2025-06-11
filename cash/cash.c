// Check how much change in coins is due

#include <cs50.h>
#include <stdio.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int calculate_coins(int cents, int one_coin_value);

int main(void)
{
    // ask for change owed in cents
    int n;
    do
    {
        n = get_int("Change owed in cents: "); // our owed value
    }
    while (n < 0);

    int quarters_number = calculate_coins(n, QUARTER);
    n = n - (quarters_number * QUARTER);

    int dimes_number = calculate_coins(n, DIME);
    n = n - (dimes_number * DIME);

    int nickels_number = calculate_coins(n, NICKEL);
    n = n - (nickels_number * NICKEL);

    int pennies_number = calculate_coins(n, PENNY);

    int change = quarters_number + dimes_number + nickels_number + pennies_number;
    printf("%i \n", change);
}

int calculate_coins(int cents, int one_coin_value)
{
    int change = 0;
    {
        change = cents / one_coin_value;
    }
    return change;
}
