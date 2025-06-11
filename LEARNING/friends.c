#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // name
    string name = get_string("What's ur name? ");

    // age
    int age = get_int("Your age: ");

    // hometown
    string town = get_string("Where ya from? ");

    // phone numero
    string phone = get_string("Please, type in your phone number: ");


    printf("My new friend's name is %s, %i, from %s, reach him at %s. \n", name, age, town, phone);
}
