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

print("chick", chicks)
print("house:",houses)
for house in houses:        
   

    min_val = 101
    sum = 0
    print(house[0], house[1])
    for chick in chicks:    

        d = abs(house[0] - chick[0]) + abs(house[1] - chick[1])
        print(d, end=" ")
        sum += d
    print("sum=",sum, end="")
    print()