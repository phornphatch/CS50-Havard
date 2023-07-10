#include "helpers.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

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
            double num_avg = ((num_red + num_green + num_blue) / 3);

            image[i][j].rgbtRed = round(num_avg);
            image[i][j].rgbtGreen = round(num_avg);
            image[i][j].rgbtBlue = round(num_avg);

            if(i==0 && j==0)
            {
                 printf("%f", num_avg);
                 printf("%i", num_red);
printf("%i", num_green);printf("%i", num_blue);
            }
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

int get_pixel(int height, int width, RGBTRIPLE image[height][width], int i, int j, char color)
{
    // ขอบบน ล่าง ซ้าน ขวา
    if (i < 0 || i >= height || j < 0 || j >= width)
    {
        return 0;
    }

    if (color == 'r')
    {
        return image[i][j].rgbtRed;
    }
    if (color == 'g')
    {
        return image[i][j].rgbtGreen;
    }
    if (color == 'b')
    {
        return image[i][j].rgbtBlue;
    }
    return 0;
}

int divisor(int height, int width, int i, int j)
{
    int divisor = 0;
    if (i == 0)
    {
        if (j == 0 || j == width)
        {
            return 4;
        }
        else
        {
            return 6;
        }
    }

    if (i == height)
    {
        if (j == 0 || j == width)
        {
            return 4;
        }
        else
        {
            return 6;
        }
    }

    if (j == 0 || j == width)
    {
        return 6;
    }

    return 9;
}

void avg_pixel(int height, int width, RGBTRIPLE image[height][width], int i, int j)
{
    image[i][j].rgbtRed =
        (int) ((get_pixel(height, width, image, i - 1, j - 1, 'r') + get_pixel(height, width, image, i - 1, j, 'r') +
                get_pixel(height, width, image, i - 1, j + 1, 'r') + get_pixel(height, width, image, i, j - 1, 'r') +
                image[i][j].rgbtRed + get_pixel(height, width, image, i - 1, j + 1, 'r') +
                get_pixel(height, width, image, i + 1, j - 1, 'r') + get_pixel(height, width, image, i + 1, j, 'r') +
                get_pixel(height, width, image, i + 1, j + 1, 'r')) /
               divisor(height, width, i, j));
    image[i][j].rgbtGreen =
        (int) ((get_pixel(height, width, image, i - 1, j - 1, 'g') + get_pixel(height, width, image, i - 1, j, 'g') +
                get_pixel(height, width, image, i - 1, j + 1, 'g') + get_pixel(height, width, image, i, j - 1, 'g') +
                image[i][j].rgbtRed + get_pixel(height, width, image, i - 1, j + 1, 'g') +
                get_pixel(height, width, image, i + 1, j - 1, 'g') + get_pixel(height, width, image, i + 1, j, 'g') +
                get_pixel(height, width, image, i + 1, j + 1, 'g')) /
               divisor(height, width, i, j));
    image[i][j].rgbtBlue =
        (int) ((get_pixel(height, width, image, i - 1, j - 1, 'b') + get_pixel(height, width, image, i - 1, j, 'b') +
                get_pixel(height, width, image, i - 1, j + 1, 'b') + get_pixel(height, width, image, i, j - 1, 'b') +
                image[i][j].rgbtRed + get_pixel(height, width, image, i - 1, j + 1, 'b') +
                get_pixel(height, width, image, i + 1, j - 1, 'b') + get_pixel(height, width, image, i + 1, j, 'b') +
                get_pixel(height, width, image, i + 1, j + 1, 'b')) /
               divisor(height, width, i, j));
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
            avg_pixel(width, height, original_image, i, j);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
