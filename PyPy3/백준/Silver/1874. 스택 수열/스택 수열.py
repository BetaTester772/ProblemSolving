from collections import deque

n = int(input())

answer = []
for _ in range(n):
    answer.append(int(input()))

stack = deque()

result = []

pointer = 0

while list(stack) != answer:
    for i in range(1, n + 1):
        stack.append(i)
        result.append('+')
        # print(stack)
        while stack and answer[pointer] == stack[-1]:
            result.append('-')
            stack.pop()
            pointer += 1
            # print(stack)
        if pointer >= n and len(stack) == 0:
            print('\n'.join(map(str, result)))
            exit()
        else:
            if i == n:
                print('NO')
                exit()
                # print(answer[pointer+1:])

        # if list(reversed(answer[pointer:])) == stack:
        #     for _ in range(len(stack)):
        #         answer.append('-')
        #     break
        # print(stack, result)

print(result)
