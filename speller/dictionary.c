// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int hashed_index = hash(word);
    for (node *ptr = table[hashed_index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            // it is in dictionary
            return true;
        }
    }
    // its not in dictionary
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hashed = 0;
    for (int i = 0; i < 3; i++)
    {
        // if word is shorter than 3 characters add space
        char c = (i < strlen(word)) ? toupper(word[i]) : ' ';
        hashed *= c;
    }

    return (hashed % N);
}

// counter of words loaded into memory
unsigned int word_counter = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Error opening the dictionary!\n");
        return 1;
    }
    // read each word in the file
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        // add each word to hash table
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return 2;
        }
        // copy that word
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // hash the world and insert into hash table
        unsigned int hashed_index = hash(word);
        new_node->next = table[hashed_index];
        table[hashed_index] = new_node;

        // increase global word counter
        word_counter++;
    }
    // close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        // ass long as ptr isnt null
        while (ptr != NULL)
        {
            // create temp pointer so we can free it
            node *temp = ptr;
            // move to next node
            ptr = ptr->next;
            // free current node
            free(temp);
        }
    }
    return true;
}
