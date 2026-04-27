N, K = map(int, input().split())

queue = [i for i in range(1, N + 1)]

result = []

while queue:
    for _ in range(K - 1):
        # print(queue)
        queue.append(queue.pop(0))
    result.append(queue.pop(0))

print("<", end="")
for i in range(N - 1):
    print(result[i], end=", ")
print(result[-1], end=">")
