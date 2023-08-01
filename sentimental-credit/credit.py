from cs50 import get_int

credit_card_number = get_int("Number: ")
credis_card_string = str(credit_card_number)
number_length = len(credit_card_string)
sum = 0

for range(i, number_length, 2)
    

# Check checksum is valid according to Luhn's Algorithm or not
if sum % 10 != 0:
    print("INVALID")
# Check card length and two first number
elif loop_count == 15 and (two_first_number == 34 or two_first_number == 37):
    print("AMEX")
elif loop_count == 16 and (50 < two_first_number < 56):
    print("MASTERCARD")
elif loop_count == 16 and first_number == 4:
    print("VISA")
elif loop_count == 13 and first_number == 4:
    print("VISA")
else:
    print("INVALID")