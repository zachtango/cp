inp = input().split(' ')

n = int(inp[0])
k = int(inp[1])

if k >= 350:
    print("Your wish is granted!")
elif 2**k < n:
    print("You will become a flying monkey!")
else:
    print("Your wish is granted!")

