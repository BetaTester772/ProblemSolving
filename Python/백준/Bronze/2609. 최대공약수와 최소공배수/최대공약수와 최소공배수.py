def Euclidean(a, b):
    r = b % a
    if r == 0:
        return a
    return Euclidean(r, a)
a,b=map(int,input().split())
gcd=Euclidean(a,b)
print(gcd)
print(a*b//gcd)
