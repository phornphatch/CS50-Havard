from pyfiglet import Figlet
from cs50 import get_string
from sys import argv

figlet = Figlet()

if len(argv) > 0:
    if argv[1] == '-f' or argv[1] == '--font':
        text = get_string("Input: ")
        print("Output: ")
        figlet.setFont(argv[2])
        print(figlet.renderText(text))
    else:
        print("Invalid usage")
else:
     print("Invalid usage")

