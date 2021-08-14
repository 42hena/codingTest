# S5 15489 (파스칼의 삼각형)

# 시간 제한: 1초
# 메모리 제한: 512MB

# 조건 (단, 2 ≤ R+W ≤ 30, 2 ≤ C+W ≤ 30, 1 ≤ W ≤ 29, C ≤ R)

# R, C, W입력
R, C, W = map(int, input().split())

# dp테이블 생성
dp = [[0] * (31) for _ in range(31)]


for i in range(1, 31):
    # i + 1이어야 j가 i까지 이므로 갯수가 같다
    for j in range(i + 1):
        # i + 1번째의 행의 처음과 끝은 1로 초기화
        if j == 1 or j == i:
            dp[i][j] = 1
        # 나머지는 i번째의 행의 같은 열과 j - 1의 열을 더함
        else:
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

# 정답을 가르킬 변수
ans =0

for i in range(0, W):
    for j in range(i + 1):
        ans += dp[i + R][j + C]
print(ans)

# comment
# 범위를 설정할경우 i, j를 1,1로 두고 설정후 R만큼 C만큼 더해주는 게 좋아보인다.

#for i in range(R, R + W):
#     for j in range(C, C + W):
#         ans += dp[i][j]
# 이렇게 하면 계산하기 힘들다.