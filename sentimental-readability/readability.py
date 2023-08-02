from cs50 import get_int

text = get_int("Text: ")
L = 0
S = 0
actual_grade = 0

#find grade


if actual_grade > 16:
    print("Grade 16+");
elif actual_grade < 1:
    print("Before Grade 1");
else:
    print(f"Grade {actual_grade}")