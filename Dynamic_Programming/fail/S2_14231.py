N = int(input())
array = list(map(int, input().split()))
dp = [1] * N

dp[0] = 1

for i in range(1, N):    
    for j in range(i):
        if array[j] < array[i]:
            dp[i] = max(dp[i], dp[i - 1] + 1)
print(dp)
