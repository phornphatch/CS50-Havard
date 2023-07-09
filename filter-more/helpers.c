#include "helpers.h"

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
                red = image[i][j].rgbtRed;
                green = image[i][j].rgbtGreen;
                blue = image[i][j].rgbtBlue;
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
