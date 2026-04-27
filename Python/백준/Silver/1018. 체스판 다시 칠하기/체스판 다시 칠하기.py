import sys


def input() -> str:
    return sys.stdin.readline().rstrip()


N, M = map(int, input().split())

BOARD = []

for _ in range(N):
    BOARD.append(input())

final_rst = 64


def check(x, y):
    global final_rst
    rst1 = 0
    rst2 = 0
    for i in range(y, y + 8):
        for j in range(x, x + 8):
            if (i + j) % 2 == 0:
                if BOARD[i][j] != "W":
                    rst1 += 1
                elif BOARD[i][j] != "B":
                    rst2 += 1
            else:
                if BOARD[i][j] != "B":
                    rst1 += 1
                elif BOARD[i][j] != "W":
                    rst2 += 1

    if rst1 < final_rst:
        final_rst = rst1
    if rst2 < final_rst:
        final_rst = rst2


for i in range(N - 7):
    for j in range(M - 7):
        check(j, i)

print(final_rst)
