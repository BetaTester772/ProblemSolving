def combination_n_2(n):
    return n * (n - 1) // 2


def get_sum_of_game(B):
    A = B * k
    cache = combination_n_2(M)
    return N * cache * A + (combination_n_2(N * M) - N * cache) * B


def binary_search_max_sum(D):
    left, right = 1, D
    max_sum = -1
    while left <= right:
        mid = (left + right) // 2
        temp = get_sum_of_game(mid)
        if temp <= D:
            max_sum = max(max_sum, temp)
            left = mid + 1  # Move right to find a potentially higher valid sum
        else:
            right = mid - 1  # Move left since mid is too large
    return max_sum


T = int(input())
for _ in range(T):
    N, M, k, D = map(int, input().split())
    max_sum = binary_search_max_sum(D)
    print(max_sum)
