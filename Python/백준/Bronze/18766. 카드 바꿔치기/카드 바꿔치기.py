T = int(input())
for _ in range(T):
    n = int(input())
    A = input().split()
    B = input().split()
    if sorted(A) == sorted(B):
        print("NOT CHEATER")
    else:
        print("CHEATER")
