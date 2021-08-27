import sys
input = sys.stdin.readline
N, M = map(int, input().split())

graph = [[0]* N]

for i in range(N):
    graph.append(list(map(int, input().split())))
# print(graph)

for i in range(2, N + 1):
    for j in range(N):
        graph[i][j] += graph[i - 1][j]
# print(graph)

command = []
for _ in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    ans = 0
    for i in range(y1 -1, y2):
        ans += graph[x2][i] - graph[x1 -1][i]
    print(ans)