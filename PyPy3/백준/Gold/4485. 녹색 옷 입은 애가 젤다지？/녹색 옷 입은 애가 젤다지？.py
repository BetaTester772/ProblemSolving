import heapq
inf = float('inf')
it=1
while True:
    N = int(input())
    if N == 0:
        break
    E = [[] for _ in range(N*N)]
    V = []
    distance = [inf]*(N*N)
    for i in range(N):
        A = list(map(int, input().split()))
        for j in range(N):
            V.append(A[j])
            if j != 0:
                E[i*N+j].append(i*N+(j-1))
            if j < N-1:
                E[i*N+j].append(i*N+(j+1))
            if i!=0:
                E[i*N+j].append((i-1)*N+j)
            if i< N-1:
                E[i*N+j].append((i+1)*N+j)
    # print(E)
    # print(V)
    heap = [(V[0], 0)]
    distance[0] = V[0]
    while heap:
        w,r = heapq.heappop(heap)
        
        if w > distance[r]:
            continue

        for c in E[r]:
            if w+V[c] < distance[c]:
                distance[c] = w+V[c]
                heapq.heappush(heap, (w+V[c], c))
    
    print(f"Problem {it}:", distance[N**2-1])
    it+=1
