N, M = map(int, input().split())

nlist = []

for i in range(M):
    nlist.append(0)

for _ in range(N):
    nums = list(map(int, input().split()))
    for i in range(M):
        nlist[i] += nums[i]

A = int(input())

alist = []

for i in range(M - A + 1):
    alist.append(sum(nlist[i:i + A]))

print(max(alist))
