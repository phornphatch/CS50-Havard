#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");
    int first_number;
    int two_first_number;

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
            if (number % 100 > 0) {
                two_first_number = number;
                printf("wthh %i\n", two_first_number);
            }


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

    printf("firstnumber is %i\n", first_number);

    if (loop_count % 2 == 0)
    {
        sum = sum + number * 2;
    }
    else
    {
        sum += number;
    }

    // printf("Super sum: %i\n", sum);
    //  printf("Number of loop: %i\n", loop_count);

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }



    // check card length and first number
    if (loop_count == 15 && first_number == 3) {
        printf("AMEX\n");
    }
     if (loop_count == 16 && first_number == 5) {
        printf("MASTERCARD\n");
    }
    if (loop_count == 16 && first_number == 4) {
            printf("VISA\n");
    }
    if (loop_count == 13 && first_number == 4) {
        printf("VISA\n");
    }



    // check starting number
}