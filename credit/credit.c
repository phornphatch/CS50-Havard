#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");

    // calculate checksum
    long last_number = number % 10;
    if (last_number < 10) {
        printf("hello, %li", last_number);
        number = number - last_number
    }
    // check card length

    // check starting number
}