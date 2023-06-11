// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string newword;
string replace(string word);

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
        printf("not ok\n");
        return 1;
    }
}

// function replace : take string and return string
string replace(string word)
{
    int i = 0;
    for (i = 0; i < strlen(word); i++)
    {
        char character = word[i];
        // printf("%c\n", character);
        if (character == h) {
            printf("%c\n", character);
        }
        // switch (character)
        // {
        // case character == "a":
        //     printf("a is 6\n");
        //     break;

        // case character == "e":
        //     printf("e is 3\n");
        //     break;

        // default:
        //     printf("what\n");
        //     break;
        // }
    }
    return "b";
}