S = input()
bomb = list(input())
stack = []

for i in S:
    stack.append(i)
    if i == bomb[-1] and stack[-len(bomb):] == bomb:
        for _ in range(len(bomb)):
            stack.pop()

print(''.join(stack) if len(stack) else 'FRULA')
