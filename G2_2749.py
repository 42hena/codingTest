#G2_2749 피보치나 수 3
import time

n = int(input())
start = time.time()
dp = [0 for _ in range(1500001)]
dp[1] = 1
for i in range(2, 1500001):
    dp[i] = (dp[i - 1] + dp[i - 2])% 1000000
print(dp[n % 1500000])