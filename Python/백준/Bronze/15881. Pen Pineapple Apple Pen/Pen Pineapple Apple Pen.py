n = int(input())
S = input()
result = 0
i = 0
while i + 4 <= n:
    # print(S[i:i + 4])
    if S[i:i + 4] == 'pPAp':
        i += 4
        result += 1
    else:
        i += 1

print(result)
