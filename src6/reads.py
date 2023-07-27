import csv

books = []

# Add books to your shelf by reading from books.csv
with open("books.csv") as file: # หมายความว่า open csv นั้น แล้วเรียกว่า file
    file_reader = csv.DictReader(file) # จะใช้ reader ก้ได้ แต่มันจะออกหัวตารางมาด้วย ในที่นี้คือ "title, author"
    for book in file_reader:
        books.append(book) # append คือ adds an item to the end of the list.

# Print titles of books
for book in books:
    print(book["title"])

# ไม่ต้อง close เพระา python ทำมาให้แล้ว