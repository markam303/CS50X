// Check if Credit Card provided is valid

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

int count_digits(long long card_number); // helper function to count digits
bool luhn_apply(long long card_number);  // function to apply luhn algorithm
string card_type(long long card_number); // determining card type

int main(void)
{
    // Get CC number as input
    long long card_number;
    do
    {
        card_number = get_long("Number: "); // get CC number
    }
    while (card_number < 0);

    // Check if number is valid and apply Luhn's
    if (luhn_apply(card_number))
    {
        printf("%s\n", card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// count digits in a number
int count_digits(long long card_number)
{
    int count = 0;
    while (card_number > 0)
    {
        card_number /= 10;
        count++;
    }
    return count;
}

// apply luhn algorithm
bool luhn_apply(long long card_number)
{
    int sum = 0;
    bool alt = false; // flagging every other digit
    // Multiply every other digit by 2 starting from second-to-last
    while (card_number > 0)
    {
        int digit = card_number % 10;
        card_number /= 10;

        if (alt)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10);
            }
        }
        sum += digit;
        alt = !alt; // flag toggle
    }
    return sum % 10 == 0;
}

// check CC type
string card_type(long long card_number)
{
    long long first_two_digits = card_number;
    while (first_two_digits >= 100)
    {
        first_two_digits /= 10;
    }
    if (count_digits(card_number) == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX";
    }
    else if (count_digits(card_number) == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        return "MASTERCARD";
    }
    else if (first_two_digits / 10 == 4 &&
             (count_digits(card_number) == 13 || count_digits(card_number) == 16))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}
