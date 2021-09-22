N = int(input())

dp = [0] * (abs(N) + 1)

if abs(N)>0:
    dp[1] = 1
for i in range(2, abs(N) +1):
    dp[i] = dp[i - 1] + dp[i - 2]
    dp[i] %= 1000000000

if N < 0:
    if N % 2 == 0:
        print(-1)
    else:
        print(1)
elif N > 0:
    print(1)
else:
    print(0)
print(dp[abs(N)])