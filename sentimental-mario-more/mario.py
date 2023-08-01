from cs50 import get_int

height = get_int("Height: ")

while height > 1 or height < 8:
    for i in range(height):
        print("")

        for j in range(i):
            print("#")

        print(" ")

        for k in range(i):
            print("#")