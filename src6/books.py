books = []

# Add three books to your shelf
for i in range(3):
    book = dict()
    book["title"] = input("Title: ").strip().lower().capitalize() # ทำให้มันสวยขึ้น เรียบร้อยขึ้น
    book["author"] = input("Author: ")

    books.append(book) # insert book in the lists
    print(book)

# Print book titles
for book in books:
    print(book["title"])