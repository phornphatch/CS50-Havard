text = "In the great green room"
words = text.split() # split by word

# Round 1
print("Round 1")
for word in words:
    print(word)
print()
# In
# the
# great
# green
# room

print("Round 1")
for word in words:
    print(word, end=" ") # ต่อ space at the end
print()
# In the great green room

# Round 2
print("Round 2")
for word in words:
    for c in word:
        print(c)
print()
# I
# n
# t
# h
# ...

# Round 3
print("Round 3")
for word in words:
    if "g" in word:
        print(word)
print()
# great
# green

# Round 4
print("Round 4")
for word in words[2:]:
    print(word)
print()

# Round 5
print("Round 5")
for word in words:
    print("Goodnight Moon")
print()