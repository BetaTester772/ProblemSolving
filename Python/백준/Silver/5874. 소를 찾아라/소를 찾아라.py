S = input()

front = 0

result = 0

for i in range(0, len(S)):
    if S[i:i + 2] == '((':
        front += 1
    elif S[i:i + 2] == '))':
        result += front

print(result)
