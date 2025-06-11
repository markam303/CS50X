#include "helpers.h"
#include <math.h>
#include <stdio.h>

int check255(int x);
void swap(RGBTRIPLE *x, RGBTRIPLE *y);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // take avg of r g and b
            double gray = 0;
            gray = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            gray = round(gray);

            // update pixels values
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // apply algorytm of sepia
            double sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                               .131 * image[i][j].rgbtBlue;
            double sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                .168 * image[i][j].rgbtBlue;
            double sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                              .189 * image[i][j].rgbtBlue;

            // update rgb values
            sepiaBlue = round(sepiaBlue);
            sepiaGreen = round(sepiaGreen);
            sepiaRed = round(sepiaRed);

            sepiaBlue = check255(sepiaBlue);
            sepiaGreen = check255(sepiaGreen);
            sepiaRed = check255(sepiaRed);

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // swap pixels

            swap(&image[i][j], &image[i][width - j - 1]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create copy of img
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // create copy of img
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // apply blurbox with 3x3 grid and center at i, j
            int sumaBlue = 0;
            int sumaGreen = 0;
            int sumaRed = 0;
            float step_counter = 0;
            // iterate thru that 3x3 grid
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    int mi = i + k;
                    int mj = j + l;

                    // check if within img limits
                    if (mi >= 0 && mi < height && mj >= 0 && mj < width)
                    {
                        sumaBlue += copy[mi][mj].rgbtBlue;
                        sumaGreen += copy[mi][mj].rgbtGreen;
                        sumaRed += copy[mi][mj].rgbtRed;
                        step_counter++;
                    }
                }
            }

            image[i][j].rgbtBlue = round((sumaBlue / step_counter));
            image[i][j].rgbtGreen = round((sumaGreen / step_counter));
            image[i][j].rgbtRed = round((sumaRed / step_counter));
        }
    }
    return;
}

// check 255
int check255(int x)
{
    if (x > 255)
    {
        x = 255;
    }

    return x;
}

// swap
void swap(RGBTRIPLE *x, RGBTRIPLE *y)
{
    RGBTRIPLE bufferos = *x;
    *x = *y;
    *y = bufferos;

    return;
}
