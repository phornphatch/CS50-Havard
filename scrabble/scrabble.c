#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 win\n");
    }
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 2 win\n");
    }
}

int compute_score(string word)
{
    int total_points = 0;

    // loop char in word
    for (int i = 0; i < strlen(word); i++)
    {
        //  หาว่าตัวอักษรที่ใส่มาจะอยู่ลำดับที่เท่าไรของ array of POINTS
        if (isupper(word[i]))
        {
            total_points += POINTS[word[i] - 'A']; // minus A : A in ASCII is 65.
        }
        else if (islower(word[i]))
        {
            total_points += POINTS[word[i] - 'a']; // minus a : a in ASCII is 25.
        }
    }
    return total_points;
}
