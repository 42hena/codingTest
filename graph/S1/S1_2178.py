import sys
from collections import deque
input = sys.stdin.readline
N, M = map(int,input().split())

graph = []

for _ in range(N):
    graph.append(list(input()))
# print(graph)

queue = deque([[0, 0]])
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def is_border(x, y):
    if x > N - 1 or x < 0 or y > M - 1 or y < 0:
        return True
    return False


while len(queue) > 0:
    
    x, y = queue.popleft() 
    
    if x == N - 1 and y == M - 1:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if is_border(nx,ny):
            continue
        if graph[nx][ny] == '1':
            graph[nx][ny] = int(graph[x][y]) + 1
            queue.append([nx, ny])
print(graph[N-1][M-1])