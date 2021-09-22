N, M = map(int, input().split())

def DFS(graph, visited, start, cnt):
    visited[start] = True
    cnt += 1
    for i in graph[start]:
        if not visited[i]:
            cnt = DFS(graph, visited, i, cnt)
    # print(cnt)
    return cnt
            
graph = []
cnt = 0
visited = [False] * (N + 1)
for i in range(N+1):
    graph.append([])
for i in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)
# print(graph)

ans = 0
for i in range(1, N + 1):
    cnt = 0
    cnt = DFS(graph, visited, i, cnt)
    ans = max(ans, cnt)

print(ans)