// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string word;
string newword;

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("ok");
        word = argv[1];
        replace(word);
        printf("%s\n", newword);
    }
    else
    {
        prints("not ok") return 1;
    }
}

// function replace : take string and return string
string replace(word)
{
    int length = strlen(word)
}