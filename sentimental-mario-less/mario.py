# print reversed half of pyramid

from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break

    for i in range(height):
        print_row(height - i, i + 1)
        print()


def print_row(space, brick):
    for _ in range(space - 1, 0, -1):
        print(" ", end="")
    for _ in range(0, brick, 1):
        print("#", end="")


main()
