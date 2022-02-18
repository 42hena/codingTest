import sys
input = sys.stdin.readline
INF = int(1e9)
graph = [[INF] * 1000 for _ in range(1000)]

n, m, t = map(int, input().split())

for i in range(n):
    graph[i][i] = 0


for i in range(m):
    v1, v2, w = map(int, input().split())
    graph[v1-1][v2-1] = w
    

for k in range(n):
    for i in range(n):
        for j in range(n):
            if graph[i][k] + graph[k][j] < graph[i][j]:
                graph[i][j] = graph[i][k] + graph[k][j]

maxV = 0
for i in range(n):
    maxV = max(graph[i][t-1] + graph[t-1][i], maxV)
print(maxV)