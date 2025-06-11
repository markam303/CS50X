// Build reversed pyramid based on input 

#include <cs50.h>
#include <stdio.h>

void print_row(int space, int brick);

int main(void)
{
    // ask for height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    // print pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // print row of bricks
        print_row(n - i, i + 1);
    }
}

void print_row(int space, int brick)
{
    // print spaces
    for (int i = space - 1; i > 0; i--)
    {
        printf(" ");
    }
    // print bricks
    for (int i = 0; i < brick; i++)
    {
        printf("#");
    }
    printf("\n");
}
