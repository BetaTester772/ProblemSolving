N = int(input())

S: list[str] = []

for _ in range(N):
    s = input()

    if not (s.isdigit()) and not (len(s) > 10):
        S.append(s)

# print(S)

result = []

for s in S:
    upper = 0
    lower = 0

    for c in s:
        if c.isupper():
            upper += 1
        elif c.islower():
            lower += 1

    if not (upper > lower):
        print(s)
        break
