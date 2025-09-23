max_slice, add, dic = map(int, input().split())

real_len = 0

for _ in range(add + dic):
    s = input()
    if s == '1':
        real_len += 1
    elif s == '0':
        real_len -= 1

    while real_len > max_slice:
        max_slice *= 2

print(max_slice)
