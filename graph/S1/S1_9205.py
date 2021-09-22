from collections import deque

N = int(input())
graph = []

for i in range(N):
    graph.append(list(map(int, input().split())))

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def BFS(i, j, visited):
    queue = deque( [(i,j)] )
    visited[i][j] = 1
    while queue:
        i, j = queue.popleft()

        for direction in range(4):
            nx = i + dx[direction]
            ny = j + dy[direction]
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if not visited[nx][ny] and graph[nx][ny] > height:
                queue.append((nx, ny))
                visited[nx][ny] = 1
            

maxVal = 0

# print("maxnum", maxnum)

for height in range(0, 101):
    safezone = 0
    visited = [[0] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if graph[i][j] > height and not visited[i][j]:
                BFS(i, j, visited)
                safezone += 1    
    if safezone == 0:
        break
    if maxVal < safezone:
        maxVal = safezone
    
print(maxVal)