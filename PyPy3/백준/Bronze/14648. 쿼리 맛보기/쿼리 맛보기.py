n, q = map(int, input().split())
A = list(map(int, input().split()))
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        print(sum(A[query[1] - 1:query[2]]))
        A[query[1] - 1], A[query[2] - 1] = A[query[2] - 1], A[query[1] - 1]
    else:
        print(sum(A[query[1] - 1:query[2]]) - sum(A[query[3] - 1:query[4]]))
