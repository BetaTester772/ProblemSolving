import sys


def input():
    return sys.stdin.readline().rstrip()


t = int(input())
for _ in range(t):
    input()
    r, c = map(int, input().split())

    S_list = []

    for i in range(r):
        S_list.append(list(input()))

    result = 0

    for i in range(0, r):
        for j in range(0, c):
            if S_list[i][j] == 'o':
                if j - 1 >= 0 and j + 1 < c and S_list[i][j - 1] == '>' and S_list[i][j + 1] == '<':
                    result += 1
                if i - 1 >= 0 and i + 1 < r and S_list[i - 1][j] == 'v' and S_list[i + 1][j] == '^':
                    result += 1

    print(result)
