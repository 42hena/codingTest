# S1 19947 (투자의 귀재 배주형)

# 시간 제한: 1초
# 메모리 제한: 512MB

# 조건 10,000 ≤ H ≤ 100,000, H는 정수, 0 ≤ Y ≤ 10, Y는 정수
# 1년마다 5%의 이율을 얻는 투자 (A)
# 3년마다 20%의 이율을 얻는 투자 (B)
# 5년마다 35%의 이율을 얻는 투자 (C)

# H, Y입력
H, Y = map(int, input().split())

# DP테이블 생성(Y는 최대 10)


# A, B, C 년도와 이자율
year = [1, 3, 5]
rate = [1.05, 1.2, 1.35]

dp = [0] * 11
dp[0] = H

for j in range(1, Y + 1):
    for i in range(3):
        # 지정된 연도보다 j값이 같거나 크다면 실행가능
        if year[i] <= j:
            dp[j] = max(dp[j], dp[j - year[i]] * rate[i])
        dp[j] = int(dp[j])
    # print(dp)
# 원하는 연도 출력
print(dp[Y])



# 얘는 틀림 왜일까?
# dp1 = [0] * 11
# dp1[0] = H

# for i in range(3):
#     for j in range(year[i], Y + 1):
#         if year[i] <= j:
#             dp1[j] = max(dp1[j], dp1[j - year[i]] * rate[i])
#         dp1[j] = int(dp1[j])
#     # print(dp)
# print(dp1)
# print(dp == dp1)

# comment
# int강제로 인해 조금 달라지는 거 같은데 정확히는 모르겠다.
# 잘못 생각하면 S5급이 아닌듯