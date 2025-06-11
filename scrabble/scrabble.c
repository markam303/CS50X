// Scrabble game based on two user's input

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// scoring outside of any function
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // get Player 1 word
    string player1word = get_string("Player 1: ");
    // get Player 2 word
    string player2word = get_string("Player 2: ");

    // calculate points
    int player1points = compute_score(player1word);
    int player2points = compute_score(player2word);

    // compare points and print a winner
    if (player1points > player2points)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1points < player2points)
    {
        printf("Player 2 wins!\n");
    }
    else
        printf("Tie!\n");
}

int compute_score(string word)
{
    // compute and return score for word
    // compute value of single letter then loop it
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }
    return score;
}
