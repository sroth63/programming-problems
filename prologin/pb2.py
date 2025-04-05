N = int(input())
M = int(input())

d = {}

for _ in range(N):
    line = input()
    if line in d:
        d[line] +=1
    else:
        d[line] = 1
couples = 0

for line in d:
    couples += d[line] // 2

print(N - 2 * couples)