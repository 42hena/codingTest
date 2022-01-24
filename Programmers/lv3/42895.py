# N으로 표현
def solution(N, number):
    answer = 0
    val = N

    dp = [[]  for i in range(9)]
    if (number == N):
        return 1
    
    dp[1].append(N)
    for leng in range(2, 9):
        val = val * 10 + N
        dp[leng].append(val)
        for i in range(1, leng // 2 + 1):
            for l in dp[i]:
                for r in dp[leng - i]:
                    dp[leng] = check(l, r, dp[leng])
                    if number in dp[leng]:
                        return leng
    answer = -1
    return answer

def check(a,b,r):
    t = [a+b,a*b,a-b,b-a,a//b,b//a]
    for y in t:
        if y not in r and y <= 32000 and y >= 1:
            r.append(y)
    return r