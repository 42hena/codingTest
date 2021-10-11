import sys
input = sys.stdin.readline
N, K = map(int, input().split())

array = [[0, 0]]
for _ in range(N):
    array.append(list(map(int, input().split())))

dp = [[0] * (K + 1) for _ in range(N + 1)]

dp1 = [[0] * (K + 1) for _ in range(N + 1)]
for i in range(1, N + 1):
    for j in range(1, K + 1):
        if j < array[i][0]:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j - array[i][0]] + array[i][1],dp[i - 1][j])

for i in range(N + 1):
    for j in range(K + 1):
        print(dp[i][j], end=" ")
    print()

print()
for i in range(1, N + 1):
    for j in range(array[i][0], K + 1):
        dp1[i][j] = max(dp1[i - 1][j - array[i][0]] + array[i][1],dp1[i - 1][j])

for i in range(N + 1):
    for j in range(K + 1):
        print(dp1[i][j], end=" ")
    print()
# print(dp)
