longueur = int(input())
tunnel = list(map(int, input().split()))

R = float("inf")
E = 0
current = (tunnel[0],1)

for i in range(1,longueur + 1):
    if i < longueur and tunnel[i] == current[0]:
        current = (current[0],current[1]+1)
    else:
        if current[0] == 0 and current[1] < R:
            R = current[1]
        elif current[0] == 1 and current[1] > E:
            E = current[1]
        if i < longueur:
            current = (tunnel[i],1)

print(R-E)