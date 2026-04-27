from itertools import product


def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def solve(N, digits):
    for length in range(1, 13):
        for combination in product(digits, repeat=length):
            num = int(''.join(map(str, combination)))
            if num <= 10 ** 12 and not is_prime(num):
                return "YES", num
    return "NO", None


N = int(input())
digits = list(map(int, input().split()))

print(*solve(N, digits), sep='\n')
