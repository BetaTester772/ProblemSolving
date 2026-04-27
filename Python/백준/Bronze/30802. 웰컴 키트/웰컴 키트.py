N = int(input())
t_shirt = list(map(int, input().split()))
T, P = map(int, input().split())

result_t_shirt = 0
for t in t_shirt:
    if t % T == 0:
        result_t_shirt += t // T
    else:
        result_t_shirt += 1 + t // T

print(result_t_shirt)
print(N // P, N % P)
