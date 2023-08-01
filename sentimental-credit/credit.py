from cs50 import get_int

credit_card_number = get_int("Number: ")
number = int(credit_card_number)
sum = 0
loop_count = 1

while number % 10 < number:
    last_number = number % 10
    if last_number < 10:
        number = number / 10

    if loop_count % 2 == 0:
        product_last_number = last_number * 2
        if product_last_number > 10:
            last_digit_of_product_last_number = product_last_number % 10
            first_digit_of_product_last_number = (product_last_number - last_digit_of_product_last_number) / 10
            sum = sum + last_digit_of_product_last_number + first_digit_of_product_last_number
        elif product_last_number == 0:
            sum = sum + 1
        else:
            sum = sum + product_last_number
    else:
        sum += last_number
    loop_count += 1
    first_number = number

    if loop_count % 2 == 0:
        product_last_number = last_number * 2
        if product_last_number > 10:
            last_digit_of_product_last_number = product_last_number % 10
            first_digit_of_product_last_number = (product_last_number - last_digit_of_product_last_number) / 10
            sum = sum + last_digit_of_product_last_number + first_digit_of_product_last_number
        elif product_last_number == 10:
            sum = sum + 1
        else:
            sum = sum + number * 2
    else:
        sum = sum + number

    two_first_number = (credit_card_number - (credit_card_number % pow(10, loop_count - 2))) / (pow(10, loop_count - 2));

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