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

int get_pixel(RGBTRIPLE image[height][width], int i, int j, int height, int width, string color)
{
    // ขอบบน ล่าง ซ้าน ขวา
    if (i < 0 || i >= height || j < 0 || j > = width)
    {
        return 0;
    }

    if (color == 'red')
    {
        return image[i][j].rgbtRed;
    }
    if (color == 'green')
    {
        return image[i][j].rgbtGreen;
    }
    if (color == 'blue')
    {
        return image[i][j].rgbtBlue;
    }
}

int get_divisor(RGBTRIPLE image[height][width], int height, int width, )
{
    int divisor = 0;
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (i >= 0 && i < height && j >= 0 && j < width)
            {
                divisor++;
            }
        }
    }
    return divisor;
}

void avg_pixel(RGBTRIPLE image[height][width], int i, int j)
{
    image[i][j].rgbtRed = (int) (image[i - 1][j - 1] + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed +
                                  image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed +
                                  image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) /
                                 9);
    image[i][j].rgbtGreen = (int) ((image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen +
                                    image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                    image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) /
                                   9);
    image[i][j].rgbBlue = (int) ((image[i - 1][j - 1].rgbBlue + image[i - 1][j].rgbBlue + image[i - 1][j + 1].rgbBlue +
                                  image[i][j - 1].rgbBlue + image[i][j].rgbBlue + image[i][j + 1].rgbBlue +
                                  image[i + 1][j - 1].rgbBlue + image[i + 1][j].rgbBlue + image[i + 1][j + 1].rgbBlue) /
                                 9);
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
            avg_pixel(image, i, j);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
