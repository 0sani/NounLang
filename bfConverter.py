import re

with open("HelloWorld.txt", "r") as f:
    data = f.read()
    f.close()

out = ""

keys = [">", "<", "+", "-", ".", ",", "[", "]"]

current = 0
currentPos = 2

words = re.split(" |\n", data)

for word in words:
    word = word.lower()
    if (word == "the"):
        currentPos -= 1
    elif (word == "a" or word == "an"):
        current += 2 ** currentPos
        currentPos -= 1

    if (currentPos == -1):
        currentPos = 2
        out += keys[current]
        current = 0

print(out)
