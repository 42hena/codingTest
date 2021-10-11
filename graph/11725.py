import sys
from collections import deque
n = int(input())
input = sys.stdin.readline
graph = [[]for _ in range(n + 1)]

def BFS(v, graph, visited):
    visited[v] = -1
    queue = deque([v])
    
    while queue:
        # size = len(queue)
        # for 
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                visited[i] = v
                queue.append(i)


visited = [0] * (n + 1)
for _ in range(n - 1):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

BFS(1, graph, visited)
for i in range(2, n + 1):
    print(visited[i])