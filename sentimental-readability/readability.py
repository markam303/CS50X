from cs50 import get_string
import re


def main():
    # get input text
    text = get_string("Text: ")

    # calculate grade
    # index = 0.0588 * L - 0.296 * S - 15.8 where L letters per 100 words S sentences per 100 words

    # count letters
    lettersNO = get_letters(text)

    # count sentences by spliting them with punctuation '.' '!' or '?'
    sentencesNO = get_sentences(text)

    # count the words by spliting them with space ' '
    wordsNO = len(text.split())

    L = (lettersNO / wordsNO) * 100.00
    S = (sentencesNO / wordsNO) * 100.00

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 1 and index <= 16:
        print(f"Grade: {index}")
    else:
        print("Grade 16+")


def get_letters(text):
    letter_counter = 0
    for char in text:
        if char.isalpha():
            letter_counter += 1
    return letter_counter


def get_sentences(text):
    sentences_counter = 0
    for i in text:
        if i == '.' or i == '!' or i == '?':
            sentences_counter += 1
    return sentences_counter


main()
