#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");

    // calculate checksum
    int i = 10;
    int loop_count = 1;
    int sum_even = 0;
    while (number % i < number)
    {
            long last_number = number % i;
            if (last_number < i) {
                printf("last number is, %li\n", last_number);
                number = number / i;
            }
            printf("remaining number is, %li\n", number);
            printf("---\n");
            if (loop_count % 2 == 0) {
                sum_even = sum_even + last_number * 2;
            }
            else
            {
                sum_even += last_number;
            }
            printf("this is sum %i", sum_even);
        loop_count++;
    }

    if (loop_count % 2 == 0)
    {
        sum_even = sum_even + number * 2;
    }
    else
    {
        sum_even += number;
    }

    printf("sum: %i", sum_even);

    // check card length

    // check starting number
}