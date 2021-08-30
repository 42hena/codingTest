# B1 9625 (BABBA)

# 시간 제한: 1초
# 메모리 제한: 128MB

# 조건 K은 1 <= N <= 45

# K 입력
K = int(input())

# dp생성
dp = [[0] * (K + 1) for _ in range(2)]

# dp 초기화
dp[0][0] = 1

# dp 계산
for i in range(1, K + 1):
    dp[0][i] += dp[1][i - 1]
    dp[1][i] += dp[0][i - 1] + dp[1][i - 1]

# A와 B 갯수 출력 
print(dp[0][K], dp[1][K])

# comment
# A -> B
# B -> BA