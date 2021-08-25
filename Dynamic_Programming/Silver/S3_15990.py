import sys

input= sys.stdin.readline

dp = [[0] * (100001) for _ in range(4)]
dp[1][1] = 1
dp[2][2] = 1
dp[1][3] = 1
dp[2][3] = 1
dp[3][3] = 1

for i in range(4, 100001):
    dp[1][i] = (dp[2][i - 1] + dp[3][i - 1]) % 1000000009
    dp[2][i] = (dp[1][i - 2] + dp[3][i - 2]) % 1000000009
    dp[3][i] = (dp[1][i - 3] + dp[2][i - 3]) % 1000000009
for _ in range(int(input())):
    n = int(input())
    print( (dp[1][n] + dp[2][n] + dp[3][n]) % 1000000009 )
# print(dp)
# for i in range(4):
#     for j in range(n+1):
#         print(dp[i][j], end=" ")
#     print()

#     # dp[i][1] += dp[i - 1][2] + dp[i - 1][3]
#     # dp[i][2] += dp[i - 2][1] + dp[i - 2][3]
#     # dp[i][3] += dp[i - 3][1] + dp[i - 3][2]
