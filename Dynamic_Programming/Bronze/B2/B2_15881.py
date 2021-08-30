# B2 15881 (Pen Pineapple Apple Pen)

# 시간 제한: 1초
# 메모리 제한: 32MB

# 조건 n은 1 <= n <= 1000000

# n 입력
n = int(input())

# 문자열 입력
string = input()

# dp 초기화
dp = [0] * n

# 0번째 dp 초기화
if string[0] == 'p':
    dp[0] = 1
else:
    dp[0] = 0

# dp 계산
for i in range(1, n):
    if dp[i - 1] != 0 and dp[i - 1] != 4:
        if string[i - 1] == 'p' and string[i] == 'P':
            dp[i] = dp[i - 1] + 1
        elif string[i - 1] == 'P' and string[i] == 'A':
            dp[i] = dp[i - 1] + 1
        elif string[i - 1] == 'A' and string[i] == 'p':
            dp[i] = dp[i - 1] + 1
        elif string[i] == 'p':
            dp[i] = 1
    else:
        if string[i] == 'p':
            dp[i] = 1
        else:
            dp[i] = 0

# 갯수 변수 선언
cnt = 0

# 갯수 세기
for i in dp:
    if i == 4:
        cnt += 1

# 출력
print(cnt)