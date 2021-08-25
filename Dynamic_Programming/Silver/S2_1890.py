N = int(input())
graph = []

for i in range(N):
    graph.append(list(map(int, input().split())))
# print(graph)
dp = [[0]*N for _ in range(N)]
dp[0][0] = 1
for i in range(N):
    for j in range(N):
        if dp[i][j] == 0:
            continue
        if i == N - 1 and j == N - 1:
            break
        val = graph[i][j]
        if i + val < N:
            dp[i + val][j] += dp[i][j]
        if j + val < N:
            dp[i][j + val] += dp[i][j]

print(dp[N-1][N-1])
# for k in range(N):
#     for l in range(N):
#         print(dp[k][l], end="")
#     print()    
# print()
# print()