N = int(input())
message = input()

last_number = 0
new = ""

for i in range(N):
    if not(message[i] in [str(j) for j in range(10)] and int(message[i]) < last_number):
        new = new + message[i]
    if message[i] in [str(j) for j in range(10)]:
        last_number = int(message[i])

print(new)