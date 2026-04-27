import sys
from math import sqrt

input = sys.stdin.readline


def is_prime_list(n):
    sieve = [True] * (n + 1)
    m = int(sqrt(n))
    for i in range(2, m + 1):
        if sieve[i]:
            for j in range(i + i, n + 1, i):
                sieve[j] = False
    return sieve


def main():
    T = int(input())
    a = [int(input()) for _ in range(T)]

    P = is_prime_list(max(a))

    for n in a:
        cnt = 0
        for m in range(2, n // 2 + 1):
            if P[m] and P[n - m]:
                cnt += 1
        print(cnt)


if __name__ == '__main__':
    main()
