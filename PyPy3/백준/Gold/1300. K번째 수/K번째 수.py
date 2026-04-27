N = int(input())
K = int(input())

n = None


def solve(start, end):
    global n
    if start > end:
        return

    middle = (start + end) // 2

    if not middle > 0:
        return

    # print('middle', middle)

    m = 0
    for i in range(1, N + 1):
        if middle // i > N:
            m += N
        else:
            m += middle // i

    # print(middle, m)

    if m < K:
        solve(middle + 1, end)
    else:
        n = middle
        solve(start, middle - 1)


solve(1, N ** 2)
print(n)
