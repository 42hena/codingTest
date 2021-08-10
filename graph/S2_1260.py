from collections import deque


def dfs(graph, V, visited):
    print(V, end=" ")
    visited[V] = True
    for i in graph[V]:
        if visited[i] == False:
            dfs(graph, i, visited)

def bfs(graph, V, visited):
    queue = deque([V])
    visited[V] = True
    while queue:
        v = queue.popleft()
        print(v, end=" ")
        for i in graph[v]:
            if visited[i] == False:
                queue.append(i)
                visited[i] = True


N, M, V = map(int, input().split())
visited = [False for _ in range(N + 1)]
graph = []

for i in range(N + 1):
    graph.append([])

for i in range(M):
    index, v = map(int, input().split())
    graph[index].append(v)
    graph[v].append(index)
    graph[index].sort()
    graph[v].sort()
# print(graph)

dfs(graph, V, visited)
print()
visited = [False for _ in range(N + 1)]
bfs(graph, V, visited)