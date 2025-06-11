#include <cs50.h>
#include <stdio.h>

int calc_quaters(int cents);

int main(void)
{
    int quaters = calc_quaters(100);
    printf("%i \n", quaters);
}


int calc_quaters(int cents)
{
    int quaters = 0;
    for (int i = 0; cents >= 25; i++)
    {
        quaters++;
        cents = cents - 25;
    }
    return quaters;
}
