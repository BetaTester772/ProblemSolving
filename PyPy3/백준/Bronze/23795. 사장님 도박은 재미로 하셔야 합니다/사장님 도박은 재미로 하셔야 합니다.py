import sys


def input():
    return sys.stdin.readline().strip()


num = 0
result = 0
while num > -1:
    result += num
    num = int(input())
print(result)
