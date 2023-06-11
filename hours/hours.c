#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// calc_hours function

// declare var to be float for decimal
float A = 0;
float a = 0;
float T = 0;

float calc_hours(int hours[], int weeks, char output)
{
    if (output == 'T')
    {

        for (int i = 0; i < weeks; i++)
        {
            T += hours[i]; // only total
        }
        return T; // return total value to calc_hours function
    }
    else if (output == 'A')
    {

        for (int i = 0; i < weeks; i++)
        {
            T += hours[i];
        }
        A = T / weeks; // avg is total divided weeks
        return A; // return avg value to calc_hours function
    }
    return 0; // return 0 if null
}