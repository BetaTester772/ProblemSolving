from collections import deque
import sys

input = sys.stdin.readline

deque = deque()


def pushLeft(x):
    deque.appendleft(x)
    return


def pushRight(x):
    deque.append(x)
    return


def popLeft():
    return deque.popleft() if deque else -1


def popRight():
    return deque.pop() if deque else -1


def size():
    return len(deque)


def empty():
    return 0 if deque else 1


def Left():
    return deque[0] if deque else -1


def Right():
    return deque[-1] if deque else -1


N = int(input())

for _ in range(N):
    command = input().split()
    if command[0] == '1':
        pushLeft(int(command[1]))
    elif command[0] == '2':
        pushRight(int(command[1]))
    elif command[0] == '3':
        print(popLeft())
    elif command[0] == '4':
        print(popRight())
    elif command[0] == '5':
        print(size())
    elif command[0] == '6':
        print(empty())
    elif command[0] == '7':
        print(Left())
    elif command[0] == '8':
        print(Right())
