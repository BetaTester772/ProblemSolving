matchstick_map = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

N = int(input())


def find_num():
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for l in range(10):
                    m = ((i * 10 + j) + (k * 10 + l)) // 10
                    n = ((i * 10 + j) + (k * 10 + l)) % 10

                    if m < 10 and n < 10 and matchstick_map[i] + matchstick_map[j] + matchstick_map[k] + matchstick_map[
                        l] + matchstick_map[m] + matchstick_map[n] == N - 4:
                        return i, j, k, l, m, n


def solve():
    nums = find_num()
    if nums:
        i, j, k, l, m, n = nums
        print(f"{i}{j}+{k}{l}={m}{n}")
    else:
        print("impossible")


solve()
