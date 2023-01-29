import sys

input = sys.stdin.readline()

words = input.split("WUB")

for w in words:
    if w != '' or w != '\n':
        sys.stdout.write(w + ' ')