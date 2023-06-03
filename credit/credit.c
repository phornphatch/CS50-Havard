#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");
    char str[20];
    sprintf(str, "%ld", number);

    // calculate checksum
    for (int i=strlen(str); i >= 0; i-=2)
    {

        printf("%c ", str[i]);
    }

    // check card length

    // check starting number
}