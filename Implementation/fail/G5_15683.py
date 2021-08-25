N, M = map(int, input().split())

graph = []

for i in range(N):
    graph.append(list(map(int, input().split())))

print(graph)

def func1(graph, i, j):
    while True:
        j += 1
        if graph[i][j] == 6:
            return
        if j >= M:
            return 
        graph[i][j] = '#'

def func2(graph, i, j):
    while True:
        j -= 1
        if graph[i][j] == 6:
            return
        if j < 0:
            return 
        graph[i][j] = '#'

for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            func1(graph, i, j)

for i in range(N):
    for j in range(M):
        print(graph[i][j], end=" ")
    print()
        # if graph[i][j] == 2:

        # if graph[i][j] == 3:

        # if graph[i][j] == 4:

        # if graph[i][j] == 5: