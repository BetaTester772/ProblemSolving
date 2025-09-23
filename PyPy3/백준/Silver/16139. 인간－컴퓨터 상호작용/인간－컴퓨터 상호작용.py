import sys

input = sys.stdin.readline

string = input()
chars = list(set(string))

S = {}

for char in chars:
    tmp = [0]
    for i in range(len(string)):
        if string[i] == char:
            tmp.append(tmp[-1] + 1)
        else:
            tmp.append(tmp[-1])
    S[char] = tmp

q = int(input())

for _ in range(q):
    a, l, r = input().split()
    l, r = map(int, [l, r])
    if S.get(a) is None:
        print(0)
        continue
    # print(S[a])
    print(S[a][r + 1] - S[a][l])
