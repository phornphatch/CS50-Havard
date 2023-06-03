#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");

    // calculate checksum
    long last_number = number % 10;
    // check card length

    // check starting number
    int first_number;
    if (first_number == 4)
    {
        printf("VISA\n");
    }
}