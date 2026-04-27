import sys


def input():
    return sys.stdin.readline().strip()


N = int(input())

for _ in range(N):
    G = int(input())
    A = []

    for _ in range(G):
        A.append(int(input()))

    mod = 1
    while True:
        A_mod = [(a % mod) for a in A]
        if len(set(A_mod)) == G:
            break
        mod += 1
    print(mod)
