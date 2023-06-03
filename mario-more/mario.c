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
        // add space before brick equal to height - number of each layer
        for (s = 1; s <= height - i; s++)
        {
            printf(" ");
        }

        // add brick (amount of brick equal to number of each layer)
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        // add 2 middle space
        printf("  ");

        // add brick (amount of brick equal to number of layer)
        for (k = 1; k <= i; k++)
        {
            printf("#");
        }
        // enter to new line
        printf("\n");
    }
}