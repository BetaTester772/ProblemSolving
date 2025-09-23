strict = 0
N = int(input())
slist = list(map(int, input().split()))

stricts = []

for i in range(N):
    if slist[i] != 0:
        strict += 1
    else:
        stricts.append(strict)
        strict = 0
stricts.append(strict)
print(max(stricts))
