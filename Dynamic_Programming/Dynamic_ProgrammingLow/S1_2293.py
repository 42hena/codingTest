n, k = map(int, input().split())

dp = [0] * (k + 1)
coin = [0]
for i in range(n):
    coin.append(int(input()))
# print(coin)

for i in range(1, n + 1):
    for j in range(coin[i], k + 1):
        # print("coin", coin[i])
        if i == 1 and j % coin[i] == 0:
            dp[j] = 1
        else:
            if j == coin[i]:
                dp[j] = dp[j] + 1
            else:
                dp[j] = dp[j - coin[i]] + dp[j]
print(dp[k])







# 메모리 초과 
# dp = [[0] * (k + 1) for _ in range(n + 1)]
# array = []
# for i in range(n):
#     array.append(int(input()))

# # print(n + 1, k + 1)
# for i in range(1, n + 1):
#     for j in range(1, k + 1):
#         # print(array[i - 1])
#         if j < array[i - 1]:
#             dp[i][j] = dp[i - 1][j]
#         elif j == array[i - 1]:
#             dp[i][j] = dp[i - 1][j] + 1
#         else:
#             dp[i][j] = dp[i - 1][j] + dp[i][j - array[i - 1]]

# print(dp[n][k])