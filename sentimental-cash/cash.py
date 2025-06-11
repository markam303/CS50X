# How many coins should i get back as a change

from cs50 import get_float


def main():
    while True:
        owed = get_float("Change owed in dollars: ")
        if owed > 0:
            break

    # QUARTER = 0.25
    # DIME = 0.10
    # NICKEL = 0.05
    # PENNY = 0.01

    coins= {'QUARTER': 0.25, 'DIME': 0.10, 'NICKEL': 0.05, 'PENNY': 0.01}

    quarters_number = int(owed / coins['QUARTER'])
    owed = round(owed - quarters_number * 0.25, 2)

    dimes_number = int(owed / coins['DIME'])
    owed = round(owed - dimes_number * 0.10, 2)

    nickels_number = int(owed / coins['NICKEL'])
    owed = round(owed - nickels_number * 0.05, 2)

    pennies_number = round(owed / coins['PENNY'])

    change = quarters_number + dimes_number + nickels_number + pennies_number
    print(change)


main()
