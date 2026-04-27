from math import sqrt
import sys

input = sys.stdin.readline


def prime_list(n):
    sieve = [True] * (n + 1)
    m = int(sqrt(n))
    for i in range(2, m + 1):
        if sieve[i] == True:
            for j in range(i + i, n + 1, i):
                sieve[j] = False
    return [i for i in range(2, n + 1) if sieve[i] == True]


def main():
    A = []
    while True:
        n = int(input())
        if n == 0:
            break
        A.append(n)

    primes = prime_list(max(A) * 2)

    for n in A:
        cnt = 0
        for p in primes:
            if p > n and p <= 2 * n:
                cnt += 1
        print(cnt)


main()
