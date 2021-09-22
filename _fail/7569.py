from collections import deque
M, N, H = map(int, input().split())

graph = []
for i in range(H):
    graph.append([])
    for j in range(N):
        graph[i].append(list(map(int, input().split())))

def isborder(nx, ny, nz):
    if nx < 0 or nx > H or ny < 0 or ny > M or nz < 0 or nz > N:
        return True
    return False

def BFS(i, j, k):
    queue = deque([[i, j, k]])
    
    dx = [1, -1, 0, 0, 0, 0]
    dy = [0, 0, 1, -1, 0, 0]
    dz = [0, 0, 0, 0, 1, -1]
    while queue:
        for a in range(6):
            i, j, k = queue.popleft()
            nx = i + dx[a]
            ny = j + dy[a]
            nz = k + dz[a]
            if isborder(nx, ny, nz) or graph[nx][ny][nz] == -1:
                continue





for i in range(H):
    for j in range(N):
        for k in range(M):
            if graph[i][j][k] == 1:
                visited = [[[False]* M for _ in range(N)] for _ in range(H)]
                BFS(i, j, k, visited)




