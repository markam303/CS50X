#include <cs50.h>
#include <stdio.h>

void remainder_check(int owed, int coin);

int main(void)
{
    remainder_check(105, 25);
}




int remainder_check(int owed, int coin)
{
    int quotent = owed / coin;
    int remainder = owed % coin;
    if (quotent == 0)
    {
        printf("Quotent is: %i \n", quotent);
    }
    else
    {
        printf("Remainder is: %i \n", remainder);
    }
}
