from cs50 import get_int

credit_card_number = get_int("Number: ")
credit_card_string = str(credit_card_number)
number_length = len(credit_card_string)
sum_even = 0
sum_odd = 0
sum = 0
i = 1
j = 0

for i in range(1, number_length, 2):
    multiply = int(credit_card_string[i])*2
    if multiply < 10:
        sum_even += multiply
    else:
        multiply = str(multiply)
        sum_even += (int(multiply[0]) + int(multiply[2]))


for j in range(0, number_length, 2):
    sum_odd += int(credit_card_string[i])
print(sum_odd)

sum = sum_even + sum_odd

print(sum)

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