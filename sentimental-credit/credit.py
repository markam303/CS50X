from cs50 import get_int


def main():
    """ Get the card number from user """
    while True:
        card_number = get_int("Number: ")
        if card_number > 0:
            break
    # Check the card type
    card_type = check_type(card_number)

    # If the card is valid, apply Luhn algorithm
    if card_type != "INVALID":
        if luhn_algorithm(card_number):
            print(card_type)
        else:
            print("INVALID")
    else:
        print("INVALID")


def check_type(card_number):
    """ Check type of card (MasterCard, VISA, AMEX) """
    # Convert to string
    card_number = str(card_number)

    # Check if MC
    if (card_number.startswith(("51", "52", "53", "54", "55")) and len(card_number) == 16):
        return "MASTERCARD"
    # Check if VISA
    elif (card_number.startswith("4") and (len(card_number) == 13 or len(card_number) == 16)):
        return "VISA"
    # Check if AMEX
    elif (card_number.startswith(("34", "37")) and len(card_number) == 15):
        return "AMEX"
    # If nothing from above
    return "INVALID"


def luhn_algorithm(card_number):
    """ Apply Luhn's algorithm """
    # Convert CC number and reverse it
    card_number = str(card_number)[::-1]

    # Initialize sum of digits
    sum = 0

    # Loop through each digit in already reversed card number
    for i, digit in enumerate(card_number):
        digit = int(digit)

        # Double every second digit (from right)
        if i % 2 != 0:
            doubled = digit * 2

            # if result in 2 digits number
            if doubled > 9:
                sum += (doubled % 10) + (doubled // 10)
            else:
                sum += doubled
        else:
            # add digit to the sum
            sum += digit

    # check if total sum can be divided by 10
    return sum % 10 == 0


main()
