N, M = map(int, input().split())

S = []

A = sorted(list(map(int, input().split())))


def dfs(current):
    if len(S) == M:
        if len(set(S)) != M:
            return
        for s in S:
            print(s, end=' ')
        print()
        return

    for i in range(0, N):
        if i == current:
            continue
        S.append(A[i])
        dfs(i)
        S.pop()


dfs(-1)
