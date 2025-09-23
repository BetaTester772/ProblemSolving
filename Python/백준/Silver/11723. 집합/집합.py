import sys


def input():
    return sys.stdin.readline().rstrip()


def print(value, end='\n'):
    sys.stdout.write(str(value) + end)


M = int(input())

S = 0

for _ in range(M):
    inst = input().split()
    if inst[0] == 'add':
        S |= (1 << int(inst[1]))
    elif inst[0] == 'remove':
        S &= ~(1 << int(inst[1]))
    elif inst[0] == 'check':
        print(1 if (1 << int(inst[1])) & S != 0 else 0)
    elif inst[0] == 'toggle':
        S ^= (1 << int(inst[1]))
    elif inst[0] == 'all':
        S = ((1 << 21) - 1)
    else:
        S = 0
