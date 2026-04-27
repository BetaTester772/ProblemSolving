N = int(input())
A = []

for _ in range(N):
    A.append(input())

rst = 0


def solve(idx: int):
    global rst
    dic = {}
    i = idx
    while i < N and A[i] != "ENTER":
        dic[A[i]] = True
        i += 1
    rst += len(dic.keys())
    return i


for i in range(N):
    if A[i] == "ENTER":
        i = solve(i + 1)

print(rst)
