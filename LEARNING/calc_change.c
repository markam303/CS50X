#include <cs50.h>
#include <stdio.h>

int calc_change(int cents, int OneCoinValue);

int main(void)
{
    int change = calc_change(100, 25);
    printf("%i \n", change);
}


int calc_change(int cents, int OneCoinValue)
{
    int change = 0;
    for (int i = 0; cents >= OneCoinValue; i++)
    {
        change++;
        cents = cents - OneCoinValue;
    }
    return change;
}
