
N = int(input())
val = int(input())

graph = [[0]*N for _ in range(7)]

cnt = 1
i = N//2
j = N//2
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
lcnt = 0
while True:
    graph[i][j] = cnt
    cnt += 1
    print(graph)
    
    if graph[i][j] == val:
        location = (i, j)
    if i >= N or i < 0 or j >= N or j < 0:
        break