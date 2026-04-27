S = input()


# S = 'mobitel'


# a = S.index(sorted(S)[0])
#
# i = 1
# b = 0
# while b <= a:
#     b = S.index(sorted(S)[i])
#     i += 1
#
# # print(a, b)
# # print(S[a], S[b])
#
# sub_S = [S[:a + 1], S[a + 1:b + 1], S[b + 1:]]
# for i in range(3):
#     sub_S[i] = sub_S[i][::-1]
#     print(sub_S[i], end='')

def split_and_reverse_string(S, a, b):
    sub_S = [S[:a][::-1], S[a:b][::-1], S[b:][::-1]]
    return ''.join(sub_S)


candidates = []
for i in range(1, len(S)):
    for j in range(i + 1, len(S)):
        # print(S[:i], S[i:j], S[j:])
        candidates.append(split_and_reverse_string(S, i, j))

print(sorted(candidates)[0])
