// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next; // pointer = address of the next node
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
// larger N means more buckets.
// if your function ends up with a value > N, you can take the value % N toget a value in the appropriate range

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // return true if the word is in the dictory, otherwise false
    // case sensitive
    // hash word to obtain a hash value
    // access linked list at that index in the hash table
    // Traverse linked list, looking for the word (strcasecmp : campare to string with case sensitive)
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // take a word and input withalphabetical characters and apostopphes
    // output a number corresponding to which "bucket" to store the word in (numerical index between 0 and N -1)
    // each index inside hash table will be linked list (node : value + pointer to next node)
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
       // use fopen
       // remember to check if return value is null
    // read strings from file one at a time
       //  use fscanf(file, %s , word)
       // fscan will return EOF ince it reaches end of file
    // create a new node for each word
       // use malloc
       // remember to check if return value is null
       // copy the word into that node using strcpy function
    // hash word using hash function to obtain a hash value
       // use hash function
       // function takes a string and return an index
    // insert node into hash table at the location
       // recall that hash table is an array of linked list
       // besure to set pointers in the correct order
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO return number of word
    // keep track number of word that you added
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
