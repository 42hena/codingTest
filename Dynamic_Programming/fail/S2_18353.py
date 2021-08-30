N = int(input())
dp = [0] * (N + 1)

dp[1] = 0
array = list(map(int, input().split()))
array.insert(0, 0)
# print(array)
for i in range(1, N):
    if array[i] <= array[i + 1]:
        dp[i + 1] = dp[i] + 1
    else:
        dp[i + 1] = dp[i]
print(dp[N])


