#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
}
node;

node *table[26]; // new array named table ที่ pointer to node มี 26 ตัวอักษร

int hash(string phrase); // new phrase

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");
        int index = hash(phrase);
        printf("%s hashes to %i\n", phrase, index);
    }
}

// TODO: return an index, 0–25, for a given phrase
int hash(string phrase)
{
    return toupper(phrase[0]) - 'A';
    // A = 65
    // A - A = 0
    // B - A = 1
    // Z - A = 25
 }