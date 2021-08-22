
H, W = map(int, input().split())

dp = []
for i in range(H):
    dp.append([])
    for j in list(input()):
        if j == 'c':
            dp[i].append(0)
        else:
            dp[i].append(-1)


# 한번에 출력하기
for i in range(H):
    print(dp[i][0], end=" ")
    for j in range(1, W):
        if dp[i][j - 1] != -1 and dp[i][j] != 0:
            dp[i][j] = dp[i][j - 1] + 1
        print(dp[i][j], end=" ")
    print()