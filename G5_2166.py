#G5 2166 다각형의 면적
#신발끈의 공식을 알아야했다...
N = int(input())

arr = []
for i in range(N):
    arr.append(list(map(int,input().split())))
sum1 = 0
sum2 = 0
print(len(arr))
for i in range(N):
    sum1 += arr[i][0] * arr[(i + 1)%N][1]
    sum2 += arr[i][1] * arr[(i + 1)%N][0]
print(round(abs(sum1-sum2)/2,1))
