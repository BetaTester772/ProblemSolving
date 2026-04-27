from collections import deque
import sys

queue = deque()


def push(X):
    queue.append(X)


def pop():
    if queue:
        temp = queue[0]
        queue.remove(temp)
        return temp
    else:
        return -1


def size():
    return len(queue)


def empty():
    return 0 if queue else 1


def front():
    return queue[0] if queue else -1


def back():
    return queue[-1] if queue else -1


N = int(sys.stdin.readline())

for _ in range(N):
    command = sys.stdin.readline().split()
    if command[0] == 'push':
        push(int(command[1]))
    elif command[0] == 'pop':
        sys.stdout.write(str(pop()) + '\n')
    elif command[0] == 'size':
        sys.stdout.write(str(size()) + '\n')
    elif command[0] == 'empty':
        sys.stdout.write(str(empty()) + '\n')
    elif command[0] == 'front':
        sys.stdout.write(str(front()) + '\n')
    elif command[0] == 'back':
        sys.stdout.write(str(back()) + '\n')
    else:
        raise IOError
