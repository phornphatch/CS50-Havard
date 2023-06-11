// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string newword;
string replace(string word);

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("%s\n", replace(argv[1]));
    }
    else
    {
        printf("not ok"); return 1;
    }
}

// function replace : take string and return string
string replace(string word)
{
    for (int i=0; i < strlen(word); i++)
    {
        newword += i;
    } return newword;
}