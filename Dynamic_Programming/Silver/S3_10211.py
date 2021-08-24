for _ in range(int(input())):
    N = int(input())
    dp = list(map(int, input().split()))
    # dp = [-1001]*N

    # dp[0] = array[0]
    for i in range(1, N):
        dp[i] = max(dp[i],dp[i] + dp[i-1]) 
    print(max(dp))