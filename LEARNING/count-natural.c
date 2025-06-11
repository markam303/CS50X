#include <cs50.h>
#include <stdio.h>

void count(int how_much);

int main(void)
{
    int n;
    do
    {
        n = get_int("Input counter only natural number up to: ");
    }
    while(n < 0);

    count(n);
}



void count(int how_much)
{
    int i;
    for(i = 0; i < how_much; i++)
    {
        printf("%i ", i + 1);
    }
    printf("\n");
}
