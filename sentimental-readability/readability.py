from cs50 import get_string

text = get_string("Text: ")
L = 0
S = 0
actual_grade = 0

#find grade
for i in range(len(text)):
    if i == ","
        total_comma += 1

    if character == ',' or character == ' ':
        total_word += 1
    elif character == '.' or character == '!' or character == ':' or character == '?':
        total_sentence += 1
    else:
        total_letter += 1

L = total_letter // (total_word - total_comma) * 100;
S = total_sentence // (total_word - total_comma) * 100;
grade = (0.0588 * L) - (0.296 * S) - 15.8;

if actual_grade > 16:
    print("Grade 16+");
elif actual_grade < 1:
    print("Before Grade 1");
else:
    print(f"Grade {actual_grade}")