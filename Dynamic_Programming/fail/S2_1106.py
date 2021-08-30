C, N = map(int, input().split())

dp = [101] * (C + 1)
array = []
for _ in range(N):
    array.append(list(map(int, input().split())))

for i in range(1, N + 1):
    for j in range(array[i][1], N + 1):
        if j % array[i][1] == 0:
            dp[j] = min(dp[j], dp[j - array[i][1]])
        if dp[j] != 0:
            dp[j] = min(dp[j], dp[j - array[i][1]])
        

