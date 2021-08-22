N, M = map(int, input().split())
graph = []
for row in range(N):
    graph.append(list(map(int, input().split())))
# print(graph)

houses = []
chicks = []
for row in range(N):
    for col in range(N):
        if graph[row][col] == 1:
            houses.append((row + 1, col + 1))
        elif graph[row][col] == 2:
            chicks.append((row + 1, col + 1))

for chick in chicks:
    min_val = 101
    sum = 0
    for house in houses:    
        d = abs(house[0] - chick[0]) + abs(house[1] - chick[1])
        # if d < min_val:
        #     min_val = d
        print(d, end=" ")
    
        sum += d
    # print(min_val, end=" ")
    print("sum=",sum, end="")
    print()

# print(houses, chicks)
