N, K = map(int, input().split())

chess = {}
artifacts = []

result = 0

for _ in range(K):
    X, Y = map(int, input().split())
    X -= 1
    Y -= 1
    chess[(X, Y)] = True
    artifacts.append((X, Y))

# print(chess)
moves = [(2, 0), (-2, 0), (0, 2), (0, -2)]

for X, Y in artifacts:
    for a, b in moves:
        new_X, new_Y = X + a, Y + b
        if 0 <= new_X < N and 0 <= new_Y < N and (new_X, new_Y) not in chess:
            result += 1
            chess[(new_X, new_Y)] = True

print(result)
# print(chess)
