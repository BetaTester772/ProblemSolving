def available(x, y):
    for q in queen:
        if q[0] == x or q[1] == y or abs(x - q[0]) == abs(y - q[1]):
            return False
    return True


def dfs(y):
    global num
    # print(y)
    if y == N:
        num += 1
        return

    for x in range(0, N):
        if available(x, y):
            queen.append((x, y))
            dfs(y + 1)
            queen.pop()


N = int(input())
queen = []
num = 0

dfs(0)

print(num)
