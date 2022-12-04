from cs50 import get_int

h = get_int("Height: ")

while ((h < 1) or (h > 8)):
    h = get_int("Height: ")

for r in range(h):
    for c in range(h):
        if c + r >= h - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()