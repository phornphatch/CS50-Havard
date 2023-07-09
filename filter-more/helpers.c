#include "helpers.h"
#include "stdio.h"
#include "stdlib.h"

// TODO implement all filters function
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
    // find avg of red green blue
    //.rgbtRed + .rgbtGreen + .rgbtBlue / 3
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int num_red = (int) strtol(image[i][j].rgbtRed, NULL, 0); // -> 0x00 or 0xff
            int num_green = (int) strtol(image[i][j].rgbtGreen, NULL, 0);
            int num_blue = (int) strtol(image[i][j].rgbtBlue, NULL, 0);
            float num_avg = (num_red + num_green + num_blue) / 3;
            printf("%f", num_avg);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
