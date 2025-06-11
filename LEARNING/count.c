#include <stdio.h>
#include <cs50.h>

void count(int n, int m);

int main(void)
{
    int x = get_int("Input X: ");
    int y = get_int("Input Y: ");
    count(x, y);
}







void count(int n, int m)
{
    for (int i = n; i >= m; i--)
    {
        printf("%i ", i);
    }
    printf("\n");
}
