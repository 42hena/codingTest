#G5 10026
from collections import deque

def bfs(graph, x, y, color):
    queue = deque()
    queue.append((x, y))
    # print(queue)

    while queue:
        x, y = queue.popleft()
        # print(x, y)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if graph[nx][ny] != color:
                continue
            queue.append((nx, ny))
            graph[nx][ny] = 0
N = int(input())

graph_normal = []

for i in range(N):
    graph_normal.append(list(map(str, input())))
# print(graph_normal)
graph_abnormal = [item[:] for item in graph_normal]

#변환
for i in range(N):
    for j in range(N):
        if graph_abnormal[i][j] == 'G':
            graph_abnormal[i][j] = 'R'

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
normal_cnt = 0
abnormal_cnt = 0
for i in range(N):
    for j in range(N):
        if graph_abnormal[i][j] != 0:
            bfs(graph_abnormal, i, j, graph_abnormal[i][j])
            abnormal_cnt += 1
        if graph_normal[i][j] != 0:
            bfs(graph_normal, i, j, graph_normal[i][j])
            normal_cnt += 1

print(normal_cnt, abnormal_cnt)