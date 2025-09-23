import sys
from collections import deque

stack = deque()


def push(x):
    stack.append(x)


def size():
    return len(stack)


def empty():
    return 1 if len(stack) == 0 else 0


def top():
    return stack[-1] if stack else -1


def pop():
    return stack.pop() if stack else -1


N = int(sys.stdin.readline().strip())

for _ in range(N):
    command = sys.stdin.readline().split()
    if command[0] == '1':
        push(int(command[1]))
    elif command[0] == '2':
        sys.stdout.write(str(pop()) + '\n')
    elif command[0] == '3':
        sys.stdout.write(str(size()) + '\n')
    elif command[0] == '4':
        sys.stdout.write(str(empty()) + '\n')
    elif command[0] == '5':
        sys.stdout.write(str(top()) + '\n')
