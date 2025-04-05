import heapq

N = int(input())
K = int(input())
barres = list(map(int, input().split()))

barres.sort()
diff = [barres[i+1]-barres[i] for i in range(N-1)]

queue = [(diff[i],i) for i in range(N-1)]
heapq.heapify(queue)

neighbours = {i:(i-1,i+1) for i in range(1,N-2)}
if N == 2:
    neighbours[0] = (None, None)
else:
    neighbours[0] = (None, 1)
    neighbours[N-2] = (N-3, None)

to_delete = [False for _ in range(N-1)]

s = 0

for _ in range(K):
    (d,i) = heapq.heappop(queue)
    while to_delete[i]:
        (d,i) = heapq.heappop(queue)
    s += d
    (pre,next) = neighbours[i]
    if pre is None and next is None:
        pass
    elif pre is None and not(next is None):
        to_delete[next] = True
        next = neighbours[next][1]
        neighbours[i] = (None,next)
        if not(next is None):
            neighbours[next] = (None,neighbours[next][1])
    elif not(pre is None) and next is None:
        to_delete[pre] = True
        pre = neighbours[pre][0]
        neighbours[i] = (pre,None)
        if not(pre is None):
            neighbours[pre] = (neighbours[pre][0],None)
    else:
        d = diff[pre] + diff[next] - d
        diff[i] = d
        to_delete[pre] = True
        to_delete[next] = True
        pre,next = neighbours[pre][0],neighbours[next][1]
        neighbours[i] = (pre,next)
        if not(pre is None):
            neighbours[pre] = (neighbours[pre][0],i)
        if not(next is None):
            neighbours[next] = (i,neighbours[next][1])
        heapq.heappush(queue,(d,i))

print(s)
    
