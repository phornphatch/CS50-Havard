#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("result: %i\n", convert(input));
}

int convert(string input)
{
    // Start by getting the index of the last char in the string.
    int index_last_char = strlen(input) - 1;
    printf("index of last char %d\n", index_last_char);

    // find last_int : Convert this char into its numeric value.
    int last_int = input[index_last_char] - '0';
    printf("last int %d\n", last_int);

    if (index_last_char <= 0)
    {
        return last_int;
    }
    else
    {
        // Remove the last char from the string by moving the null terminator one position to the left.
        input[strlen(input) - 1] = '\0';
        // Return this value plus 10 times the integer value of the new shortened string.
        return last_int + (10 * convert(input));
    }
    // Remember you need a base case when creating a recursive function.
}