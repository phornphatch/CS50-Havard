#include "helpers.h"
#include "math.h"
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
            float num_avg = ((num_red + num_green + num_blue) / 3.00);

            image[i][j].rgbtRed = round(num_avg);
            image[i][j].rgbtGreen = round(num_avg);
            image[i][j].rgbtBlue = round(num_avg);

            // if (i == 0 && j == 0)
            // {
            //     printf("%f\n", num_avg);
            //     printf("%i", num_red);
            //     printf("%i", num_green);
            //     printf("%i\n", num_blue);
            // }
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
            image[i][width - j - 1].rgbtRed = original_image[i][j].rgbtRed;
            image[i][width - j - 1].rgbtGreen = original_image[i][j].rgbtGreen;
            image[i][width - j - 1].rgbtBlue = original_image[i][j].rgbtBlue;
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

float divisor(int height, int width, int i, int j)
{
    if (i == 0)
    {
        if (j == 0 || j == width - 1) // corner
        {
            return 4.00;
        }
        else
        {
            return 6.00;
        }
    }

    if (i == height - 1)
    {
        if (j == 0 || j == width - 1)
        {
            return 4.00;
        }
        else
        {
            return 6.00;
        }
    }

    if (j == 0 || j == width - 1)
    {
        return 6.00;
    }

    return 9.00;
}
void avg_pixel(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE original_image[height][width], int i, int j)
{
    image[i][j].rgbtRed = round(
        (get_pixel(height, width, original_image, i - 1, j - 1, 'r') + get_pixel(height, width, original_image, i - 1, j, 'r') +
         get_pixel(height, width, original_image, i - 1, j + 1, 'r') + get_pixel(height, width, original_image, i, j - 1, 'r') +
         original_image[i][j].rgbtRed + get_pixel(height, width, original_image, i, j + 1, 'r') +
         get_pixel(height, width, original_image, i + 1, j - 1, 'r') + get_pixel(height, width, original_image, i + 1, j, 'r') +
         get_pixel(height, width, original_image, i + 1, j + 1, 'r')) /
        divisor(height, width, i, j));
    image[i][j].rgbtGreen = round(
        (get_pixel(height, width, original_image, i - 1, j - 1, 'g') + get_pixel(height, width, original_image, i - 1, j, 'g') +
         get_pixel(height, width, original_image, i - 1, j + 1, 'g') + get_pixel(height, width, original_image, i, j - 1, 'g') +
         original_image[i][j].rgbtGreen + get_pixel(height, width, original_image, i, j + 1, 'g') +
         get_pixel(height, width, original_image, i + 1, j - 1, 'g') + get_pixel(height, width, original_image, i + 1, j, 'g') +
         get_pixel(height, width, original_image, i + 1, j + 1, 'g')) /
        divisor(height, width, i, j));
    image[i][j].rgbtBlue = round(
        (get_pixel(height, width, original_image, i - 1, j - 1, 'b') + get_pixel(height, width, original_image, i - 1, j, 'b') +
         get_pixel(height, width, original_image, i - 1, j + 1, 'b') + get_pixel(height, width, original_image, i, j - 1, 'b') +
         original_image[i][j].rgbtBlue + get_pixel(height, width, original_image, i, j + 1, 'b') +
         get_pixel(height, width, original_image, i + 1, j - 1, 'b') + get_pixel(height, width, original_image, i + 1, j, 'b') +
         get_pixel(height, width, original_image, i + 1, j + 1, 'b')) /
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
            avg_pixel(width, height, image, original_image, i, j);
        }
    }
}

typedef struct
{
    int GRed;
    int GGreen;
    int GBlue;
} __attribute__((__packed__)) GALL;

// find gx and gy
GALL find_g(int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE original_image[height][width], int i, int j)
{
    int gx_red = (((-1) * get_pixel(height, width, original_image, i - 1, j - 1, 'r')) +
                  (0 * get_pixel(height, width, original_image, i - 1, j, 'r')) +
                  (1 * get_pixel(height, width, original_image, i - 1, j + 1, 'r')) +
                  ((-2) * get_pixel(height, width, original_image, i, j - 1, 'r')) + (0 * original_image[i][j].rgbtRed) +
                  (2 * get_pixel(height, width, original_image, i, j + 1, 'r')) +
                  ((-1) * get_pixel(height, width, original_image, i + 1, j - 1, 'r')) +
                  (0 * get_pixel(height, width, original_image, i + 1, j, 'r')) +
                  (1 * get_pixel(height, width, original_image, i + 1, j + 1, 'r')));
    int gx_green = (((-1) * get_pixel(height, width, original_image, i - 1, j - 1, 'g')) +
                    (0 * get_pixel(height, width, original_image, i - 1, j, 'g')) +
                    (1 * get_pixel(height, width, original_image, i - 1, j + 1, 'g')) +
                    ((-2) * get_pixel(height, width, original_image, i, j - 1, 'g')) + (0 * original_image[i][j].rgbtGreen) +
                    (2 * get_pixel(height, width, original_image, i, j + 1, 'g')) +
                    ((-1) * get_pixel(height, width, original_image, i + 1, j - 1, 'g')) +
                    (0 * get_pixel(height, width, original_image, i + 1, j, 'g')) +
                    (1 * get_pixel(height, width, original_image, i + 1, j + 1, 'g')));
    int gx_blue = (((-1) * get_pixel(height, width, original_image, i - 1, j - 1, 'b')) +
                   (0 * get_pixel(height, width, original_image, i - 1, j, 'b')) +
                   (1 * get_pixel(height, width, original_image, i - 1, j + 1, 'b')) +
                   ((-2) * get_pixel(height, width, original_image, i, j - 1, 'b')) + (0 * original_image[i][j].rgbtBlue) +
                   (2 * get_pixel(height, width, original_image, i, j + 1, 'b')) +
                   ((-1) * get_pixel(height, width, original_image, i + 1, j - 1, 'b')) +
                   (0 * get_pixel(height, width, original_image, i + 1, j, 'b')) +
                   (1 * get_pixel(height, width, original_image, i + 1, j + 1, 'b')));
    int gy_red = (((-1) * get_pixel(height, width, original_image, i - 1, j - 1, 'r')) +
                  ((-2) * get_pixel(height, width, original_image, i - 1, j, 'r')) +
                  ((-1) * get_pixel(height, width, original_image, i - 1, j + 1, 'r')) +
                  (0 * get_pixel(height, width, original_image, i, j - 1, 'r')) + (0 * original_image[i][j].rgbtRed) +
                  (0 * get_pixel(height, width, original_image, i, j + 1, 'r')) +
                  (1 * get_pixel(height, width, original_image, i + 1, j - 1, 'r')) +
                  (2 * get_pixel(height, width, original_image, i + 1, j, 'r')) +
                  (1 * get_pixel(height, width, original_image, i + 1, j + 1, 'r')));
    int gy_green = (((-1) * get_pixel(height, width, original_image, i - 1, j - 1, 'g')) +
                    ((-2)) * get_pixel(height, width, original_image, i - 1, j, 'g')) +
                    ((-1) * get_pixel(height, width, original_image, i - 1, j + 1, 'g')) +
                    (0 * get_pixel(height, width, original_image, i, j - 1, 'g')) + (0 * original_image[i][j].rgbtGreen) +
                    (0 * get_pixel(height, width, original_image, i, j + 1, 'g')) +
                    (1 * get_pixel(height, width, original_image, i + 1, j - 1, 'g')) +
                    (2 * get_pixel(height, width, original_image, i + 1, j, 'g')) +
                    (1 * get_pixel(height, width, original_image, i + 1, j + 1, 'g')));
    int gy_blue = (((-1) * get_pixel(height, width, original_image, i - 1, j - 1, 'b')) +
                   ((-2) * get_pixel(height, width, original_image, i - 1, j, 'b')) +
                   ((-1)) * get_pixel(height, width, original_image, i - 1, j + 1, 'b')) +
                   (0 * get_pixel(height, width, original_image, i, j - 1, 'b')) + (0 * original_image[i][j].rgbtBlue) +
                   (0 * get_pixel(height, width, original_image, i, j + 1, 'b')) +
                   (1 * get_pixel(height, width, original_image, i + 1, j - 1, 'b')) +
                   (2 * get_pixel(height, width, original_image, i + 1, j, 'b')) +
                   (1 * get_pixel(height, width, original_image, i + 1, j + 1, 'b')));

    GALL GRed = (gx_red*gx_red)+(gy_red*gy_red);
    GALL GGreen = (gx_green*gx_green)+(gy_green*gy_green);
    GALL GBlue = (gx_blue*gx_blue)+(gy_blue*gy_blue);
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
        for (int j = 0; j < width; j++)
        {
            // avg_pixel(width, height, image, original_image, i, j);
        }
    }
}
