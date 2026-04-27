T = int(input())
for _ in range(T):
    A, B = map(int, input().split())
    
    def fac(n):
        a = 1
        while n > 0:
            a *= n
            n -= 1
        return a
    
    print(fac(B) // fac(B - A) // fac(A))