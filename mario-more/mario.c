#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get height from user and continue if height => 1 and <= 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // create pyramid
    int i;
    int j;
    int k;
    int s;
    for (i = 1; i <= height; i++)
    {
         for (s = height; s == height - 1; s--)
        {
            printf("*");
        }
        
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf(" ");

         for (k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}