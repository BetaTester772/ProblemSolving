a, b, c = map(int, input().split())

if c == 0:
    print(int((a + b) ** (1 / 2)))
else:
    print(c ** 2 - (a + b))
