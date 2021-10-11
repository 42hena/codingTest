n, m, r = map(int, input().split())
item = list(map(int, input().split()))
item.insert(0, 0)
INF = int(1e9)
graph = [[INF] * (n + 1) for _ in range(n + 1)]
for i in range(5):
    graph[i + 1][i + 1] = 0

for _ in range(r):
    v1, v2, d = map(int, input().split())
    graph[v1][v2] = d
    graph[v2][v1] = d

# for i in range(1, n + 1):
#     for j in range(1, n + 1):
#         print(graph[i][j], end=" ")
#     print()


for k in range(1, n + 1):
    visited = [False]*(n + 1)
    for a in range(1, n + 1):
        index = -1
        for b in range(1, n + 1):
            if graph[a][b] > graph[a][k] + graph[k][b]:
                graph[a][b] = graph[a][k] + graph[k][b]
                index = k
    # if graph[a][b] <= m:
        
            

# for i in range(1, n + 1):
#     for j in range(1, n + 1):
#         if graph[i][j] == int(INF):
#             print("X")
#         else:
#             print(graph[i][j], end=" ")
#     print()

# n: 지역 개수, m: 수색범위, r: 길의 개수

# for i in range(1, n + 1):
#     for j in range(1, n + 1):
#         print(graph[i][j], end=" ")

Max = 0
for i in range(1, n + 1):
    Sum = item[i]
    for j in range(1, n + 1):
        if graph[i][j] != 0 and graph[i][j] <= m:
            Sum += item[j]
    if Max < Sum:
        Max = Sum
print(Max)