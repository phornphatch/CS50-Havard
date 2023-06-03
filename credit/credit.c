#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // get credit cardnumber
    long credit_card_number = get_long("Number: ");
    long number = credit_card_number;
    int first_number = 0;
    int two_first_number = 0;

    // start calculate checksum
    int i = 10;
    int loop_count = 1; // loop count represent the amount of digit
    int sum = 0;
    while (number % i < number)
    {
        // remove last number from all number
        long last_number = number % i;
        if (last_number < i)
        {
            number = number / i; // this number will be remaining number
        }
        // printf("remaining number is, %li\n", number);
        // printf("---\n");

        // digit in even position will multiply by 2
        if (loop_count % 2 == 0)
        {
            int product_last_number = last_number * 2;
            if (product_last_number > 10) // if the result of multiply more than 10, those number should be sum
            {
                int last_digit_of_product_last_number = product_last_number % 10;
                int first_digit_of_product_last_number = (product_last_number - last_digit_of_product_last_number) / 10;
                sum = sum + last_digit_of_product_last_number + first_digit_of_product_last_number;
            }
            else if (product_last_number == 10) // if the result of multiply equal 10, those number should be sum to be 1
            {
                sum += 1;
            }
            else // if the result of multiply < 10, just sum those number
            {
                sum = sum + product_last_number;
            }
        }
        else
        {
            sum += last_number;
        }
        // printf("this is sum %i\n", sum);
        loop_count++; // increase loop
        first_number = number;
    }

    // printf("firstnumber is %i\n", first_number);

    // if the last calculated number (fistnumber of credit card) * 2 > 10, it should be calculated again
    if (loop_count % 2 == 0)
    {
        int product_last_number = number * 2;
        if (product_last_number > 10)
        {
            int last_digit_of_product_last_number = product_last_number % 10;
            int first_digit_of_product_last_number = (product_last_number - last_digit_of_product_last_number) / 10;
            sum = sum + last_digit_of_product_last_number + first_digit_of_product_last_number;
        }
        else if (product_last_number == 10)
        {
            sum += 1;
        }
        else
        {
            sum = sum + number * 2;
        }
    }
    else
    {
        sum += number;
    }

    // find 2 first digit
    two_first_number = (credit_card_number - (credit_card_number % (long) pow(10, loop_count - 2))) / (pow(10, loop_count - 2));
    // printf("this is two first number %i\n", two_first_number);

    //  printf("Super sum: %i\n", sum);
    //  printf("Number of loop: %i\n", loop_count);

    // check checksum is valid according to Luhn’s Algorithm or not
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    // check card length and two first number
    else if (loop_count == 15 && (two_first_number == 34 || two_first_number == 37))
    {
        printf("AMEX\n");
    }
    else if (loop_count == 16 && (two_first_number > 50 && two_first_number < 56))
    {
        printf("MASTERCARD\n");
    }
    else if (loop_count == 16 && first_number == 4)
    {
        printf("VISA\n");
    }
    else if (loop_count == 13 && first_number == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}