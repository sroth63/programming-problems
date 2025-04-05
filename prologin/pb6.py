import collections
MOD = 10**9+7

# Entrées
N = int(input())
M = int(input())
K = int(input())
scores = list(map(int, input().split()))
graphe = [[] for _ in range(N)]
for _ in range(M):
    A, B = map(int, input().split())
    graphe[A-1].append(B-1)
    graphe[B-1].append(A-1)

# BFS
dist_sorted = [(0,0)] # liste des (distance à 0, numéro du sommet) triés par distance
dist = [float("inf") for _ in range(N)] # liste des distances à zéro
dist[0] = 0
file = collections.deque()
file.append(0)
new_dist = 0
while file and new_dist <= K:
    s = file.popleft()
    for t in graphe[s]:
        if dist[t] == float("inf"):
            file.append(t)
            new_dist = dist[s] + 1
            dist[t] = new_dist
            dist_sorted.append((new_dist,t))

prefix = [scores[0]] #prefix[i] = somme des scores des i+1 éléments les plus proches de 0
i = 1
while i < len(dist_sorted) and dist_sorted[i][0] <= K: #TODO
    prefix.append((prefix[-1]+scores[dist_sorted[i][1]])%MOD)
    i += 1
dist_sorted = dist_sorted[:i]

def binary_search(t,b):
    '''renvoie l'indice du dernier élément du tableau t inférieur ou égal à b, à condition qu'il y en ait un et que t soit trié'''
    l, h = 0, len(t)
    while l < h:
        mid = l + (h-l)//2
        if t[mid][0] <= b:
            l = mid+1
        else:
            h = mid
    return l-1

sum = 0
i = 0
while i < len(dist_sorted) and dist_sorted[i][0] <= K:
    d = dist_sorted[i][0]
    j = binary_search(dist_sorted,K-d)
    sum = (sum + scores[dist_sorted[i][1]]*prefix[j]) % MOD
    i += 1
print(sum)