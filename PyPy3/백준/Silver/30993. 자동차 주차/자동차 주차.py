def fac(n):
    if n == 0:
        return 1
    return n * fac(n - 1)


N, A, B, C = map(int, input().split())

print(fac(N) // (fac(A) * fac(B) * fac(C)))
