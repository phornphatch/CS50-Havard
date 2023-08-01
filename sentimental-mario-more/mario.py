from cs50 import get_int

height = get_int("Height: ")

while height < 1 or height > 8:
    try:
        height = get_int("Height: ")
    except ValueError:
        pass

for i in range(1, height, 1):
    print("")

    for j in range(i, 1):
        print("#")

    print(" ")

    for k in range(i, 1):
        print("#")