#include <stdio.h>
#include <cs50.h>

int const size = 1;

int main(void)
{
    // declare array
    int numbers[size];
    numbers[0] = 1;
    //  populate array

    for(int i = 1; i < size; i++)
    {
        numbers[i] = numbers[i - 1] * 2;
    }


 //   numbers[0] = 1;
  //  numbers[1] = numbers[0] * 2;
 //   numbers[2] = numbers[1] * 2;
 //   numbers[3] = numbers[2] * 2;
 //   numbers[4] = numbers[3] * 2;

    // int numbers[5] = {1, 2, 4, 8, 16};

    // print values one by one
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", numbers[i]);
    }
}
