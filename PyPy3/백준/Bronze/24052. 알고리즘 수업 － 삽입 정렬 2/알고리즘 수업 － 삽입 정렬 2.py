def insertion_sort():
    global A
    global t
    for i in range(1, N):
        newItem = A[i]
        loc = i - 1
        while 0 <= loc and newItem < A[loc]:
            A[loc + 1] = A[loc]
            # print(*A)
            t += 1
            if t == K:
                print(*A)
                return
            loc -= 1
        if loc + 1 != i:
            A[loc + 1] = newItem
            # print(*A)
            t += 1
            if t == K:
                print(*A)
                return


N, K = map(int, input().split())
A = list(map(int, input().split()))
t = 0

insertion_sort()

if t < K:
    print(-1)
