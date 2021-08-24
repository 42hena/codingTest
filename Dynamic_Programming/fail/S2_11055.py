N = int(input())
array = list(map(int, input().split()))
dp = [0]*N
dp[0] = array[0]
for i in range(1, N):
    for j in range(i):
        if array[i]>array[j]:
            dp[i] = max(dp[i], array[i] + dp[j])    
print(max(dp))