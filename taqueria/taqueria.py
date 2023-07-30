menus = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    total = 0

    while True:
        try:
            item = input("Item: ").capitalize()
            if item in menus:
                print(f"{item}")
                total += menus.get(item)
                print(f"${total}")
            else:
                print("noitem in menu")
        except EOFError:
            return False
            print("\n")
            sys.exit(1)
main()