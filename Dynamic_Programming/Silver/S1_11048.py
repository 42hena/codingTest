N, M = map(int, input().split())

graph = []
for i in range(N):
    graph.append(list(map(int, input().split())))

dp = [[0] * (M) for _ in range(N)]

dp[0][0] = graph[0][0]

for i in range(N):
    for j in range(M):
        if i + 1 < N:
            dp[i + 1][j] = max(dp[i + 1][j], graph[i + 1][j] + dp[i][j])
        if j + 1 < M:
            dp[i][j + 1] = max(dp[i][j + 1], graph[i][j + 1] + dp[i][j])
        if i + 1 < N and j + 1 < M:
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], graph[i + 1][j + 1] + dp[i][j])
print(dp[N-1][M-1])
# for i in range(N):
#     for j in range(M):
#         print(dp[i][j],end=" ")
#     print()
