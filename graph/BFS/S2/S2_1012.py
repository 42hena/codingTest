import sys
from collections import deque
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for _ in range(int(input())):
    M, N, K = map(int, input().split())

    visited = [[False]*M for _ in range(N)]
    graph = [[0]*M for _ in range(N)]

    # print(M, N, K)
        
    for _ in range(K):
        j, i = map(int, input().split())
        graph[i][j] = 1

    # print("start")
    # for i in range(N):
    #     for j in range(M):
    #         print(graph[i][j], end="")
    #     print()
    # print("end")


    def BFS(graph, i, j, visited):
        visited[i][j] = True

        queue = deque([(i, j)])
        while queue:
            i, j = queue.popleft()
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                if nx < 0 or nx >= N or ny < 0 or ny >= M:
                    continue
                if graph[nx][ny] == 1 and not visited[nx][ny]:
                    queue.append((nx, ny))
                    visited[nx][ny] = True

    cnt = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1 and not visited[i][j]:
                BFS(graph, i, j, visited)
                cnt += 1
    print(cnt)