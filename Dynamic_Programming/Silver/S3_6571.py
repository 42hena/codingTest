dp = [0] * 501
dp[0] = 1
dp[1] = 1
for i in range(2, 501):
    dp[i] = dp[i - 1] + dp[i - 2]
# print(dp)
while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    cnt = 0 
    for i in range(1, 501):
        if dp[i] > b:
            break
        if dp[i] >= a and dp[i] <= b:
            cnt += 1
    print(cnt)