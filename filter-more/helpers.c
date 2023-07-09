#include "helpers.h"
#include "stdio.h"
#include "stdlib.h"

// TODO implement all filters function
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // find avg of red green blue
    //.rgbtRed + .rgbtGreen + .rgbtBlue / 3
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int num_red = image[i][j].rgbtRed; // -> 0x00 or 0xff
            int num_green = image[i][j].rgbtGreen;
            int num_blue = image[i][j].rgbtBlue;
            int num_avg = (int) ((num_red + num_green + num_blue) / 3);
            // printf("%d", num_avg);
            image[i][j].rgbtRed = num_avg;
            image[i][j].rgbtGreen = num_avg;
            image[i][j].rgbtBlue = num_avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original_image[height][width];

    for (int i = 0; i < height; i++) // access to each row
    {
        // save orginal image
        for (int j = 0; j < width; j++)
        {
            original_image[i][j].rgbtRed = image[i][j].rgbtRed;
            original_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            original_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++) // access to each row
    {
        // switch (mirror)
        for (int j = 0; j < width; j++)
        {
            image[i][width - j].rgbtRed = original_image[i][j].rgbtRed;
            image[i][width - j].rgbtGreen = original_image[i][j].rgbtGreen;
            image[i][width - j].rgbtBlue = original_image[i][j].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original_image[height][width];

    for (int i = 0; i < height; i++) // access to each row
    {
        // save orginal image
        for (int j = 0; j < width; j++)
        {
            original_image[i][j].rgbtRed = image[i][j].rgbtRed;
            original_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            original_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }


    for (int i = 0; i < height; i++) // access to each row
    {
        // switch (mirror)
        for (int j = 0; j < width; j++)
        {
            image[i][width - j].rgbtRed = original_image[i][j].rgbtRed;
            image[i][width - j].rgbtGreen = original_image[i][j].rgbtGreen;
            image[i][width - j].rgbtBlue = original_image[i][j].rgbtBlue;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
