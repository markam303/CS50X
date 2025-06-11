// Basic encrypting 

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int only_digits(string key);
char rotate(char letter, int key);
string ciphering(string text, int key);

int main(int argc, string argv[])
{
    // chceck command-line input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // use function only_digits to determine if there are only digits
    if (!only_digits(argv[1]))
    {
        return 1;
    }

    // convert string key into int key
    int key = atoi(argv[1]);

    // prompt user for input text

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    string ciphertext = ciphering(plaintext, key);


}

string ciphering(string text, int key)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char cipher = rotate(text[i], key);
        printf("%c", cipher);
    }
    printf("\n");
    return 0;
}

char rotate(char letter, int key)
{
    if(!isalpha(letter))
    {
        return letter;
    }
    else
    {
        letter += key;
        while (!isalpha(letter))
        {
            letter -= 26;
        }
    }
    return letter;
}


int only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if(!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 0;
        }
    }
    return 1;
}
