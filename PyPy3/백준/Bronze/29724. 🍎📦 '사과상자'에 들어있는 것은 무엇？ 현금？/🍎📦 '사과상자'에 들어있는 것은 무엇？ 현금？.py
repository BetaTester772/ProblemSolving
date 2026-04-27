N = int(input())

apple = 0
apple_box = 0
bae = 0

for _ in range(N):
    T, W, H, L = input().split()
    W, H, L = map(int, [W, H, L])

    if T == 'A':
        W //= 12
        H //= 12
        L //= 12
        apple += W * H * L
        apple_box += 1
    else:
        bae += 1

print(apple_box * 1000 + apple * 500 + bae * 120 * 50)
print(4000 * apple)
