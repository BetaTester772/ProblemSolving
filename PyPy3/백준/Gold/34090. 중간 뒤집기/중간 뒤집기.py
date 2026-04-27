import sys
from collections import Counter

def solve():
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        return
        
    n = int(data[0])
    a = data[1:]
    
    total_pairs = n * (n - 1) // 2
    
    counts = Counter(a)
    
    same_pairs = 0
    for count in counts.values():
        if count >= 2:
            same_pairs += count * (count - 1) // 2
            
    answer = 1 + total_pairs - same_pairs
    print(answer)

if __name__ == '__main__':
    solve()
