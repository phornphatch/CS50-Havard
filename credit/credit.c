#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");

    // calculate checksum
    int i = 10;
    while (number % i < number)
    {
    long last_number = number % i;
    if (last_number < 10) {
        printf("last number is, %li\n", last_number);
        number = number / i;
    }
    printf("remaining number is, %li\n", number);
    
    }

    // check card length

    // check starting number
}