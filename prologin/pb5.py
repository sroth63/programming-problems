N = int(input())
occ_pre = {}
for _ in range(N):
    pre = input()
    occ_pre[pre] = occ_pre.get(pre, 0) + 1
occ_pre = list(occ_pre.values())
occ_post = {}
for _ in range(N):
    post = input()
    occ_post[post] = occ_post.get(post, 0) + 1
occ_post = list(occ_post.values())

occ = [pre*post for pre in occ_pre for post in occ_post]
occ.sort(reverse=True)

best = sum(occ[1:]) #on supprime tout sauf le plus grand élément
new = best

for n in range(1,len(occ)): #on supprime tout sauf les n+1 plus grand éléments, qu'on transforme en leur médiane
    new = new + occ[n//2] - 2*occ[n]
    if new < best:
        best = new

print(best)