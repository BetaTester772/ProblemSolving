import sys

from collections import defaultdict

input = sys.stdin.readline

N, M = map(int, input().split())

A = list(map(int, input().split()))

S = [0] * (N + 1)

count = defaultdict(int)

for i in range(N):

    S[i + 1] = (S[i] + A[i]) % M

    count[S[i + 1]] += 1


count[0] += 1

res = 0

for c in count.values():

    res += c * (c - 1) // 2  # 같은 나머지를 가진 쌍의 수

print(res)