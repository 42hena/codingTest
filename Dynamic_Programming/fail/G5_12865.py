N, K = map(int, input().split())

info = []
for i in range(N):
    info.append(list(map(int, input().split())))

dp = [0] * (K + 1)

for i in range(4):
    for j in range(info[i][0], K + 1):
        dp[j] = max(dp[j], dp[j - info[i][0]] + info[i][1])
    print(dp)
print(max(dp))