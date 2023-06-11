// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include<string.h>

string newword;
string replace(string word);
int j = 0;

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
    }
    else if (argc == 1)
    {
        printf("Usage: %s word\n", argv[0]);
    }
    else
    {
        printf("not ok\n"); return 1;
    }
}

// function replace : take string and return string
string replace(string word)
{
    for (int j = 0, j < strlen(word); j++)
    {
        printf("%c\n", argv[0][j]);
    }
    printf("\n");
}