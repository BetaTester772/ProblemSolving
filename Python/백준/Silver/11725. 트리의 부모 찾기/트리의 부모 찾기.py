import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

N = int(input())
C = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    C[a].append(b)
    C[b].append(a)

P = [-1] * (N + 1)


def find(R):
    for child in C[R]:
        if P[child] == -1:
            P[child] = R
            find(child)


P[1] = 0
find(1)

for i in range(2, N + 1):
    print(P[i])
