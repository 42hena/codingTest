from collections import deque
n, m = map(int, input().split())

Map = []
visited = [[False] * m for _ in range(n)]
for _ in range(n):
    Map.append(list(map(int, input().split())))

cnt = 0
S = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
def BFS(x, y, count):
    global S
    queue = deque([[x, y]])
    visited[x][y] = True
    while queue:
        x, y = queue.popleft()
        # print("test", x, y)
        count+=1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if not visited[nx][ny] and Map[nx][ny]==1:
                visited[nx][ny] = True
                queue.append([nx,ny])
                
    # print(count)
    if S < count:
        S = count


for i in range(n):
    for j in range(m):
        if not visited[i][j] and Map[i][j]:
            BFS(i, j, 0)
            cnt+=1

print(cnt)
print(S)
