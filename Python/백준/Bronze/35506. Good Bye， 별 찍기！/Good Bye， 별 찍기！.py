n = int(input())

for r in range(2*n):
    s = [' '] * (4*n + 2)
    s[2*n-1-r] = '*'
    
    if r < n:
        s[3*n-r] = '*'
        s[3*n+2+r] = '*'
    else:
        s[r+n+1] = '*'
        s[5*n+1-r] = '*'
    
    print(''.join(s))