def cal_grade(text):
    total_letter = 0
    total_comma = 0
    total_word = 1  # count by space + 1 to start with 1
    total_sentence = 0  # count by . or !

    for character in text:
        if character == ',':
            total_comma += 1

        if character == ',' or character == ' ':
            total_word += 1
        elif character == '.' or character == '!' or character == ':' or character == '?':
            total_sentence += 1
        elif character != "'":
            total_letter += 1

    L = (total_letter / (total_word - total_comma)) * 100
    S = (total_sentence / (total_word - total_comma)) * 100
    grade = (0.0588 * L) - (0.296 * S) - 15.8
    return grade

def main():
    # get text from user
    text = input("Text: ")

    # print grade with conditions
    actual_grade = cal_grade(text)
    if actual_grade > 16:
        print("Grade 16+")
    elif actual_grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {int(round(actual_grade))}")

if __name__ == "__main__":
    main()
