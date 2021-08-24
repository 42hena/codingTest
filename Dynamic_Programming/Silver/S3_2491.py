N = int(input())
array = list(map(int, input().split()))
dp = [[1] * N for _ in range(2)]

for i in range(1, N):
    if array[i - 1] <= array[i]:
        dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1)
    if array[i - 1] >= array[i]:
        dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1)

print(max(max(dp[0]), max(dp[1])))


# for i in range(1, N):
#     for j in range(i):
#         if array[j] <= array[j + 1]:
#             dp[0][j + 1] = max(dp[0][j + 1], dp[0][j] + 1)
#         if array[j] >= array[j + 1]:
#             dp[1][j + 1] = max(dp[1][j + 1], dp[1][j] + 1)
# print(max(dp))