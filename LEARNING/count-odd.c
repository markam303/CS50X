#include <cs50.h>
#include <stdio.h>

void count(int n, int m);

int main(void)
{
    int n;
    int m;
    do
    {
        n = get_int("Input first: ");
        m = get_int("Input last: ");
    }
    while(n < 0 || m < 0 || m < n);

    count(n, m);
}



void count(int first, int last)
{
    int i;
    for(i = first/2; i <= last; i++)
    {
        printf("%i ", i);
    }
    printf("\n");
}
