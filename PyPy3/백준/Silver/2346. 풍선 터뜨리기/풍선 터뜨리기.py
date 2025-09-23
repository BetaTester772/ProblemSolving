from collections import deque
N = int(input())
numbers = list(map(int, input().split()))
deq = deque([i for i in range(1, N + 1)])
a = deq.popleft()
print(a, end=" ")
while deq:
    if numbers[a - 1] > 0:
        for _ in range(abs(numbers[a - 1]) - 1):
            deq.append(deq.popleft())
    else:
        for _ in range(abs(numbers[a - 1])):
            deq.appendleft(deq.pop())
    a = deq.popleft()
    print(a, end=" ")
