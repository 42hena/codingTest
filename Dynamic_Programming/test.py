
# n입력
n = int(input())

# dp생성
dp = [0] * (n + 1)

# dp 초기화
dp[0] = 0
if n > 0:
    dp[1] = 1

# dp 계산
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]

# 출력
print(dp[n])