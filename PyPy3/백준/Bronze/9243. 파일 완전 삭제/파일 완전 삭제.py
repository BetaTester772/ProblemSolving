N = int(input())
A = input()
B = input()


def inverse_zero_one(A):
    B = ""
    for a in A:
        if a == '1':
            B += "0"
        else:
            B += "1"
    return B


if N % 2 == 1:
    if B == inverse_zero_one(A):
        print("Deletion succeeded")
    else:
        print("Deletion failed")
else:
    if B == A:
        print("Deletion succeeded")
    else:
        print("Deletion failed")
