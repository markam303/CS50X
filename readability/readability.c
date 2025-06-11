// Mark readability level needed for certain text

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letters(string text);
int get_sentences(string text);
int get_words(string text);

int main(void)
{
    // get input text
    string text = get_string("Text: ");

    // calculate grade
    // index = 0.0588 * L - 0.296 * S - 15.8 where L letters per 100 words S sentences per 100 words
    long lettersNum = get_letters(text);
    long sentencesNum = get_sentences(text);
    double wordsNum = get_words(text);
    double L_helper = lettersNum / wordsNum;
    double S_helper = sentencesNum / wordsNum;
    double L = L_helper * 100.00;
    double S = S_helper * 100.00;

    // printf("Letters, words, sentences: %li & %f & %li \n L: %f, S: %f.\n", lettersNum, wordsNum, sentencesNum, L, S);

    // print Grade X
    // calculate index
    double index = 0.0588 * L - 0.296 * S - 15.8;
    long index2 = round(index);

    // printf("Index: %f \n", index);

    if (index2 < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index2 >= 1 && index2 < 16)
    {
        printf("Grade %li\n", index2);
    }
    else
    {
        printf("Grade 16+\n");
    }
    // grades 1-16
    // grade over 16+
    // grade 'before grade 1'
}

int get_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int get_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentences++;
        }
    }
    return sentences;
}

int get_words(string text)
{
    int words = 1;
    for (int i = 0, len = strlen(text); i <= len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}
