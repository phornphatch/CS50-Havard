#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");

    // calculate checksum
    int i = 10;
    int loop_count = 1;
    while (number % i < number)
    {
            long last_number = number % i;
            if (last_number < i) {
                printf("last number is, %li\n", last_number);
                number = number / i;
            }
            printf("remaining number is, %li\n", number);
            printf("---\n");
        loop_count++;
    }

    // check card length

    // check starting number
}