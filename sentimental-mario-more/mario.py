from cs50 import get_int

height = get_int("Height: ")

while height < 1 or height > 8:
    try:
        height = get_int("Height: ")
    except ValueError:
        pass

# range(start, stop, step)
for i in range(1, height, 1):
    for j in range(1, height - i, 1):
        print(" ")

    for k in range(1, i, 1):
        print("#")

    print("  ")

    for z in range(1, i, 1):
        print("#")