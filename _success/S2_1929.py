#S2 1929 소수 구하기
import math
import time

M, N = map(int, input().split())
# start = time.time()
#print(M, N)

arr = [False for _ in range(1000001)]

for i in range(2, N + 1):
    for j in range(2*i, N + 1, i):
        if arr[j] == True:
            continue
        arr[j] = True

if M == 1:
    M = 2
for i in range(M, N + 1):
    if (arr[i] == False):
        print(i)
# print(time.time() - start)


#두 번째 시도 160초
# if M == 1:
#     M = 2
# for i in range(M, N + 1):
#     if (i != 2 and i %2 ==0):
#         continue
#     cnt = 0
#     for j in range(1, int(math.sqrt(i)) + 1):
#         #print(j)
#         if (i % j == 0):
#             cnt += 1
#     if (cnt == 1):
#         print(i)        
# print(time.time() - start)


#첫 번째 시도
# for i in range(M, N + 1):
#     cnt = 0
#     for j in range(1, i + 1):
#         if (i % j == 0):
#             cnt += 1
#     if (cnt == 2):
#         print(i)
# print(time.time() - start)
#시간초과