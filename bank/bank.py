from cs50 import get_string

greeting = get_string("Greeting: ")

remove_prefix = greeting.removeprefix('Hello')

if greeting != remove_prefix:
    print("0$")
