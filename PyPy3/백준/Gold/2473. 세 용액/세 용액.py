N = int(input())
A = sorted(list(map(int, input().split())))
a, b, c = 0, 1, N - 1
current = float('inf')

for first in range(0, N - 1):
    second = first + 1
    third = N - 1
    while first < second < third <= N - 1:
        tmp = A[first] + A[second] + A[third]

        if abs(tmp) < current:
            current = abs(tmp)
            a, b, c = first, second, third

        if tmp < 0:
            second += 1
        elif tmp > 0:
            third -= 1
        else:
            break

print(*sorted([A[a], A[b], A[c]]))
