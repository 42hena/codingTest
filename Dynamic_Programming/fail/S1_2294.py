n, k = map(int, input().split())

coin = []
for _ in range(n):
    coin.append(int(input()))
print(coin)

dp = [10001] * (k + 1)
dp[0] = 0
for i in range(n):
    for j in range(coin[i], k + 1):
        
        dp[j] = min(dp[j], dp[j - coin[i]] + 1)

print(dp)