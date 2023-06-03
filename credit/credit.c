#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // get credit cardnumber
    long credit_card_number = get_long("Number: ");
    long number = credit_card_number;
    int first_number = 0;
    int two_first_number = 0;

    // calculate checksum
    int i = 10;
    int loop_count = 1;
    int sum = 0;
    while (number % i < number)
    {
            long last_number = number % i;
            if (last_number < i) {
                // printf("last number is, %li\n", last_number);
                number = number / i;
            }
            // printf("remaining number is, %li\n", number);
            // printf("---\n");

            if (loop_count % 2 == 0) {
                int product_last_number = last_number * 2;
                if (product_last_number >= 10)
                {
                    int last_digit_of_product_last_number = product_last_number % 10;
                    int first_digit_of_product_last_number = (product_last_number - last_digit_of_product_last_number)/10;
                    sum = sum + last_digit_of_product_last_number + first_digit_of_product_last_number;
                }
                else
                {
                sum = sum + last_number * 2;
                }
            }
            else
            {
                sum += last_number;
            }
            // printf("this is sum %i\n", sum);
        loop_count++;
        first_number = number;
    }

    // printf("firstnumber is %i\n", first_number);

    if (loop_count % 2 == 0)
    {
        sum = sum + number * 2;
    }
    else
    {
        sum += number;
    }

    // find 2 first digit

        two_first_number = (credit_card_number - (credit_card_number % (long) pow(10, loop_count - 2)))/ (pow(10, loop_count - 2));
        // printf("this is two first number %i\n", two_first_number);

    // printf("Super sum: %i\n", sum);
    //  printf("Number of loop: %i\n", loop_count);

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }



    // check card length and first number
    if (loop_count == 15) {
        if (two_first_number == 34 || two_first_number == 37)
        {
        printf("AMEX\n");
        }
    }
     if (loop_count == 16) {
        if (two_first_number >= 51 && two_first_number <= 55)
        {
        printf("MASTERCARD\n");
        }
    }
    if (loop_count == 16 && first_number == 4) {
            printf("VISA\n");
    }
    if (loop_count == 13 && first_number == 4) {
        printf("VISA\n");
    }



    // check starting number
}