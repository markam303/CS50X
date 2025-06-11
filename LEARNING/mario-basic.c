#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);

int main(void)
{
                                    // user input how high
    int height;
    do
    {
        height = get_int("Whats the height of pyramid? ");
    }
    while (height < 1);

    // print a pyramid of that height
    for (int i = 0 ; i < height; i++)
    print_row(i + 1);
}




void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
