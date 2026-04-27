Y, M, D = map(int, input().split('-'))
N = int(input())

D += N

while D > 30:
    D -= 30
    M += 1

while M > 12:
    M -= 12
    Y += 1

if M < 10:
    M = "0" + str(M)

if D < 10:
    D = "0" + str(D)

print(f"{Y}-{M}-{D}")
