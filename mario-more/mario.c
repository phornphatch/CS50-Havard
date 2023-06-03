#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height >= 1 || height <= 8);

    int i;
    for (i = 1; i < height; i++)
    {
        printf("#");
    }
}