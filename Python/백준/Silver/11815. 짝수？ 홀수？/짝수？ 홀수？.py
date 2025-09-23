import math

N = int(input())
A = list(map(int, input().split()))

for a in A:
    if int(math.sqrt(a)) ** 2 == a:
        print(1, end=' ')
    else:
        print(0, end=' ')
