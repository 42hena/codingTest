# B1 2839 (설탕 배달)

# 시간 제한: 1초
# 메모리 제한: 128MB

# 조건 N은 3 <= N <= 5000

# N 입력
N = int(input())

# dp 생성
INF = 1e9
dp = [INF] * (N + 1)
dp[0] = 0

# dp 계산
for i in range(1, N + 1):
    if i >= 3:
        dp[i] = min(dp[i], dp[i - 3] + 1)
    if i >= 5:
        dp[i] = min(dp[i], dp[i - 5] + 1)

# 불가능한 경우 시 출력
if dp[N] == INF:
    print(-1)
# 가능 시 출력
else:
    print(dp[N])