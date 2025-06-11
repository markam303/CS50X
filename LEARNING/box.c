#include <cs50.h>
#include <stdio.h>
#include "bmp.h"

int box(int height, int width, RGBTRIPLE image[height][width])
{
    int sumaBlue = 0;
    int sumaGreen = 0;
    int sumaRed = 0;
    int step_counter = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    sumaBlue += *image[i][j].rgbtBlue;
                    sumaGreen += *image[i][j].rgbtGreen;
                    sumaRed += *image[i][j].rgbtRed
                    step_counter += 1;
                }
            }
        }
    }
    // calc the avarage value of middle cell in 3x3 grid
    int avgBlue = sumaBlue / step_counter;
    int avgGreen = sumaGreen / step_counter;
    int avgRed = sumaRed / step_counter;

    avgBlue = check255(avgBlue);
    avgGreen = check255(avgGreen);
    avgRed = check255(avgRed);

    image[i][j].rgbtBlue = avgBlue;
    image[i][j].rgbtGreen = avgGreen;
    image[i][j].rgbtRed = avgRed;
}
