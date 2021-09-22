N = int(input())


graph = list(map(int, input().split()))
graph.insert(0, 0)

# print(graph)
dp = [1000] * (N + 1)
if N == 1:
    dp[1] = 0

if graph[1] != 0:
    dp[1] = 0
for i in range(1, N + 1):
    for j in range(1, graph[i] + 1):
        if i + j <= N:
            dp[i + j] = min(dp[i + j], dp[i] + 1)
    # print(dp)
if dp[N] != 1000:
    print(dp[N])
else:
    print(-1)