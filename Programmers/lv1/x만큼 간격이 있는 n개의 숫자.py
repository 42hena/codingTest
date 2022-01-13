def solution(x, n):
    print([0] * 0)
    if x > 0:
        answer = [i for i in range(x, x*n + 1, x)]
    elif x < 0:
        answer = [i for i in range(x, x*n - 1, x)]
    else:
        answer = [0] * n
    return answer