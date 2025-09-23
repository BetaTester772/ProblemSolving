board = [list(map(int, list(input()))) for _ in range(9)]
zero = []

for i in range(9):
    for j in range(9):
        if board[i][j] == 0:
            zero.append((i, j))

goal = len(zero)

# print(board)

def dfs(current_zero):
    global board


    if current_zero == goal:

        for i in range(9):
            for j in range(9):
                print(board[i][j], end='')
            print()
        exit()

    for i in range(1, 10):
        if available(i, current_zero):
            board[zero[current_zero][0]][zero[current_zero][1]] = i
            dfs(current_zero + 1)
            board[zero[current_zero][0]][zero[current_zero][1]] = 0


def available(num, current_zero):
    y_0 = zero[current_zero][0]
    x_0 = zero[current_zero][1]

    for i in range(9):
        if board[y_0][i] == num or board[i][x_0] == num:
            return False

    if 0 <= x_0 <= 2:
        sector_x = [0, 1, 2]
    elif 3 <= x_0 <= 5:
        sector_x = [3, 4, 5]
    else:
        sector_x = [6, 7, 8]

    if 0 <= y_0 <= 2:
        sector_y = [0, 1, 2]
    elif 3 <= y_0 <= 5:
        sector_y = [3, 4, 5]
    else:
        sector_y = [6, 7, 8]

    for y in sector_y:
        for x in sector_x:
            if board[y][x] == num:
                return False

    return True


dfs(0)
