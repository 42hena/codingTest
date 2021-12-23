import sys
input = sys.stdin.readline
S = input().rstrip()
n = int(input())
stringSet = []
for i in range(n):
    Str, point = input().split()
    stringSet.append([Str, int(point)])

# print(stringSet)
dp = [0] * 1001
dp[0] = 0
# print(len(stringSet))
stringSize = len(S)
setSize = len(stringSet)
for i in range( stringSize ):
    for j in range(setSize):
        dp[i + 1] = max(dp[i + 1], dp[i] + 1)
        size = len(stringSet[j][0])
        if (size - 1 <= i):
            if (stringSet[j][0] ==  S[i - size + 1:i + 1]):    
                dp[i + 1] = max(dp[i + 1], dp[i - size + 1] + stringSet[j][1])
        
print(dp[len(S)])