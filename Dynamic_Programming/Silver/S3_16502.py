N = int(input())
M = int(input())
dp = [[0]*4 for _ in range(4)]

for m in range(M):
    i, j, val = map(str, input().split())
    dp[ord(i) - ord('A')][ord(j) - ord('A')] = float(val)
    # print(dp)

rate = [0.25, 0.25, 0.25, 0.25]
for n in range(N):

    sum_rate = [0] * 4
    for i in range(4):
        for j in range(4):
            sum_rate[j] += rate[i] * dp[i][j]
    rate = sum_rate[:]

for i in range(4):
    print(rate[i]*100)
