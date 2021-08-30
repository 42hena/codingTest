# B2 10870 (피보나치 수 5)

# 시간 제한: 1초
# 메모리 제한: 256MB

# 조건 n은 20보다 작거나 같은 자연수 또는 0이다.

# 입력 n 받기
n = int(input())

# dp테이블 생성
dp = [0] * (n + 1)
if n > 0:
    dp[1] = 1

# dp 계산
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]

# 출력
print(dp[n])

# comment
# X