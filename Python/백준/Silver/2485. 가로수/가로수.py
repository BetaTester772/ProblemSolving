from collections import deque
import sys

input = sys.stdin.readline

N = int(input())
A = deque()
B = deque()

for i in range(N):
    A.append(int(input()))
    B.append(A[i] - A[i - 1] if i > 0 else 0)


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


g = B[0]
for i in range(1, N):
    g = gcd(g, B[i])

result = 0

for i in range(1, N):
    result += B[i] // g - 1

print(result)
