#include "helpers.h"
#include "stdio.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][i].rgbtRed == 0x00 && image[i][i].rgbtGreen == 0x00 && image[i][i].rgbtBlue == 0x00)
            image[i][i].rgbtRed == 0x00 && image[i][i].rgbtGreen == 0x00 && image[i][i].rgbtBlue == 0x00)
        }
    }
}
