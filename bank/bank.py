from cs50 import get_string

greeting = get_string("Greeting: ")

remove_prefix = greeting.removeprefix('Hello')

if greeting != remove_prefix:
    print("$0")
elif greeting[0] == 'H':
    print("$20")
else:
    print("$100")