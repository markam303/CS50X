#include <cs50.h>
#include <stdio.h>

void count(int n, int m);

int main(void)
{
    int x;
    int y;
    x = get_int("Input X: ");
    y = get_int("Input Y: ");

    if (x < y || x < 0)
    {
        printf("Wrong input x!\n");
        return 1;
    }
    else if (y < 0)
    {
        printf("Wrong input y!\n");
        return 1;
    }
    else
    {
        count(x, y);
    }
}

void count(int n, int m)
{
    for (int i = n; i >= m; i--)
    {
        printf("%i ", i);
    }
    printf("\n");
}
