# 1 4 10 20 35 56
# 1 3 6 10 15 21
# 1 2 3 4 5 6

array = [list(range(1, 15))]


def solve(n, k):
    if len(array) <= n:
        for i in range(len(array), n + 1):
            new_array = [0] * 14
            for j in range(14):
                new_array[j] = sum(array[i - 1][:j + 1])
            array.append(new_array)

    return array[n][k - 1]


T = int(input())

for _ in range(T):
    n = int(input())
    k = int(input())

    print(solve(n, k))
