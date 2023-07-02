#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
// เก็บเป็น boolean ว่าใครชนะใคร
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();

    for(int i=0; i<pair_count; i++)
    {
        printf("pairs : %i - %i\n", pairs[i].winner, pairs[i].loser);
    }
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    // look for candidate called 'name'
    // if candidate found, update 'ranks' and return 'true'. 'ranks[i]' is the voter's ith perference
    // if no candidate found, dont update any ranks and return false
    bool voted = false;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            voted = true;
        }
    }
    return voted;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // update the preferences array based on the current voter's ranks
    // i j คือดำแหน่งในตาราง
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 1; j < candidate_count; j++)
        {
            preferences[i][j] += 1;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // add each pair of candidates to 'pairs' array if one candidate is preferred over the other
    // update global variable 'pair_count' to be the total number of pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                // create stucture var of pair
                pair p;
                p.winner = i;
                p.loser = j;
                pairs[pair_count] = p;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int i, j, k, winner1, winner2;
    bool swapped;

    // sort pairs in order by decreasing strength of victory
    for (i = 0; i < pair_count - 1; i++)
    {
        // Bubble sort
        swapped = false;
        for (j = 0; j < pair_count - i - 1; j++)
        {
            int strength1 = 0;
            winner1 = pairs[j].winner;
            for (k = 0; k < candidate_count; k++)
            {
                strength1 += preferences[winner1][j];
            }

            int strength2 = 0;
            winner2 = pairs[j + 1].winner;
            for (k = 0; k < candidate_count; k++)
            {
                strength2 += preferences[winner2][j];
            }

            // สลับตัวแปร : กรณีที่ตัวถัดไปมากกว่าตัวแรก
            if (strength2 > strength1)
            {
                pair temp = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
    // Update 'locked' to create the locked graph by adding all edges in decreasing order of victory strength, as long as there is
    // no cycle
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
    // Print out the winner of the election, who will be the source of the graph.
    // You may assume there will not be more than one source.
}