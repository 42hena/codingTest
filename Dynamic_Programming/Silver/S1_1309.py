N = int(input())
dp = [[0]* (N + 1) for _ in range(3)]


dp[0][1] = 1    #<X
dp[1][1] = 1    #X>
dp[2][1] = 1    #XX

# print(dp)
for i in range(2, N + 1):
    dp[0][i] = dp[1][i - 1] + dp[2][i - 1]
    dp[1][i] = dp[0][i - 1] + dp[2][i - 1]
    dp[2][i] = dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]
    dp[0][i]%=9901
    dp[1][i]%=9901
    dp[2][i]%=9901


print((dp[0][N]+dp[1][N]+dp[2][N])%9901)
