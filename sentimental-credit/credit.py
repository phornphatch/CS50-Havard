from cs50 import get_int

credit_card_number = get_int("Number: ")
number = credit_card_number

while number % 10 < number:
    last_number = number % 10
    if last_number < 10:
        number = number / i

    if len(number) % 2 == 0:
        product_last_number = last_number * 2
        if product_last_number > 10
            last_digit_of_product_last_number = product_last_number % 10
            first_digit_of_product_last_number = (product_last_number - last_digit_of_product_last_number) / 10
            sum = sum + last_digit_of_product_last_number + first_digit_of_product_last_number
        elif product_last_number == 0
            sum = sum + 1
        else
            sum = sum + product_last_number
    else
        sum = sum + last_number

    first_number = number

    if len(number) % 2 == 0:
        product_last_number = last_number * 2
        if product_last_number > 10
            last_digit_of_product_last_number = product_last_number % 10
            first_digit_of_product_last_number = (product_last_number - last_digit_of_product_last_number) / 10
            sum = sum + last_digit_of_product_last_number + first_digit_of_product_last_number
        elif product_last_number == 10
            sum = sum + 1
        else
            sum = sum + number * 2
    else
        sum = sum + number

    two_first_number = (credit_card_number - (credit_card_number % pow(10, loop_count - 2))) / (pow(10, loop_count - 2));