import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))

s, e = 0, 0

result = float('inf')
sum = A[0]
while s <= e < len(A):
    # print(s, e, sum)
    if sum >= M and e >= s:
        result = min(result, e + 1 - s)
        sum -= A[s]
        s += 1
        if e < s <= len(A) - 1:
            e += 1
            sum += A[e]
    elif e < len(A) - 1:
        e += 1
        sum += A[e]
    elif e == len(A) - 1:
        sum -= A[e]
        s += 1

print(result if 0 < result != float('inf') else 0)
