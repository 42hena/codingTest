import sys
input = sys.stdin.readline

dp = [0] * 21

dp[1] = 1
dp[2] = 2
for i in range(3, 21):
    dp[i] += 1
    for j in range(1, i):
        
        if i - 2**j >= 0:
            dp[i] += dp[i - 2**j]
        else:
            break
print(dp)
for _ in range(int(input())):
    n = int(input())
    print(dp[n])
