import sys
sys.setrecursionlimit(10**6)
n, m = map(int, input().split())

Map = []
visited = [[False] * m for _ in range(n)]
for _ in range(n):
    Map.append(list(map(int, input().split())))

cnt = 0
S = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
def DFS(x, y):
    global S
    S += 1
    visited[x][y] = True
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue
        if not visited[nx][ny] and Map[nx][ny]:
            DFS(nx, ny)
            # visited[nx][ny] = False
    
            
Max = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j] and Map[i][j]:
            # visited[i][j] = True
            S = 0
            DFS(i, j)
            Max = max(Max, S)
            cnt+=1

print(cnt)
print(Max)
