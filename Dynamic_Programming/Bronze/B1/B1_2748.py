# B1 2748 (피보나치 수 2)

# 시간 제한: 1초
# 메모리 제한: 128MB

# 조건 n은 90보다 작거나 같은 자연수

# n 입력
n = int(input())

# dp 생성
dp = [0] * (n + 1)

# dp 초기화
dp[1] = 1

# dp 계산
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]

# dp 출력
print(dp[n])