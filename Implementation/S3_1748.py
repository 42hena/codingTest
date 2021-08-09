#S3 1748 수 이어 쓰기

N = int(input())
val = 9         #뭉탱이 초기값
cnt = 1         #길이
ans = 0         #정답을 담을 공간
#1: 9, 2: 90, 3: 900, 4: 9000 ... 이므로 

while True:
    #길이가 1, 2, 3...인 갯수를 계속 빼고 난 후 값이 0보다 큰 경우
    if N - val * pow(10, cnt - 1) > 0:
        N -= val * pow(10, cnt - 1)
        ans += val * pow(10, cnt - 1) * cnt
    #남은 값과 각각의 길이를 곱하기
    else:
        ans += N * cnt
        break
    # print(f"N={N}, ans={ans}, cnt={cnt}")
    cnt += 1
print(ans)    


#시간 초과
# count = 0
# # 1~9는 1개 10~99는 2개 100~999는 3개
# for i in range(1, N + 1):
#     count += len(str(i))
# print(count)