// Pyramids generator that accepts input between 1 and 8

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input 1-8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Generate pyramids
    for (int i = 0; i < height; i++)
    {
        // spaces for left alignment
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // hashes for left pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // print static space
        printf("  ");

        // print hashes for right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}
