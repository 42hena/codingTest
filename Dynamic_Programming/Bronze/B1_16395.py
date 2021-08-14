# B1 16395 (파스칼의 삼각형) 나중에 index 맞춰서 해보기

# 시간 제한: 1초
# 메모리 제한: 256MB

# 조건 1 ≤ k ≤ n ≤ 30
# N번째 행에는 N개의 수가 있다.
# 첫 번째 행은 1이다.
# 두 번째 행부터, 각 행의 양 끝의 값은 1이고, 나머지 수의 값은 바로 위 행의 인접한 두 수의 합이다.

# n, k입력
n, k = map(int, input().split())

# dp테이블 생성
dp = [[0] * n for _ in range(n)]


for i in range(n):
    # i + 1이어야 j가 i까지 이므로 갯수가 같다
    for j in range(i + 1):
        # i + 1번째의 행의 처음과 끝은 1로 초기화
        if j == 0 or j == i:
            dp[i][j] = 1
        # 나머지는 i번째의 행의 같은 열과 j - 1의 열을 더함
        else:
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]

# 출력
print(dp[n - 1][k - 1])

# comment
# 인덱스를 맞추지 않을 경우 햇갈리지 않게 조심해야함