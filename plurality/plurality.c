#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // look for a candidate called name
    // if candidate found, update their vote total and return true
    // if no candidate found, dont update and return false
    bool voted = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            printf("valid name\n");
            candidates[i].votes += 1;
            printf("vote for name %s\n", candidates[i].name);
            printf("total %i\n", candidates[i].votes);
            voted = true;
        }
    }
    return voted;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // print name of candidate most votes
    int max[candidate_count];
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[max[0]].votes - candidates[i].votes <= 0)
        {
            max = i
        }
    }
    // if equal print both name
    return candidates[max].name;
}