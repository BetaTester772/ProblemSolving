K, N = map(int, input().split())
A = []
for _ in range(K):
    A.append(int(input()))

A.sort()

n = 0


def solve(left, right):
    global n
    if left > right:
        return

    middle = (left + right) // 2

    if not middle > 0:
        return

    m = 0
    for a in A:
        m += a // middle

    if m >= N:
        n = middle
        solve(middle + 1, right)
    else:
        solve(left, middle - 1)


solve(0, max(A) * 2)
print(n)
