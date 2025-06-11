#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // get user input
    if (argc != 2)
    {
        printf("Please provide a word.\n");
        return 1;
    }

    string text = argv[1];
    // its better to declare len here because its used 2 times
    int len = strlen(text);


    for (int i = 0; i < len; i++)
    {
        if (!isalpha(text[i]))
        {
            printf("This is not a letter.\n");
            return 2;
        }
    }


  //  string text;
  //  text = get_string("Input: ");

    // iterate thru each element in string
    for (int i = 1; i < len; i++)
    {
        if (text[i] < text [i - 1])
        {
            printf("No.\n");
            return 0;
        }
    }
        // check if its alphabetical

    // print yes
    printf("Yes.\n");
}
