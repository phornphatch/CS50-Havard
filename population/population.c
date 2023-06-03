#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // insert start size
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // insert end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // calculate new start_size and increase year until start_size >= end_size
    int y;
    for (y = 0; start_size < end_size; y++)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
    }

    printf("Years: %i\n", y);
}
