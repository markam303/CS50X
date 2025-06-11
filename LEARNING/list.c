#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    string phrase;
    struct node *next;
} node;

#define LIST_SIZE 2

bool unload(node *list);
void visualizer(node *list);

int main(void)
{
    node *list = NULL;

    // add items to list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        string phrase = get_string("Enter a new phrase: ");

        // TODO: add phrase to new code in list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->phrase = phrase;
        n->next = list;
        list = n;

        // visualize a list after adding a new node
        visualizer(list);
    }

    // free all memory used
    if (!unload(list))
    {
        printf("Error freeing the list.\n");
        return 1;
    }

    printf("Freed the list.\n");
    return 0;
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

