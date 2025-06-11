#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    string phrase;
    struct node *next;
}node;

node *table[26];

int hash(string phrase);
bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    // add items
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // find phrase bucket
        int bucket = hash(phrase);
        printf("%s hashes to %i\n", phrase, bucket);
    }
}

// TODO: return the correct bucket for a given phrase
int hash(string phrase)
{
    // returns 0-25, depending on the first char of phrase
    return toupper(phrase[0]) - 'A';

}

bool unload(node *list)
{
    // TODO: free all allocated nodes
    node *ptr = list;
    while (ptr != NULL)
    {
        ptr = list->next;
        free(list);
        list = ptr;
    }
    return true;
}

void visualizer(node *list)
{
    node *print_ptr = list;
    printf("\n+-- List Visualizer --+\n\n");
    while (print_ptr != NULL)
    {
        printf("Address: %p\n", print_ptr);
        printf("Phrase: %s\n", print_ptr->phrase);
        printf("Next: %p\n\n", print_ptr->next);
        print_ptr = print_ptr->next;
    }
    printf("\n+---------------------+\n\n");
}
