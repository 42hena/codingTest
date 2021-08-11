


N = int(input())

def mapping(graph,visited, x, y, cnt):
    # print(x, y)
    visited[x][y] = 1
    cnt += 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= N:
            continue
        if visited[nx][ny] == 1:
            continue
        if graph[nx][ny] == 0:
            continue
        cnt = mapping(graph,visited, nx, ny, cnt)
    return cnt



graph = []
visited = [[0]*N for _ in range(N)]

for i in range(N):
    graph.append(list(map(int, input())))

# print(graph)

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

arr = []
home = 0
for i in range(N):
    for j in range(N):
        if graph[i][j] == 1 and visited[i][j] == 0:
            cnt = 0
            cnt = mapping(graph,visited, i, j, cnt)
            arr.append(cnt)
            home += 1
print(home)
arr.sort()
for i in range(len(arr)):
    print(arr[i])
