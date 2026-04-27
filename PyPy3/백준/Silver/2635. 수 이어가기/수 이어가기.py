stack_raw = [int(input())]

result = []
for i in range(1, stack_raw[0] + 1):
    stack = stack_raw.copy()
    stack.append(i)
    while stack[-2] - stack[-1] >= 0:
        stack.append(stack[-2] - stack[-1])
    if len(result) < len(stack):
        result = stack.copy()

print(len(result))
print(*result)
