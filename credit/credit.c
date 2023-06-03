#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string str;
    // get credit cardnumber
    long number = get_long("Number: ");
    sprintf(str, "%ld", number);

    // calculate checksum
    for (int i=1; i < strlen(str); i++)
    {

        printf("string: %c", str[i]);
    }

    // check card length

    // check starting number
}