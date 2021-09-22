#S4 1978 소수찾기
N = int(input())

arr = list(map(int,input().split()))

pcnt = 0
for i in range(N):
    cnt = 0
    for j in range(1, arr[i] + 1):
        if (arr[i]%j == 0):
            cnt += 1
    if (cnt == 2):
        pcnt += 1
print(pcnt)