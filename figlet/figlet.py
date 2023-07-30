from pyfiglet import Figlet
from cs50 import get_string
from sys import argv

figlet = Figlet()

if len(argv) > 0:
    if argv[1] == '-f' or argv[1] == '--font':
        if argv[2] in figlet.getFonts():
            font = argv[2]
            text = get_string("Input: ")
            print("Output: ")
            figlet.setFont(font=font)
            print(figlet.renderText(text))
        else:
            print("Invalid usage")
            sys.exit(1)
    else:
        print("Invalid usage")
        sys.exit(1)
else:
     print("Invalid usage")
     sys.exit(1)

