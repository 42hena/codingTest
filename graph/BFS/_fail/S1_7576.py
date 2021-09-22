from collections import deque
import sys
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

input = sys.stdin.readline

M, N = map(int, input().split())
Map = []
for _ in range(N):
    Map.append(list(map(int, input().split())))

# for i in range(N):
#     for j in range(M):
#         if Map[i][j] == 0:
#             Map[i][j] = int(1e9)

# 함수
def BFS(Map, i, j, visited):
    cnt = 1
    queue = deque( [(i,j)] )
    visited[i][j] = True

    while queue:
        cnt += 1
        for _ in range(len(queue)):
            i, j = queue.popleft()
            
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                if nx < 0  or nx >= N or ny < 0 or ny >= M:
                    continue
                
                if Map[nx][ny] != -1 and not visited[nx][ny]:
                    if Map[nx][ny] == 0:
                        Map[nx][ny] = cnt
                    else:
                        Map[nx][ny] = min(cnt, Map[nx][ny])
                    visited[nx][ny] = True
                    queue.append( (nx, ny) )
                else:
                    visited[nx][ny] = True

    print(Map)
    if visited == [[True]*M for _ in range(N)]:
        return cnt - 1
    return -1
ans = int(1e9)
for i in range(N):
    for j in range(M):
        if Map[i][j] == 1:
            visited = [[False]*M for _ in range(N)]
            cnt = BFS(Map, i,j, visited)
            # print(cnt)
            ans = min(cnt, ans)
if ans == int(1e9):
    print(0)
else:
    print(ans)