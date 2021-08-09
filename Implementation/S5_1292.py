#S5 1292 쉽게 푸는 문제
from math import sqrt

#A, B 입력 받기
A, B = map(int, input().split())
# print(A, B)

# cnt_sum은 배열 갯수 arr 빈 배열
cnt_sum = 0
arr = []


i = 1
while True:
    #갯수 만큼 배열에 넣기 ex 2면 2를 2번 넣음
    for j in range(i):
        arr.append(i)
    cnt_sum += i

    #넘으면 깨짐
    if cnt_sum > B:
        break
    i += 1
# print(arr)
ans = 0
for i in range(A - 1, B):
    ans += arr[i]
print(ans)