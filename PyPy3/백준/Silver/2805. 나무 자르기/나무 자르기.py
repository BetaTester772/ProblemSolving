N, M = map(int, input().split())
A = list(map(int, input().split()))

A.sort()

n = 0


def solve(start, end):
    global n
    if start > end:
        return

    middle = (start + end) // 2

    if not middle > 0:
        return

    m = 0
    for a in A:
        if a - middle > 0:
            m += a - middle

    if m >= M:
        if middle > n:
            n = middle
        solve(middle + 1, end)
    else:
        solve(start, middle - 1)


solve(0, max(A))
print(n)
