# 정수 N이 입력되면 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는 모든 경우의 수를 구하는 프로그램을 작성하세요.
# 예를 들어 1을 입력했을 때 다음은 3이 하나라도 포함되어 있으므로 세어야 하는 시각입니다.
# - 00시 00분 03초
# - 00시 13분 30초
# 반면에 다음은 3이 하나도 포함되지 않으므로 세면 안 되는 시각입니다.
# - 00시 02분 55초
# - 01시 27분 45초

#86400초 86400경우 확인 완전 탐색(brute forcing)

h = int(input())

count = 0 
for i in range(h + 1):
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                count += 1
print(count)

#내 코드
# cnt = 0
# for h in range(24):
#     for m in range(60):
#         for s in range(60):
#             if h % 10 == 3:
#                 print("%2d:%2d:%2d" %(h,m,s))
#                 cnt += 1
#             elif m % 10 == 3 or m // 10 == 3:
#                 print("%2d:%2d:%2d" %(h,m,s))
#                 cnt += 1
#             elif s % 10 == 3 or s // 10 == 3:
#                 print("%2d:%2d:%2d" %(h,m,s))
#                 cnt += 1
# print(cnt)