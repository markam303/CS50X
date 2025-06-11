# Print half-pyramid from Problem Set 1

from cs50 import get_int


def main():
    """Get height from user"""
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break

    """Print pyramids"""
    for i in range(height):
        # Print spaces for left pyramid
        print(" " * (height - i - 1), end="")

        # Print hashes for left pyramid
        print("#" * (i + 1), end="")

        # Print 2 spaces separation
        print("  ", end="")

        # Print hashes for right side
        print("#" * (i + 1))


main()
