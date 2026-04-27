import sys


def input():
    return sys.stdin.readline().rstrip()


M = int(input())
sum = 0
xor = 0

for _ in range(M):
    Q = list(map(str, input().split()))

    if Q[0] == '1':
        sum += int(Q[1])
        xor ^= int(Q[1])
    elif Q[0] == '2':
        sum -= int(Q[1])
        xor ^= int(Q[1])
    elif Q[0] == '3':
        print(sum)
    elif Q[0] == '4':
        print(xor)
