import sys


def input():
    return sys.stdin.readline().rstrip()


n = int(input())


def round(num):
    if num - int(num) >= 0.5:
        return int(num) + 1
    else:
        return int(num)


levels = []

for _ in range(n):
    levels.append(int(input()))

levels.sort()
# print(levels)

cut = round(n * 0.15)
# print(cut)
new_levels = levels[cut:-cut]
# print(levels)

if len(new_levels) == 0:
    if len(levels) == 0:
        print(0)
    else:
        print(round(sum(levels) / len(levels)))
else:
    print(round(sum(new_levels) / len(new_levels)))
