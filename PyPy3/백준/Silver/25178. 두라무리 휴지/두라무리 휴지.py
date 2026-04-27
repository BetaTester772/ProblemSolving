N = int(input())

A = input()
B = input()

a = 0
b = 0

A_d = dict()
B_d = dict()

if A[0] != B[0] or A[-1] != B[-1]:
    print("NO")
    exit()
bypass_a, bypass_b = False, False

while True:
    if not bypass_b and B[b] in ('a', 'e', 'i', 'o', 'u'):
        if A[a] in ('a', 'e', 'i', 'o', 'u'):
            if bypass_a:
                pass
            elif A[a] in A_d:
                A_d[A[a]] += 1
            else:
                A_d[A[a]] = 1
            a += 1

        if bypass_b:
            pass
        elif B[b] in B_d:
            B_d[B[b]] += 1
        else:
            B_d[B[b]] = 1
        b += 1
    elif not bypass_a and A[a] in ('a', 'e', 'i', 'o', 'u'):
        if bypass_a:
            pass
        elif A[a] in A_d:
            A_d[A[a]] += 1
        else:
            A_d[A[a]] = 1
        a += 1
    else:
        if A[a] != B[b]:
            print("NO")
            exit()

        if bypass_a:
            pass
        elif A[a] in A_d:
            A_d[A[a]] += 1
        else:
            A_d[A[a]] = 1
        a += 1

        if bypass_b:
            pass
        elif B[b] in B_d:
            B_d[B[b]] += 1
        else:
            B_d[B[b]] = 1
        b += 1

    if a == N:
        bypass_a = True

    if b == N:
        bypass_b = True

    if bypass_a and bypass_b:
        break

    if bypass_a:
        a = N - 1

    if bypass_b:
        b = N - 1

    # print(A_d, B_d)

if A_d != B_d:
    print("NO")
    exit()

print("YES")
