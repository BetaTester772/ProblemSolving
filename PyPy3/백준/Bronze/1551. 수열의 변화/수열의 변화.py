N, K = map(int, input().split())
i_list = list(map(int, input().split(',')))


def get_B(A):
    B = [0] * (N - j)
    for i in range(0, N - j):
        B[i] = A[i + 1] - A[i]
    return B


j = 1

for i in range(K):
    i_list = get_B(i_list)
    j += 1

for i in range(len(i_list)):
    if i != 0:
        print(',', end='')
    print(str(i_list[i]), end='')
