import sys

sys.setrecursionlimit(10 ** 4 + 1)
input = sys.stdin.readline

S = []

while True:
    try:
        S.append(int(input()))
    except:
        break


def bst(l, r):
    if r - l < 0:
        return

    middle = l + 1

    for i in range(l + 1, r + 1):
        if S[i] > S[l]:
            middle = i
            break
    # print(S[l+1: middle+1])
    bst(l + 1, middle-1)
    # print(S[middle+1: r+1])
    bst(middle, r)
    # print(middle, V)
    sys.stdout.write(str(S[l])+'\n')


# print(S)
bst(0, len(S) - 1)
