#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // get credit cardnumber
    long number = get_long("Number: ");
    char str[20];
    sprintf(str, "%ld", number);

    int sum1 = 0;
    // calculate checksum
    for (int i=strlen(str); i >= 0; i-=2)
    {

        printf("%c ", str[i]);
        int a = atoi(str[i]);
        sum1 += a;
    }
    printf("sum1: %i)

    // check card length

    // check starting number
}