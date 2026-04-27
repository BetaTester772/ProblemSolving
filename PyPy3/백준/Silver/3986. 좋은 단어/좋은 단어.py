# from collections import deque

N = int(input())
result = 0
for _ in range(N):
    stack = []
    S = input()

    for s in S:
        if len(stack) == 0:
            stack.append(s)
        else:
            if stack[-1] == s:
                stack.pop(-1)
            else:
                stack.append(s)
    if len(stack) == 0:
        result += 1

print(result)
