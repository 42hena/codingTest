# S5 14916 거스름돈
import sys
input = sys.stdin.readline

# n입력
n = int(input())

# dp 테이블 생성 및 초기화
dp = [100000] * (n + 1)
dp[0] = 0

# 동전 종류
coin = [2, 5]

for i in range(len(coin)):
    for j in range(coin[i], n + 1):
        if dp[j - coin[i]] != 100000:
            dp[j] = min(dp[j - coin[i]] + 1, dp[j])

# 최댓값이 아닌 경우
if dp[n] == 100000:
    print(-1)
else:
    print(dp[n])