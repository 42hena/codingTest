#내 코드
alpha = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]
str1 = input()
str2 = input()
n = len(str1)
tmp=""
dp = [[0] * (2 * n) for _ in range(2 * n - 1)]
for i in range(n):
    tmp += str1[i] + str2[i]
for i in range(2 * n):
    dp[0][i] = alpha[ord(tmp[i]) - ord('A')]
# print(dp)
for i in range(1, 2*n - 1):
    for j in range(2*n - i):
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % 10


print(dp[2*n - 2][0], end="")
print(dp[2*n - 2][1])