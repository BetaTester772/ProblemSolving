from collections import deque

T = int(input())


def solve():
    N, M = map(int, input().split())
    queue = deque(map(int, input().split()))
    Max = max(queue)

    out = 0

    while queue:
        if queue[0] == Max:
            queue.popleft()
            if len(queue) > 0:
                Max = max(queue)
            out += 1
            N -= 1

            if M == 0:
                print(out)
                break

            M -= 1
            if M == -1:
                M = N - 1
        else:

            M -= 1
            if M == -1:
                M = N - 1
            queue.append(queue.popleft())
        # print(queue, M, out)


for i in range(T):
    # print("T:", i)
    solve()
