import sys


def input():
    return sys.stdin.readline().strip()


N, M = map(int, input().split())

reverse_streak_list = []
name_list = []

result = 0
for _ in range(N):
    S = input().split()
    A = S[:-1]
    name = S[-1]

    revers_streak = 0
    temp = 0
    for i in range(len(S)):
        if S[i] == '.':
            temp += 1
        else:
            if temp > 0 and temp > revers_streak:
                revers_streak = temp
            temp = 0

    reverse_streak_list.append(revers_streak)
    name_list.append(name)

print(len(set(reverse_streak_list)))
for revers_streak, name in zip(reverse_streak_list, name_list):
    print(revers_streak, name)
