N = int(input())
valeur = int(input())
boites = list(map(int, input().split()))

sums = {0:1}
count = 0
prefix_sum = 0

for i in range(N):
    prefix_sum = (prefix_sum + boites[i]) % valeur
    if prefix_sum in sums:
        count += sums[prefix_sum]
        sums[prefix_sum] += 1
    else:
        sums[prefix_sum] = 1

print(count % (10**9+7))