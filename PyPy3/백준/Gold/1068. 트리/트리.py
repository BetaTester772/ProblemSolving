N = int(input())
A = list(map(int, input().split()))

child = [[] for _ in range(N)]
start = None

for i in range(N):
    if A[i] == -1:
        start = i
    else:
        child[A[i]].append(i)

# print(child)

stop = int(input())

result = 0

def dfs(R):
    # print(R)
    global result
    if R == stop:
        # if len(child[R]) == 0:
        #     result += 1
        return 1
    elif len(child[R]) == 0:
        result += 1
        # print("leaf")
        return 0

    for v in child[R]:
        if dfs(v) and len(child[R]) == 1:
            result += 1

dfs(start)

print(result)
