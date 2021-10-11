N = int(input())
K = int(input())

sensors = list(map(int, input().split()))
# print(N)
sensors.sort()

distance = []
for i in range(N - 1):
    distance.append(sensors[i + 1] - sensors[i])
# print(distance)
distance.sort()
# print(distance)
for i in range(K - 1):
    if distance:
        distance.pop()
print(sum(distance))